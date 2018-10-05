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

class PID{
    public:
        PID(float kp, float ki, float kd);
        
        void setKp();
        void setKi();
        void setKd();
        
        float getOutput();
        
    private:
        /* Attributes */
        float _kp;   // proportional gain
        float _ki;   // integral gain
        float _kd;   // derivative gain
        float _error;
        
        float _output;      // current output
        float _last_output;
        
        float _max_output;   // maximum limit of the output
        float _min_output;   // minimum limit of the output
        
        bool is_first_run;
        
        /* methods */
        float _proportional();
        float _derivative();
        float _integral();
        float _clamp();
};

#endif
