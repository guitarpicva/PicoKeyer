cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)
project(keyer C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()
add_executable(
  keyer keyer.cpp
)

# to use the USB as the stdin/stdout for text and commands
pico_enable_stdio_usb(keyer 1)

# for using UART as serial input instead of USB above
# changes must also be made in the code, and they are 
# also commented out as a guide
# pico_enable_stdio_uart(keyer 1) 

# pull in common dependencies
target_link_libraries(keyer pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(keyer)
