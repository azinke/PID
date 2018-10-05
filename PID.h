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
        
    private:
        /* Attributes */
        float _kp;   // proportional gain
        float _ki;   // integral gain
        float _kd;   // derivative gain
        
        bool is_first_run;
        
        /* methods */
        
};
