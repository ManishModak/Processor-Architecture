#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <pic18f4550.h>

void main(void)
{ 
    int num1 = 0x02 ;
    
    int num2 = 0x13 ;
    
    int res = num1+num2 ;
    
    TRISD = 0;
    PORTD = res ;
    
    return ;
}
