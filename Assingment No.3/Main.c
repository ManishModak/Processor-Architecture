
#include <xc.h>
#include <stdio.h>
#include <stdlib.h>
#include <pic18f4550.h>

void main(void)
{ 
    int source[] = {50,80,10,25,60} ;
    
    int dest[] = {0,0,0,0} ;
    
    for(int i = 0 ; i<=4 ; i++)
    {
        dest[i]=source[i] ;
    }
    
    TRISD=0 ;
    for(int i = 0 ; i<=4 ; i++)
    {
        PORTD=dest[i] ;
        
        for(int n=0 ; n < 1000 ; n++)
        {
            for(int j=0 ; j<500 ;j++)
            {
                
            }
        }
    }
    
    return ;
}
