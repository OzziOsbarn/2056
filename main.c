#include<stdio.h>
#include<iostream>

#define REG0_ADDR 0x20000000
#define REG0 *((volatile unsigned long *) (REG0_ADDR))

void set_bit(int bit_num) {
  *((volatile unsigned long *)(REG0_ADDR + 0x2000000 + bit_num*4)) = 1;
}

void reset_bit(int bit_num) {
  *((volatile unsigned long *)(REG0_ADDR + 0x2000000 + bit_num*4)) = 0;
}

struct {
	char flag_a : 1; 
        char flag_b : 1;
        char flag_c : 1; 
        char flag_d : 1;
        char flag_e : 1; 
        char flag_f : 1;
        char flag_g : 1; 
        char flag_h : 1;
} bit_field; // 8 bits


static char bait = 0;


int main()
{
  // Bit Field
  bit_field.flag_a = 1; 
  bit_field.flag_a = 0; 
  bit_field.flag_c = 1;
  bit_field.flag_c = 0; 
  bit_field.flag_e = 1; 
  bit_field.flag_a = 1;
  bit_field.flag_a = 0; 
  bit_field.flag_e = 0;
  // Bit Banding
  set_bit(0); 
  reset_bit(0); 
  set_bit(1); 
  reset_bit(1); 
  set_bit(12); 
  // Handwork with bits
  bait |= (1<<2); 
  bait |= (1<<3); 
  bait &=~(1<<2); 
  bait &=~(1<<3); 
  bait ^= (1<<0); 
  
  system("pause");
  return 0;
}