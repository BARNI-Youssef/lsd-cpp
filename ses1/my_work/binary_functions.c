#include "binary_functions.h"


void check_msb(int num){
    if(num == 0){
        printf("msb is not set\n");
        return;    
    }
    num = num >> 31;
    printf("%d\n", num & 1);
}

void print_bits(unsigned char n){
    unsigned ns;
    for(int i = 1; i < 9; i++){
        ns = n>>(8-i);
        printf("%u", ns);
        n = n<<i;
        n = n>>i;
    }
    printf("\n");
}