Copyright 2022 GrizzWorks, LLC - All Rights Reserved

Pico Keyer

PicoKeyer is shared in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

Pico Keyer is a simple Morse code keyer project to demonstrate
how to use a GPIO on the RPi Pico microcontroller to key a radio 
or code practice oscillator.

Currently, the Pico's onboard LED is keyed to demonstrate the
keyed letter and punctuation and prosigns.  See alphabet.h for 
the full list of implemented characters.

If the user changes the KEYER GPIO setting from the onboard
LED to one of the GPIO pins, then that output may be used to 
drive a keying circuit or a key input to a radio directly.

It is left to the user to decide if a keying circuit is necessary
but it is highly recommended.  A simple transistor switch,
such as a 2N2222A with an appropriate bias resistor connected
between the GPIO pin and the transistor's base is likely all that
would be needed as a transistor switch between ground and the
radio's key line.  If clicking is encountered in the RF output, 
the use of an opto-isolated transistor may be necessary.  A 
device such as a 4N25 or VO610A may be appropriate.

The keying is treated as one would use a "straight key", meaning
a simple on/off switch (a telegraph key).  Thus the radio settings
should be for using a straight key and key jack wiring as
required by the radio manufacturer.  The "tip" of the radio's key
jack would be connected to the Emitter of the transistor switch,
and the Ground of the radio's key jack would be connected to the
Collector of the transistor switch.  So when the GPIO pin turns
the transistor switch to ON, the key line will be grounded and
the radio will be keyed.

Future designs may also include an "iambic" keyer for radios 
which have electronic keyers built into them.  In effect, this 
is a keyer keying a keyer!  But it provides the convenience of 
using a keyboard instead of an iambic key, which for movement 
impaired people may be welcome.

To supply the ASCII characters for the Pico to key, UART0 is
used as the input device.  Characters are echo'd back on the
UART so the user may see what has been typed into the Serial
terminal or UI application.  This necessitates a UART to RS-232
converter and any associated adapters in order to use USB ports.
These converter modules are commonly and inexpensively 
(< $1 - $3 US) available.

If an RPi is used as the input computer, one of it's UARTs may
be directly wired into the Pico on pins 1 (TX) and 2 (RX).

Power the pico on pins 39 (VSYS) and 38 (GND) with a well-regulated 
+5V DC.  That same source can supply the V+ for the UART to RS-232
converter module (if used).

Speed of keying is specified by an input command to the Pico UART.
The format "@nn" is used to set the keying speed to "nn" words
per minute based on the formula for WPM using the "PARIS " word
methodology.  The formula is :  T = 1200 / W where
T = time for a single "dot" in milliseconds
W = "PARIS " Words per minute

When the users sends "@12" for example, the keyer will adjust it's
"dot" time to 1200/12 = 100 ms
