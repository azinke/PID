/**    
    @autor: AMOUSSOU Z. Kenneth
    @date: 05/10/2018
    @version: 1.0
*/
#ifndef H_PID
#define H_PID

#if ARDUINO < 100
#include <WProgram.h>
#else
#include <Arduino.h>
#endif

#define DEBUG

class PID{
    public:
        PID(float kp, float ki, float kd);
        
        void setKp(float kp);
        void setKi(float ki);
        void setKd(float kd);
        
        float getKp();
        float getKi();
        float getKd();
        
        void setPoint(float reference);    // set the desired output
        void enableClamping(bool enable);
        
        float getOutput(float measured_output);
        void setLimits(float min, float max);
        
        void enableFilter(bool enable);
        void setFilterCutOffFrequency(unsigned int cut_off);    // cut_off in rad/s
        
        
    private:
        /* Attributes */
        
        /* PID Gains */
        float _kp;   // proportional gain
        float _ki;   // integral gain
        float _kd;   // derivative gain
        
        float _set_point;
        
        /* errors */
        float _error;
        float _last_error;
        double _cumulated_error;
        
        float _output;      // current output
        float _clamping_output;
        
        float _max_output;   // maximum limit of the output
        float _min_output;   // minimum limit of the output
        
        /* filter */
        unsigned int _cut_off_frequency;
        
        /* sampling */
        unsigned long _sampling_time;   // in ms
        unsigned long _time;            // in ms
        
        /* status */
        bool _is_clamping_enabled;  // enable or disable clamping
        bool _is_filter_enabled;
        
        /* methods */
        float _proportional();
        float _derivative();
        float _integral();
        float _clamp();
};

#endif
