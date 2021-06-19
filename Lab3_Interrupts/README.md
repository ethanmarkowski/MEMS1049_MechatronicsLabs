## Lab 3 - Interrupts

![](https://github.com/ethanmarkowski/MEMS1049_MechatronicsLabs/blob/master/Lab3_Interrupts/Lab%203%20-%20Demo.gif)

This lab is a continuation of lab 2 and uses 4 LEDS connected to PORTD, a 16 MHz quartz crystal oscillator, and 2 buttons connected to PD2 and PD3.

As before, the program uses the quartz crystal and the ATmega328P's 8-bit timing register to cycle up and down through the four LEDs at a frequency of 1 Hz. When the first button pressed, all LEDs are turned off and the program pauses for 2 seconds. Then, the microcontroller sequentially displays numbers from 0 to 15 in binary on the LEDs, counting at a rate of 4 Hz. Once finished, the normal program function resumes.

Pressing the second button triggers a different lighting sequence. This time, all four LEDs are illuminated for two seconds before turning the LEDs off one at a time at a rate of 1 Hz. After all LEDs are turned off, an additional 1 second pause occurs before returning to the normal program function.

*Each button is managed with interrupts, rather than polling, in order to allow each button press to be immediately activated. Additional rules are included to manage whether a particular interrupt service routine should be allowed to loop multiple times or start immediately following the other ISP.*
