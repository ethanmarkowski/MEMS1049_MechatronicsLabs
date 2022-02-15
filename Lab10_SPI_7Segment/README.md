## Lab 8 - SPI and 7-Segment LED Displays

![](https://github.com/ethanmarkowski/MEMS1049_MechatronicsLabs/blob/master/Lab10_SPI_7Segment/Lab%2010%20-%20Demo.gif)

![](https://github.com/ethanmarkowski/MEMS1049_MechatronicsLabs/blob/master/Lab10_SPI_7Segment/Lab%2010%20-%20Schematic.png)

This lab demonstrates the use of SPI communication to control a MAX7221 driver for a 7 segment LED display. The ATmega328P displays the date when this lab's code was written on the display. Timer0 is used to control the tempo of the LED operation, which consists of displaying the numerals of the month and day for 0.5 seconds, each, and then turning the display off for 1 second before repeating the routine.
