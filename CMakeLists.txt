cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)
project(keyer C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()
add_executable(
  keyer keyer.cpp
)

# pull in common dependencies
target_link_libraries(keyer pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(keyer)

#target_link_libraries( modemmqtt pico_stdlib pico_util hardware_i2c hardware_rtc hardware_flash hardware_sync )
