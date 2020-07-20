
/* ----------------------------------------------------------------------- */
/* Single Seven segment display program */
/* Pin abcdefgDec is connected to port C */
/* Port D is connected to switch tranisitor that controls common pin of sevensegment */

#include <pic16f877a.h>
#include <stdint.h> 

/* ----------------------------------------------------------------------- */
/* Configuration bits: adapt to your setup and needs */
typedef unsigned int word;
word __at 0x2007 CONFIG = _HS_OSC &_WDT_OFF & _PWRTE_OFF & _LVP_ON & _CPD_OFF & _WRT_OFF & _CP_OFF; //Important USE LVP_ON and HS_OSC for PIC16F877A

#define s1 RD0   //PortD 0 pin for switching common.
#define s2 RD1
#define s3 RD2
#define s4 RD3 
 


// Uncalibrated delay, just waits a number of for-loop iterations
void delay(uint16_t iterations)
{
	uint16_t i;
	for (i = 0; i < iterations; i++) {
		// Prevent this loop from being optimized away.
		__asm nop __endasm;
	}
}


void main(void) 
{
  unsigned char binary_pattern[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
  unsigned int a,b,c,d;
  unsigned int counter = 0;

   TRISD=0x00;
   TRISC=0x00;
   PORTC=0x00;
   s1=1;
   s2=1;
   s3=1;
   s4=1;

    while(1)
    {
      
           a = counter / 1000;   // holds 1000's digit
           b = ((counter/100)%10); // holds 100's digit
           c = ((counter/10)%10);  // holds 10th digit
           d = (counter%10);  // holds unit digit value
	   

PORTC=binary_pattern[a];
s1=1;
delay(1000);s1=0;
PORTC=binary_pattern[b];s2=1;  // send 100's place data to 3rd digit
delay(1000);s2=0;
PORTC=binary_pattern[c];s3=1;  // send 10th place data to 2nd digit
delay(1000);s3=0;
PORTC=binary_pattern[d];s4=1;  // send unit place data to 1st digit
delay(1000);s4=0;

if(counter>=1000) //wait till flag reaches 100
{
    counter=0; //only if flag is hundred "i" will be incremented 
}
counter++; //increment flag for each flas
  }
 return ;
   
}