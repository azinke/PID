#include <PID.h>

PID myPID(1, 0.5, 0.05);

/* init variable */
float set_point = 0.0;
float measure = 0.0;
float output = 0.0;

uint8_t val = 0;

/* function prototype */
uint8_t tf(float volt);

void setup(){
    Serial.begin(9600);
    
    myPID.setLimits(0, 255);    // set upper and lower limit of the controller
    
    pinMode(9, OUTPUT);
}

void loop(){

    /* measured output */
    measure = (analogRead(A1) * 5)/1023; // sensor - photoresistor
    
    output = myPID.getOutput(measure);
    //Serial.println(output);
    
    /* update output */
    val = tf(output);
    Serial.println("val: " + String(val));
    analogWrite(9, val);
    
    /* Reference */
    set_point = (analogRead(A0) * 5)/1023; // fixed reference
    myPID.setPoint(set_point);
    
}

uint8_t tf(float volt){
    return (volt * 255)/5;
}
