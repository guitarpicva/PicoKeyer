/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */
#include <stdio.h>
#include <cstring>
#include <cstdlib>
#include "pico/stdlib.h"
//#include "hardware/uart.h"
#include "hardware/gpio.h"
#include <queue>
#include "alphabet.h"

// Carriage Return is the send trigger via UART
#define CR 13u
// // the data will reside on UART 0 at phys. pins 1 (TX) and 2 (RX)
// #define DATA uart0
// // physical pin 1 on the Pico
// #define UART_DATA_TX_PIN 0u
// // physical pin 2 on the Pico
// #define UART_DATA_RX_PIN 1u
// // modem baud rate is fixed at 57600 baud for Nino's modem
//#define DATA_BAUD 9600u
// keyer GPIO pin
// change KEYER to a GPIO pin number to use as a 
// radio/oscillator keyer
#define KEYER 6u // physical pin 9 on the Pico
// to test the code, we just use the on-board Pico LED
const uint LED = PICO_DEFAULT_LED_PIN;
// Morse standard timings, we'll set dit to determine the speed
uint dit = 80u; // dit length ms

bool b_fullcmd = false; // we have gathered a full command from the USB
bool b_keyit = true; // true send OTA, false, only flash LED
std::queue<char> tokey; // input byte queue from the DATA UART
char inbyte, keychar, kc;
int j = 0; // string loop counter

void loop() {        
    // here is where we continually read the serial port
    // for ascii to convert to Morse and manage the GPIO
    // pin to key the radio.  The Carriage Return is the
    // line terminator, so we build a vector of chars
    // and then send each one to the KEYER GPIO when the user
    // sends the Carriage Return
    // while(uart_is_readable(DATA)) {
    //   // read the byte, store it and look out for CR (0x0D)
    //   inbyte = uart_getc(DATA);
    //   printf("%c", inbyte); // debug echo so we can see exactly what was sent from UART
    //   if(inbyte == CR) {
    //     b_fullcmd = true; // we got the frame end ok
    //     //printf("\r\nQUEUE: %d", tokey.size());
    //   }
    //   else { // add to the queue
    //     tokey.emplace(inbyte); // in place push with no copying        
    //   }      
    // }
    // we read the stdin from the USB port to get speed command
    // or text to send.  once a CR is reached, perform the speed
    // change or key the characters
    while(true) {
      int in = getchar_timeout_us(100);
      if(in != PICO_ERROR_TIMEOUT) {        
        inbyte = (in & 0xFF); // ensure only one byte from the int is in play
        printf("%c", inbyte); // echo the byte for the user
        if(inbyte == CR) {
          b_fullcmd = true; // we found an input line marker (CR)
          break;
        }
        else { // otherwise add this character to the work queue
          tokey.emplace(inbyte);
        }
      }
    }
    if(b_fullcmd == true) { // should be a fully formed sentence to key
      //printf("Full Cmd\r\n");
      // here we process the full command from the UART
      // and key the transmitter via GPIO KEYER
      b_keyit = true; // send this data over the air
      const int end = tokey.size(); // so when we pop this doesn't change
      for(uint i = 0; i < end; i++) {        
        keychar = tokey.front();
        if(keychar == '@') {
          // this is a speed command so take the rest of the digits the WPM speed
          tokey.pop(); // pop the @
          int paris = atoi(&tokey.front());  // represents 0x00 terminated string pointer
          if(paris < 5) paris = 5;
          printf("\r\n%02d %d ms", paris, 1200/paris);
          dit = (int) 1200/paris;
          b_keyit = false; // only flash the LED
          continue;
        } 
        tokey.pop(); // remove last used item                
        char * keystr = alphabet[keychar]; // look up the keying pattern by ASCII char value       
        if(keystr == "") {
          sleep_ms(dit * 3);
          continue; // skip the unknown char
        }
        if(keystr == " ") {
          printf(" ");
          sleep_ms(dit * 6); // inter-word space = 7, so 1 dit time from end of word + 6 * dit times
          continue;
        }
        // one string of dits and dahs makes ONE character          
        printf("%s", &keychar);
        j = 0; // index in keystr
        kc = keystr[j]; // DIT or DAH
        while (kc != 0x00) { 
          if(b_keyit) gpio_put(KEYER, 1); // key on
          gpio_put(LED, 1);
          if(kc == '.') {
            sleep_ms(dit); // a DIT length
          }
          else {
            sleep_ms(dit * 3); // DAH is 3 dit lengths
          }
          if(b_keyit) gpio_put(KEYER, 0); // key off
          gpio_put(LED, 0);
          sleep_ms(dit); // intra-key delay
          j++;
          kc = keystr[j];
        }
        sleep_ms(dit * 3); // wait 3 dit lengths between characters        
      }      
    }   
    b_fullcmd = false;
}

int main() {
    stdio_init_all();
    sleep_ms(1000); // give it a sec to catch up before printf's begin
    
    // // Set up the DATA UART interface
    // uart_init(DATA, DATA_BAUD);
    // // turn off RTS/CTS flow control
    // uart_set_hw_flow(DATA, false, false); // defaults not specified 
    // uart_set_format(DATA, 8, 1, UART_PARITY_NONE); // default values
    // uart_set_translate_crlf(DATA, false); // default value
    // uart_set_fifo_enabled(DATA, false); // default value
    // // DATA Physical Pico Pins 1, 2 (GPIO0, GPIO1)
    // gpio_set_function(UART_DATA_TX_PIN, GPIO_FUNC_UART);
    // gpio_set_function(UART_DATA_RX_PIN, GPIO_FUNC_UART);

    // Set up the USB as the stdio interface
    stdio_usb_init();
    // initialize GPIO as the output pin
    gpio_init(KEYER); // sets GPIO function to SIO
    gpio_init(LED);
    // set mode to OUTPUT
    gpio_set_dir(KEYER, GPIO_OUT);
    gpio_set_dir(LED, GPIO_OUT);
    // set pull-ups to avoid float keying
    // and always leave the GPIO pin in low state when finished
    gpio_set_pulls(KEYER, true, true);

    // send the letter "R" on power up
    gpio_put(LED, 1); // one flash at start so set to ON
    sleep_ms(100); // on duration ms
    gpio_put(LED, 0); // set the GPIO to low KEY OFF
    sleep_ms(100); // on duration ms
    gpio_put(LED, 1); // one flash at start so set to ON
    sleep_ms(300); // on duration ms
    gpio_put(LED, 0); // set the GPIO to low KEY OFF
    sleep_ms(100); // on duration ms
    gpio_put(LED, 1); // one flash at start so set to ON
    sleep_ms(100); // on duration ms
    gpio_put(LED, 0); // set the GPIO to low KEY OFF

    // Start the main loop    
    while (true) {
        loop();
    }
}


