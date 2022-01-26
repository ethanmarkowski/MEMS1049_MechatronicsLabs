## Lab 7 - Stepper Motor Control

![](https://github.com/ethanmarkowski/MEMS1049_MechatronicsLabs/blob/master/Lab7_StepperMotorControl/Lab%207%20-%20Demo.gif)

![](https://github.com/ethanmarkowski/MEMS1049_MechatronicsLabs/blob/master/Lab7_StepperMotorControl/Lab%207%20-%20Schematic.png)

This lab demonstrates the use of an H-Bridge to control a small stepper motor. Hardware connections are shown in the above schematic that was produced using AutoDesk Eagle.

Control input consist of a single push-button. When the button is pressed, the motor rotates 180 degrees clockwise in 5 seconds. Then, the motor pauses for 1 second before rotating 360 degrees counter-clockwise in 5 seconds.

If the button is pressed while the motor is in motion, an alternative motor routine is activated that rotates the motor back and forth 45 degrees 3 times in 3 seconds before continuing the main motion routine.

Additionally, there are 2 indicator LEDs that are used to signal the clockwise vs counter-clockwise direction of the motor while it is in motion.
