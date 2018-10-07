# PID

The aim of this library is to emulate the PID controller. It's an Arduino compatible 
library.

## The library

In order to use this library, check out in the following table the different methods 
available and their description.

| Methods | description |
|--------|------------|
|`PID(float kp, float ki, float kd)` | Consctuctor - This do the first initialization of the PDI gain
|`void PID::setPoint(float reference)` | Set the desired output of the plant
|`void setKp(float kp)` | Set the kp gain of the controller
|`void setKi(float ki)` | Set the ki gain of the controller
|`void setKd(float kd)` | Set the kd gain of the controller
|`float getKp()` | Get the kp gain of the controller
|`float getKi()` | Get the ki gain of the controller
|`float getKd()` | Get the kd gain of the controller
|`float getError()` | Get out the current error of the control loop
|`float getAccumulatedError()` | Get out the accumulated error of the control loop since ever
|`void PID::setLimits(float min, float max)` | Set the saturation limits of the controller's output
|`float PID::getOutput(float measured_output = 0)`| Compute the output of the controller
|`void PID::enableClamping(bool enable)`| Enable or disabe clamping


The methods `getError()` and `getAccumulatedError()` could be useful for monitoring 
(like, for plotting error curve) the error evolving and sharpen the choice of PID gains.

## How to use the library

An usage example is provided in the `example` folder.


