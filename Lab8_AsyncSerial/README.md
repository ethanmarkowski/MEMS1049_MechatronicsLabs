## Lab 8 - Asynchronous Serial Communication

![](https://github.com/ethanmarkowski/MEMS1049_MechatronicsLabs/blob/master/Lab8_AsyncSerial/Lab%208%20-%20Demo.gif)

![](https://github.com/ethanmarkowski/MEMS1049_MechatronicsLabs/blob/master/Lab8_AsyncSerial/Lab%208%20-%20Schematic.png)

This lab demonstrates the use of the USART interface to provide asynchronous serial communication between two ATmega328P microcontrollers. For this demonstration, one microcontroller acts as a transmitter, while the other acts as a receiver.

The transmitting microcontroller ready an analog input from a potentiometer with its A/D converter and transmits the value read to the other controller over the USART. The receiving microcontroller then varies the brightness of an LED using a PWM signal whose duty cycle is scaled to match the received value.
