## Lab 4 - A/D Conversion

![](https://github.com/ethanmarkowski/MEMS1049_MechatronicsLabs/blob/master/Lab4_AD-Conversion/Lab%204%20-%20Demo.gif)

This lab demonstrates the basics of analog-to-digital conversion. A potentiometer is wired to the microcontroller on PC0 and this input is read by the analog-to-digital converter. Five LEDs are connected in an active-low configuration to PB0 - PB4. 

As the ATmega328P features a 10-bit ADC chip, the output is shared between two 8-bit registers, with the option of writing the readings in a left or right justified manner. For this demonstration, the results are configured to be left justified and only the ADCH register is read. As a result, the lower 2-bits of data are truncated and only the top byte of the analog-to-digital conversion results are used.

The 8-bit ADC results are scaled to a number between 0 and 4 and used to left-shift the number "1" by n number of digits. The complement of this result is then outputed to the PORTB register. As a result, the microcontroller cycles through the LED array, turning on the LED that corresponds to the state of the potentiometer or other analog device being read by the ADC on PC0.
