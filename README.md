Pico Keyer

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
such as a 2N3904 with an appropriate bias resitor connected
between the he GPIO and the transistor's base is likely all that
would be needed.  If clicking is encountered in the RF output, 
the use of an opto-isolated transistor may be necessary.  A 
device such as a 4N25 or VO610A may be appropriate.

To supply the ASCII characters for the Pico to key, UART0 is
used as the input device.  Characters are echo'd back on the
UART so the user may see what has been typed into the Serial
terminal or UI application.  This necessitates a UART to RS-232
converter and any associated adapters in order to use USB ports.
These converter modules are commonly and inexpensively available.

If an RPi is used as the input computer, one of it's UARTs may
be used and directly wired into the Pico on pins 1 (TX) and 2 (RX).

Power the pico on pins 1 (VSYS) and 3 (GND) with a well-regulated 
+5V DC.  That same source can supply the V+ for the UART to RS-232
converter module (if used).