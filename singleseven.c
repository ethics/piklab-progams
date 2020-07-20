
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
   TRISD0=0;

   TRISC = 0x00; //define PORTC as a output pin
    while(1)
    {
        //this loop sends all binary patterns to PORTD
        for (int i=0;i<10;i++)
        {
            PORTC = binary_pattern[i];s1=1;
            delay(30000);s1=0;
        }
    }
    return;
}