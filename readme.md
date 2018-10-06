# PID

The aim of this library is to emulate the PID controller. It's an Arduino compatible 
library.

## The library

In order to use this library, check out in the following table the different methods 
available and their description.

| Methods | description |
|:--------:|:------------:|
|`PID(float kp, float ki, float kd)` | Consctuctor - This do the first initialization of the PDI gain
|`void PID::setPoint(float reference)` | set the desired output of the plant
|`void setKp(float kp)` | set the kp gain of the controller
|`void setKi(float ki)` | set the ki gain of the controller
|`void setKd(float kd)` | set the kd gain of the controller
|`float getKp()` | get the kp gain of the controller
|`float getKi()` | get the ki gain of the controller
|`float getKd()` | get the kd gain of the controller


