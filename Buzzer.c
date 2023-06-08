/*
* File: newmain.c
* Author: Administrator
*
* Created on 5 April, 2022, 9:31 AM
*/

#include <xc.h>
#include<pic18f4550.h>

#define Buzzer LATAbits.LATA5 //define buzzer pin

unsigned int count=0;

void Timer1ISR(){
if(TMR1IF==1){
TMR1L=0x20;
TMR1H=0xD1;
count++;

if(count>=1000){ //measure upto 1000 ms i.e. 1 seconds
Buzzer=~Buzzer; //Toggle buzzer pin


count=0;
}
TMR1IF=0;

}
}
void main(void) {
TRISB=0; //set as output
TRISAbits.TRISA5=0; //set buzzer pin as RA5 as output
GIE=1;
PEIE=1;
TMR1IE=1;
TMR1IF=0;
/*Enable 16 bit TMR1 register,no pre-scaler,internal clock,timer OFF*/
T1CON=0x80;
TMR1L=0x20;
TMR1H=0xD1;
TMR1ON=1;

while(1);

return;
}
