#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <pic18f4550.h>

void main(void)
{ 
    int num1 = 0x02 ;
    
    int num2 = 0x13 ;
    
    int res = 0 ;
    
    for(int i = 0 ; i < num2 ; i++)
    {
        if(i<=num2)
        {
            res = res+num1 ;
        }
        else
        {
            break;
        }
    }
    
    TRISD = 0;
    PORTD = res ;
}
