## Lab 11 - I2C communication

![](https://github.com/ethanmarkowski/MEMS1049_MechatronicsLabs/blob/master/Lab11_i2c_MCP9808/Lab%2011%20-%20Demo.gif)

This final lab demonstrates the simultaneous use of multiple serial communication protocols with the ATmega328P microcontroller. I2C is used to interface with an MCP9808 Digital Temperature sensor. After reading the ambient temperature, the value read is displayed on a 7-segment LED display, which involves communicating with a MAX7221 LED driver with SPI communication. Timer0 is used to establish a refresh rate of 1 Hz for the system.
