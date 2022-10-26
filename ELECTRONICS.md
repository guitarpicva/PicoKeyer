Copyright 2022 GrizzWorks, LLC - ALL RIGHTS RESERVED

Pico Keyer Electronics Notes

In order to build a suitable keyer "kit", let us take a look at
what components will be necessary.

1. Small enclosure.  The enclosure would contain the RPi Pico
device, a very small MAX232 UART to Serial converter module,
and some wires to connect them all together.

2. The UART to RS-232 converter board can be quite small, on the
order of 3/8" x 5/8" in size.  There are 6 wires which must be 
connected to it.  RX, TX, Vcc and GNG on one side and the RX
and TX lines on the other side.

3. Raspberry Pi Pico microcontroller (or equivalent.  Testing
is underway with the Seeed XIAO 2040 board).  Wiring may be
soldered directly to the microcontroller via the header pin
holes along both edges.

4. Connectors:
  a. DB-9 Male (Plug) panel connector for the RS-232 interface.
  b. 3.5mm jack, barrel, or RCA jack (or just a hole!) to supply
  the 3-5V power source for both the Pico and MAX232.  This could 
  be battery(ies) or a DC source from a wall wart or other DC power 
  supply.

  Some ham radio folks may wish to attach power pole type
  connectors instead and simply lead the power wires out of
  a small hole in the box.  Tying them in a knot inside the
  box helps to keep the wires from being pulled out and from
  straining on the Pico's soldered connections.

  Lastly, if the USB port of the microcontroller is exposed then
  that may also be used to supply power to the devices.

  c. 3.5mm Stereo audio jack.  Wire this for use as a straight
  key with the code provided here.  If an iambic version of the
  code is ever offered, it would be wired for an iambic keyer
  which is part of the radio.