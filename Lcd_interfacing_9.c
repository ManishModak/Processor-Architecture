#include <pic18f4550.h>
#include<xc.h>

#define LCD_EN LATAbits.LA1
#define LCD_RS LATAbits.LA0
#define LCDPORT LATB


void lcd_delay(unsigned int time)
{
 unsigned int i , j ;

    for(i = 0; i < time; i++)
    {
            for(j=0;j<100;j++);
    }
}


void SendInstruction(unsigned char command)
{
     LCD_RS = 0; // RS low : Instruction
     LCDPORT = command;
     LCD_EN = 1; // EN High
     lcd_delay(10);
     LCD_EN = 0; // EN Low; command sampled at EN falling edge
     lcd_delay(10);
}

void SendData(unsigned char lcddata)
{
     LCD_RS = 1; // RS HIGH : DATA
     LCDPORT = lcddata;
     LCD_EN = 1; // EN High
     lcd_delay(10);
     LCD_EN = 0; // EN Low; data sampled at EN falling edge
     lcd_delay(10);
}

void InitLCD(void)
{
    ADCON1 = 0x0F;
    TRISB = 0x00; //set data port as output
    TRISAbits.RA0 = 0; //RS pin
    TRISAbits.RA1 = 0; // EN pin

    SendInstruction(0x38);      //8 bit mode, 2 line,5x7 dots
    SendInstruction(0x06); // entry mode
    SendInstruction(0x0C); //Display ON cursor OFF
    SendInstruction(0x01);      //Clear display
    SendInstruction(0x80);      //set address to 1st line
   
}
/********************************************************************************************************************/

unsigned char *String1 = " ashish";
unsigned char *String2 = " PIC-18F Board";

void main(void)
{
    ADCON1 = 0x0F;
    TRISB = 0x00;       //set data port as output
    TRISAbits.RA0 = 0;  //RS pin
    TRISAbits.RA1 = 0;  // EN pin

    SendInstruction(0x38);      //8 bit mode, 2 line,5x7 dots
    SendInstruction(0x06);      // entry mode
    SendInstruction(0x0C);      //Display ON cursor OFF
    SendInstruction(0x01);      //Clear display
    SendInstruction(0x80);      //set address to 1st line

 while(*String1)
 {
  SendData(*String1);
  String1++;
 }

 SendInstruction(0xC0);      //set address to 2nd line
 while(*String2)
 {
  SendData(*String2);
  String2++;
 }

 while(1);
 
 
}














#include <pic18f4550.h> // header files for pic18
#include<stdio.h>   // standard input output
#include<xc.h>

#define LCD_EN LATAbits.LA1 // latch A - bit one
#define LCD_RS LATAbits.LA0 // latch A - bit two
#define LCDPORT LATB



void Delay(unsigned int time)
{
 unsigned int i,j ;

    for(i=0 ; i<time; i++)
    {
            for(j=0;j<100;j++);
    }
}

void Instruction(unsigned char inst)  // function for instruction
{
     LCD_RS = 0; // RS low : Instruction
     LCDPORT = inst;
     LCD_EN = 1; // EN High
     Delay(10);
     LCD_EN = 0; // EN Low; command sampled at EN falling edge
     Delay(10);
}

void Data(unsigned char data)  // function for data
{
     LCD_RS = 1; // RS HIGH : DATA
     LCDPORT = data;
     LCD_EN = 1; // EN High
     Delay(10);
     LCD_EN = 0; // EN Low; data sampled at EN falling edge
     Delay(10);
}

void LCD(void)
{
    ADCON1 = 0x0F;
    TRISB = 0x00; //set data port B as output
    TRISAbits.RA0 = 0; //RS pin
    TRISAbits.RA1 = 0; // EN pin

    Instruction(0x38);      //8 bit mode, 2 line,5x7 dots
    Instruction(0x06); // entry mode
    Instruction(0x0C); //Display ON cursor OFF mode
    Instruction(0x01);      //Clear display
    Instruction(0x80);      //set address to 1st line for the display screen
   
}

unsigned char *String1 = "Dhruv";
unsigned char *String2 = "Gidwani";

void main(void)
{
    ADCON1 = 0x0F;
    TRISB = 0x00;       //set data port as output
    TRISAbits.RA0 = 0;  //RS pin, bit 0 of port A
    TRISAbits.RA1 = 0;  // EN pin, bit 1 of port 1

    Instruction(0x38);      //8 bit mode, 2 line,5x7 dots
    Instruction(0x06);      // entry mode
    Instruction(0x0C);      //Display ON cursor OFF
    Instruction(0x01);      //Clear display
    Instruction(0x80);      //set address to 1st line


    while(*String1)
 {
  Data(*String1);
  String1++;
 }

 Instruction(0xC0);      //set address to 2nd line
 
 while(*String2)
 {
  Data(*String2);
  String2++;
 }

 while(1);
 
}
