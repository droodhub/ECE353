#include "msp.h"


/**
 * main.c
 */
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	int mode = 0; //signifies what mode(R/G/B/OFF) the light is in
	    //set button1 & button2 to inputs, enable resistors, set resistors to pull-up
	    P1->DIR &= ~BIT1;
	    P1->DIR &= ~BIT4;
	    P1->REN |= BIT1;
	    P1->REN |= BIT4;
	    P1->OUT |= BIT1;
	    P1->OUT |= BIT4;

	    //initialize RGBLED pins as output, initialize LED to OFF
	    P2->DIR |= BIT0;
	    P2->DIR |= BIT1;
	    P2->DIR |= BIT2;

	    P1->DIR |= BIT0;

	    while(1){ //continuous wait for button 1 press
	       while((P1->IN & BIT1) != 0){}; //waiting for button presses in order
	       while((P1->IN & BIT4) != 0){};
	       mode = (mode+1) % 4;

	       switch(mode){
	       case 0:
	           P2->OUT &= ~BIT0;
	           P2->OUT &= ~BIT1;
	           P2->OUT &= ~BIT2;
	           break;
	       case 1:
	           P2->OUT |= BIT0; //only red bit is on
	           break;
	       case 2:
	           P2->OUT &= ~BIT0; //turn red back off
	           P2->OUT |= BIT1;
	           break;
	       case 3:
	           P2->OUT &= ~BIT1;
	           P2->OUT |= BIT2;
	           break;
	       }
	    }
}
