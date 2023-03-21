#include<xc.h>
#include<stdlib.h>
#include<pic18f4550.h>

void main(void)
{
    int Data[] = {45,6,13,32,2,50,23} ;
    
    for(int i = 0 ; i < 7 ; i++)
    {
        for(int j = 0 ; j < 7-i ; j++)
        {
            if(Data[j]>Data[j+1])
            {
                int temp = Data[j] ;
                Data[j]= Data[j+1] ;
                Data[j+1]= temp ;
            }
        }
    }
    
    TRISD=0 ;
    for(int i = 0 ; i < 7 ; i++)
    {
        PORTD=Data[i] ;
        for(int j= 0 ; j < 1000 ; j++)
        {
            for(int n = 0 ; n < 100 ; n++)
            {
                
            }
        }
    }
    
    return ;
}
