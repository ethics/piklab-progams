/* ----------------------------------------------------------------------- */
/* Template source file generated by piklab */
#include <pic16f877a.h>
#include <stdint.h> 

/* ----------------------------------------------------------------------- */
/* Configuration bits: adapt to your setup and needs */
typedef unsigned int word;
word __at 0x2007 CONFIG = _HS_OSC &_WDT_OFF & _PWRTE_OFF & _LVP_ON & _CPD_OFF & _WRT_OFF & _CP_OFF; //Important USE LVP_ON and HS_OSC for PIC16F877A

#define LED_PORT RB0        
#define LED_TRIS TRISB0
#define LED1_PORT RC0      
#define LED1_TRIS TRISC0

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
	LED_TRIS = 0; // Pin as output
	LED_PORT = 0; // LED off
	LED1_TRIS = 0;
	LED1_PORT = 0;
	
	while (1) {
		LED_PORT = 1; // LED On
		LED1_PORT = 1;
		delay(30000); // ~500ms @ 4MHz
		LED_PORT = 0; // LED Off
		LED1_PORT = 0;
		delay(30000); // ~500ms @ 4MHz
	}
}
