#include <stdio.h>
#include "utils.h"

// Assignment 5.1 - Function that applies a mask on prefix and stores
// the result in str_prefix - Don't forget to modify the Makefile to compile it
// My Answer:
void  apply_mask(char *prefix, char mask, char *str_prefix)
{
  //prefix - is a pointer to a string that represents an IP address
  //str_prefix - is a pointer to a char array of size 16 bytes
  //mask - is any value [0-32]
  //The function must fill the str_prefix array with output
  while(str_prefix)
  {
    printf("%c ", ++*str_prefix);
  }
  //The function must apply the mask on prefix and store the result in str_prefix
  //i.e.: prefix = 122.1.1.1 -> mask(24) -> str_prefix stores 122.1.1.0
}
// Instructor Example:

// A brodcast MAC address is a 6-byte MAC address with all the bits set to 1:
// FF:FF:FF:FF:FF:FF
// Write an API in utils.c/utils.h which will fill the 6-byte array passed as an argument
// with MAC Broadcast Address.
// My Answer:
void layer2_fill_with_brodcast_mac(char *mac_array)
{
  
}
