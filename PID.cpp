/**    
    @autor: AMOUSSOU Z. Kenneth
    @date: 05/10/2018
    @version: 1.0
*/

/**
    @function: PID
    @constructor: true
*/
#include <PID.h>

PID::PID(float kp, float ki, float kd){
    _kp = kp;
    _ki = ki;
    _kd = kd;
    
    _max_output = 0.0;
    _min_output = 0.0;
    
    _output = 0;
    _clamping_output = 0;
    
    _error = 0.0;
    _last_error = 0.0;
    _cumulated_error = 0.0;
    
    _is_clamping_enabled = true;
    setLimits(0, 255);     // Default limits based on Arduino µC
}

/**
    function: setPoint
    @summary: set the desired output of the plant
    @parameter: none
    @return: none
*/
void PID::setPoint(float reference){
    _set_point = reference;
}

/**
    function: setKp
    @summary: set the kp gain of the controller
    @parameter:
        kp: proportional gain
    @return: none
*/
void PID::setKp(float kp){
    _kp = kp;
}

/**
    function: setKi
    @summary: set the kp gain of the controller
    @parameter:
        ki: integral gain
    @return: none
*/
void PID::setKi(float ki){
    _ki = ki;
}

/**
    function: setKd
    @summary: set the kd gain of the controller
    @parameter:
        kd: integral gain
    @return: none
*/
void PID::setKd(float kd){
    _kd = kd;
}

/**
    function: getKp
    @summary: get the kp gain of the controller
    @parameter: none
    @return:
        float: proportional gain
*/
float PID::getKp(){
    return _kp;
}

/**
    function: getKi
    @summary: get the ki gain of the controller
    @parameter: none
    @return:
        float: integral gain
*/
float PID::getKi(){
    return _ki;
}

/**
    function: getKd
    @summary: get the kd gain of the controller
    @parameter: none
    @return:
        float: proportional gain
*/
float PID::getKd(){
    return _kd;
}

/**
    function: _proportional
    @summary: compute the proportional part of the error
    @parameter: none
    @return: none
*/
float PID::_proportional(){
    if(_kp == 0) return 0;
    return _error * _kp;
}

/**
    function: setLimits
    @summary: set the saturation limits of the controller
    @parameter:
        min: minimum limit
        max: maximum limit
    @return: none
*/
void PID::setLimits(float min, float max){
    if(min >= max) return;
    _min_output = min;
    _max_output = max;
}

/**
    function: _clamp
    @summary: clamp the output of the controller
    @parameter: none
    @return: 
        float: output of the PID controller
*/
float PID::_clamp(){
    if(_output <= _min_output) { _clamping_output = _min_output; }
    else if(_output >= _max_output) { _clamping_output = _max_output; }
    else { _clamping_output = _output; }
    return _clamping_output;
}


/**
    function: _derivative
    @summary: compute the derivative part of the error
    @parameter: none
    @return: 
        float: the derivative component of the PID controller
*/
float PID::_derivative(){
    if(_kd == 0) return 0;
    static float cumulated_sum = 0;
    float d_output = 0;
    if(_is_filter_enabled){
        d_output = _cut_off_frequency - cumulated_sum;
        cumulated_sum += d_output;
        return _kd * d_output;
    }
    return (_error - _last_error) * _kp; // if filter not enabled
}

/**
    function: enableFilter
    @summary: enable of disable the derivative branch filter
    @parameter: 
        enable: true or false to enable of disable filter
    @return: none
*/
void PID::enableFilter(bool enable){
    _is_filter_enabled = enable;
}

/**
    function: setFilterCutOffFrequency
    @summary: set the cut off frequency of the derivative filter
    @parameter: 
        cut_off: cut off frequency in rad/s
    @return: none
*/
void PID::setFilterCutOffFrequency(unsigned int cut_off){
    _cut_off_frequency = cut_off;
}

/**
    function: _integral
    @summary: compute the integral part of the error
    @parameter: none
    @return: none
*/
float PID::_integral(){
    if(_ki == 0) return 0;
    if( (_output != _clamping_output) && ((_error * _output) > 0) ){ return 0; }
    _cumulated_error += _error;
    #ifdef DEBUG
        Serial.println("cumulated error: " + String(_cumulated_error));
    #endif
    return _ki * _cumulated_error;
}

/**
    function: getOutput
    @summary: compute the output of the controller - the control signal
    @parameter: none
    @return: none
*/
float PID::getOutput(float measured_output = 0){
    _output = 0;
    if(_kp != 0){ _output += _proportional(); }
    if(_ki != 0){ _output += _integral(); }
    if(_kd != 0){ _output += _derivative(); }
    
    _error = _set_point - measured_output;
    #ifdef DEBUG
        Serial.println("error: " + String(_error));
    #endif
    _last_error = _error;   // update last error
    if(_is_clamping_enabled){ return _clamp(); }
    return _output;
}

/**
    function: enableClamping
    @summary: enable or disabe clamping
    @parameter: 
        enable: boolean value to enable or disable clamping
    @return: none
*/
void PID::enableClamping(bool enable){
    _is_clamping_enabled = enable;
}
