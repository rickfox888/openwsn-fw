/**
\brief <TODO, 1-2 lines>

<TODO, what to buy>

<TODO, how to connect the TelosB to the buzzer>

<TODO, how to build the binary>

<TODO, what to expect when it runs>
 
\author <TODO, name> <TODO, e-mail>, <TODO date>
*/

#include "msp430f1611.h"
#include "stdint.h"

//#include <msp430.h>

int main(void)
{
  WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
  P2DIR |= 0x08;                            // P2.3 output
  P2SEL |= 0x08;                            // P2.3 option select
  CCTL0 = OUTMOD_4;                         // CCR0 toggle mode
  CCR0 = 100;
  TACTL = TASSEL_1 + MC_3;                  // ACLK, up-downmode

  _BIS_SR(LPM3_bits);                       // Enter LPM3
}
