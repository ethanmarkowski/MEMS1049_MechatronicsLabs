## Lab 2 - Timing and Delays

![]("Lab 2 - Demo.gif")

This lab demonstrates the use of the ATmega328P microcontroller to execute simple timing control of four LEDs that are connected to pins 0 - 3 of PORTC. This is accomplished using TCNT0, the microcontroller's 8-bit timing register, and a 16 MHz quartz crystal oscillator. A single button is also connected on PD2.

The program cycles up and down through the four LEDs at a frequency of 1 Hz. When the button is pressed, all LEDs are turned off and the program pauses until the button is released. After releasing the button, the program continues to cycle through the LEDs from where it left off at the button press. 

*Since the timed delay that occurs between cycling each LED is coded in a blocking fashion, the button press does not immediately take effect when pressed in between the cycling of the LEDs.*
