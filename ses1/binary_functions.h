#include <stdio.h>
#include <stdlib.h>
#include<windows.h>

void check_msb(int);            //takes a int and print it most significatn bit (1 in negative, 0 if positive) exeption: 0
void print_bits(unsigned char);  //prints the given unsiged int's binary representation on 32 bits