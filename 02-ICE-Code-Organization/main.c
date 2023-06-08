#include "msp.h"
#include "ece353.h"
//#include "ece353.c"

/**
 * main.c
 */
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	int mode = 0;

	ece353_button1_init();
	ece353_button2_init();
	ece353_led1_init();
	ece353_rgb_init();

	while(1){
	    while(!ece353_button1()){};
	    while(!ece353_button2()){};
	    mode = (mode+1) % 4;

	    switch(mode){
	    case 0:
	        ece353_rgb(false, false, false);
	        break;
	    case 1:
	        ece353_rgb(true, false, false);
	        break;
	    case 2:
	        ece353_rgb(false, true, false);
	        break;
	    case 3:
	        ece353_rgb(false, false, true);
	        break;
	    }
	}
}
