## Lab 5 - Brushed DC Motor Control

![](https://github.com/ethanmarkowski/MEMS1049_MechatronicsLabs/blob/master/Lab5_BrushedMotorControl/Lab%205%20-%20Demo.gif)

[embed](https://github.com/ethanmarkowski/MEMS1049_MechatronicsLabs/blob/master/Lab5_BrushedMotorControl/Lab%205%20-%20Schematic.pdf)[\embed]

This lab demonstrates the use of an H-Bridge to control a small, brushed DC motor. Hardware connections are shown in the above schematic that was produced using AutoDesk Eagle.

Control inputs consist of a push-button and a potentiometer that is read using the ATmega328P's analog-to-digital converter. The Forward and Reverse pins of the H-Bridge are connected to digital outputs on the microcontroller and the Enable pin is driven by a PWM output to provide speed control. As the potentiometer is turned from far counter-clockwise to far clockwise, 5 discrete motor states are programmed:

* Reverse - Fast
* Reverse - Slow
* Stopped
* Forward - Slow
* Forward - Variable

During the "Forward - Variable" state, which corresponds to the clockwise 80% - 100% portion of the potentiometer range, the motor speed is varied in a linear fashion based on where the potentiometer is set within that designated range. Additionally, the push button can be pressed at any time to reduce the motor speed by 1 level. For example, "Reverse - Fast" would be reduced to "Reverse - Slow" and "Forward - Slow" would be reduced to "Stopped" An array of 5 LEDs serves as indicator lights to show which control-state the program is currently in.

To better organize the code, I created a class to handle all of the setup and operation of each hardware element. This provides a degree of abstraction, with all the very low-level register manipulation needed to provide hardware control separated out into the class. Meanwhile, Main.cpp instantiates the class and uses the provided class methods to construct the high-level program features.
