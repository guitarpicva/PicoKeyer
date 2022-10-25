Copyright 2022 GrizzWorks, LLC - All Rights Reserved

Pico Keyer

PicoKeyer is shared in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

Pico Keyer is a simple Morse code keyer project to demonstrate
how to use a GPIO on the RPi Pico microcontroller to key a radio 
or code practice oscillator.  GPIO voltage on High is +3.3V.

The Pico's onboard LED is keyed to demonstrate the keyed letter 
and punctuation and prosigns.  See alphabet.h for the full list 
of implemented characters.  In addition, the GPIO pin 6 is also 
keyed for use with a keying circuit.  The "R" sent at startup 
(Ready) is only sent to the LED.  GPIO 6 is the Pico physical pin 9.

A keying circuit is highly recommended.  A simple transistor switch,
such as a 2N2222A with an appropriate bias resistor connected
between the GPIO pin and the transistor's base is likely all that
would be needed as a switch between ground and the radio's key 
line.  If clicking is encountered in the RF output, the use of 
an opto-isolated transistor may be necessary.  A device such as 
a 4N25 or VO610A may be appropriate.

The keying is treated as one would use a "straight key", meaning
a simple on/off switch (a telegraph key).  Thus the radio settings
should be for using a straight key and key jack wiring as
required by the radio manufacturer.  Typically, the "tip" of the 
radio's key jack would be connected to the Emitter of the transistor 
switch, and the Ground of the radio's key jack would be connected 
to the Collector of the transistor.  So when the GPIO pin turns
the transistor switch to ON, the key line will be grounded and
the radio will be keyed.  The above demonstrates the most common
radio keying implementation in radios or code practice oscillators.
Please ensure that your radio works this way before designing
your switching circuit.

To supply the ASCII characters for the Pico to key, the USB is
used as a serial input device.  Characters are echo'd back on the
port so the user may see what has been typed into the Serial
terminal or UI application.

If an RPi is used as the input computer, one of it's UARTs may
be directly wired into the Pico on pins 1 (TX) and 2 (RX). The
code has commented lines which deal with the setup and use of
a UART instead of the USB.  Please also make the adjustments in
the CMakeLists.txt file as indicated for use of a UART.

Speed of keying is specified by an input command to the USB.
The format "@nn" is used to set the keying speed to "nn" words
per minute based on the formula for WPM using the "PARIS " word
methodology.  

The formula is :  

     T = 1200 / W

where T = time for a single "dot" in milliseconds and W = "PARIS " 
Words per minute.

When the users sends "@12" for example, the keyer will adjust it's
"dot" time to 1200/12 = 100 ms.

Future designs may also include an "iambic" keyer for radios 
which have electronic keyers built into them.  In effect, this 
is a keyer keying a keyer!  But it provides the convenience of 
using a keyboard instead of an iambic key, which for movement 
impaired people may be welcome.