/**    
    @autor: AMOUSSOU Z. Kenneth
    @date: 05/10/2018
    @version: 1.0
*/

/**
    @function: PID
    @constructor: true
*/
PID(float kp, float ki, float kd){
    _kp = kp;
    _ki = ki;
    _kd = kd;
    
    _max_output = 0;
    _min_output = 0;
}


/**
    function: setKp
    @summary: set the kp gain of the controller
    @parameter:
        kp: proportional gain
    @return: none
*/
void setKp(float kp){
    _kp = kp;
}

/**
    function: setKi
    @summary: set the kp gain of the controller
    @parameter:
        ki: integral gain
    @return: none
*/
void setKi(float ki){
    _ki = ki;
}

/**
    function: setKd
    @summary: set the kd gain of the controller
    @parameter:
        kd: integral gain
    @return: none
*/
void setKd(float kd){
    _kd = kd;
}
