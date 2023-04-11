#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <pic18f4550.h>

void main(void)
{ 
    int data[] = {0x13,0x11,0x44,0x55} ;
    
    int sum = 0;
    
    for(int i = 0 ; i < 4 ; i++)
    {
        sum = sum + data[i] ;
    }
    
    TRISD = 0;
    PORTD = sum ;
    
    return ;
}
