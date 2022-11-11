Copyright 2022 GrizzWorks, LLC - ALL RIGHTS RESERVED

Pico Keyer Electronics Notes

In order to build a suitable keyer "kit", let us take a look at
what components will be necessary.

1. Small enclosure.  The enclosure would contain the RPi Pico
device, a very small MAX232 UART to Serial converter module, a
switching transistor such as the 2N2222A, a bias resistor for 
the transistor switch, and some wires to connect them all together.

2. The UART to RS-232 converter board can be quite small, on the
order of 3/8" x 5/8" in size.  There are 6 wires which must be 
connected to it.  RX, TX, Vcc and GND on one side and the RX
and TX lines on the other side.

3. Raspberry Pi Pico microcontroller (or equivalent.  Testing
is underway with the Seeed XIAO 2040 board).  Wiring may be
soldered directly to the microcontroller via the header pin
holes along both edges.

4. Connectors:
  a. DB-9 Male (Plug) panel connector for the RS-232 interface.
  b. 2.5mm jack, barrel, or RCA jack (or just a hole!) to supply
  the 3-5V power source for both the Pico and MAX232.  This could 
  be battery(ies) or a DC source from a wall wart or other DC power 
  supply.  4 - 1.5V batteries with the V= fed through a single
  diode should provide approximately 5.3V max to the device, 
  which is withing tolerance for the supply voltage.  The Pico
  should function down to around +2V for a supply, but the
  MAX232 may need at least +3V.  So as the battery(ies) discharge
  there may be intermittent function.  If odd things happen, 
  check the battery level.

  Some may wish to simply lead the power wires out of
  a small hole in the box.  Tying them in a knot inside the
  box helps to keep the wires from being pulled out and from
  straining on the Pico's and MAX232's soldered connections.

  Lastly, if the USB port of the microcontroller is exposed then
  that may also be used to supply power to the devices.  At this
  time, running stdio via the USB port is not suggested.  In some
  cases, strange things happen when the Pico is plugged into a
  Windows machine.  A second "device" is created along with the
  serial port and it causes some issues.  For the sake of 
  portability, use the UART version as written.  Power can be
  taken from pin 39 for V+ and pin 38 for Ground if the
  USB powered option is chosen.

  c. 3.5mm Stereo audio jack.  Wire this to a cable to the radio
  or code practice oscillator for use as a straight key using the 
  code provided here.  If an iambic version of the code is ever 
  offered, it would be wired for an iambic keyer which is part 
  of the radio (built-in keyer).  If the radio uses a 3.5mm key jack, a pre-made
  3.5mm plug to 3.5mm plug cable may be used, which is rather
  convenient.  If the radio uses a 1/4" plug, there are adapters
  available for those as well so a pre-made audio cable may be
  used.
