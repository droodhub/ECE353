//Author: Andrew Sabee
#include "ECE353.h"

#define VOLT_0P85 1056      // 0.85 /(3.3/4096)
#define VOLT_2P50 3103      // 2.50 /(3.3/4096)

void ece353_led1_init(void) {
    P1->DIR |= BIT0;
    //turn off LED as default
    P1->OUT &= ~BIT0;
}

void ece353_button1_init(void) {
    P1->DIR &= ~BIT1;
    //enable resistor
    P1->REN |= BIT1;
    //choose pullup
    P1->OUT |= BIT1;
}

void ece353_led1(bool on) {
    //turns on or off LED1 given the boolean parameter
    if (on) {
        P1->OUT |= BIT0;
    } else {
        P1->OUT &= ~BIT0;
    }
}

bool ece353_button1(void) {
    //returns status of button1
    return !(P1->IN & BIT1);
}

void ece353_RGB_LED_Init(void)
{   //set R, G, B as outptuts
    P2->DIR |= BIT0;
    P2->DIR |= BIT1;
    P2->DIR |= BIT2;

    //initialize to be turned off
    P2->OUT &= ~BIT0;
    P2->OUT &= ~BIT1;
    P2->OUT &= ~BIT2;
}


void ece353_RGB_LED(bool red_on, bool green_on, bool blue_on)
{   //turn respective light on if its parameter is true
    if(red_on){
        P2->OUT |= BIT0;
    }else{
        P2->OUT &= ~BIT0;
    }

    if(green_on){
        P2->OUT |= BIT1;
    }else{
        P2->OUT &= ~BIT1;
    }

    if(blue_on){
        P2->OUT |= BIT2;
    }else{
        P2->OUT &= ~BIT2;
    }
}


void ece353_button2_init(void)
{   //set as input
    P1->DIR &= ~BIT4;
    //enable resistor
    P1->REN |= BIT4;
    //choose pullup
    P1->OUT |= BIT4;
}


bool ece353_button2(void)
{
    return !(P1->IN & BIT4);
}

void ece353_T32_1_wait_100mS(void){
    //turn timer off
    TIMER32_1->CONTROL = 0;
    //set to be oneshot, prescale it by 16
    TIMER32_1->CONTROL = TIMER32_CONTROL_ONESHOT | TIMER32_CONTROL_PRESCALE_1;
    //at our clock speed and prescaling, 100mS = 18750 cycles
    TIMER32_1->LOAD = 18750;
    //turn timer on
    TIMER32_1->CONTROL |= TIMER32_CONTROL_ENABLE;

    while(TIMER32_1->VALUE != 0){} //wait
}

void ece353_T32_1_wait(uint32_t time){
    TIMER32_1->CONTROL = 0;
    //32b timer, oneshot mode
    TIMER32_1->CONTROL = TIMER32_CONTROL_ONESHOT | TIMER32_CONTROL_SIZE;
    //wait for the allotted time
    TIMER32_1->LOAD = time;
    //turn timer on
    TIMER32_1->CONTROL |= TIMER32_CONTROL_ENABLE;

    while(TIMER32_1->VALUE != 0){}
}
void ece353_button1_wait_for_press(void){
    //waiting for a button to be held for 5 seconds
    int count = 0;
    while(count < 50){
        ece353_T32_1_wait_100mS();
        if(ece353_button1()){
            count++;
        }
        else
            count = 0;
    }
    return;
}


void ece353_MKII_RGB_IO_Init(bool en_primary_function)
{
    // RED      : P2.6
    // GREEN    : P2.4
    // BLUE     : P5.6
    //set as outputs
    P2->DIR |= BIT6;
    P2->DIR |= BIT4;
    P5->DIR |= BIT6;

    if(en_primary_function)
    {   //only enabled if we want primary function to be on
        P2->SEL1 &= ~BIT6;
        P2->SEL1 &= ~BIT4;
        P5->SEL1 &= ~BIT6;

        P2->SEL0 |= BIT6;
        P2->SEL0 |= BIT4;
        P5->SEL0 |= BIT6;
    }
}


void ece353_MKII_RGB_PWM(
        uint16_t ticks_period,
        uint16_t red_num,
        uint16_t green_num,
        uint16_t blue_num
)
{
    // This code converts the HTML color codes into a
        // number of clock ticks to generate the duty cyle
        uint16_t ticks_red_on = (red_num * ticks_period)/255;
        uint16_t ticks_green_on = (green_num * ticks_period)/255;
        uint16_t ticks_blue_on = (blue_num * ticks_period)/255;

        // Initialze the IO pins
        ece353_MKII_RGB_IO_Init(true);


        // Replace w and y with the correct TimerA number
        // Replace x and z with the correct CCR number.
        // RED      <--> TA0.3
        // GREEN    <--> TA0.1
        // BLUE     <--> TA2.1
        TIMER_A0->CTL = 0;
        TIMER_A2->CTL = 0;

        // Set the period for both TimerA peripherals.
        TIMER_A0->CCR[0] = ticks_period-1;
        TIMER_A2->CCR[0] = ticks_period-1;

        // Configure RED PWM duty cycle
        TIMER_A0->CCR[3] = ticks_red_on;
        // Configure GREEN PWM duty cycle
        TIMER_A0->CCR[1] = ticks_green_on;
        // Configure BLUE PWM duty cycle
        TIMER_A2->CCR[1] = ticks_blue_on;

        // Set the OUT MODE to be mode 7 for each
        // PWM output
        TIMER_A0->CCTL[3] |= TIMER_A_CCTLN_OUTMOD_7;
        TIMER_A0->CCTL[1] |= TIMER_A_CCTLN_OUTMOD_7;
        TIMER_A2->CCTL[1] |= TIMER_A_CCTLN_OUTMOD_7;

        // Turn the first TimerA peripheral
        TIMER_A0->CTL = TIMER_A_CTL_SSEL__SMCLK;
        TIMER_A0->CTL |= TIMER_A_CTL_MC__UP;

        // Turn the second TimerA peripheral
        TIMER_A2->CTL = TIMER_A_CTL_SSEL__SMCLK;
        TIMER_A2->CTL |= TIMER_A_CTL_MC__UP;
    }

void ece353_ADC14_PS2_XY(void)
{
    // Configure the X direction as an analog input pin.
    P6->SEL0 |= BIT0;
    P6->SEL1 |= BIT0;
    // Configure the Y direction as an analog input pin.
    P4->SEL0 |= BIT4;
    P4->SEL1 |= BIT4;
    // Configure CTL0 to sample 16-times in pulsed sample mode.
    // NEW -- Indicate that this is a sequence-of-channels.
    ADC14->CTL0 = ADC14_CTL0_SHT02 | ADC14_CTL0_CONSEQ_1 | ADC14_CTL0_SHP;
    // Configure ADC to return 12-bit values
    ADC14->CTL1 = ADC14_CTL1_RES__12BIT;
    // Associate the X direction analog signal with MEM[0]
    ADC14->MCTL[0] = ADC14_MCTLN_INCH_15;
    // Associate the Y direction analog signal with MEM[1]
    // NEW -- Make sure to indicate this is the end of a sequence.
    ADC14->MCTL[1] = ADC14_MCTLN_INCH_9;
    ADC14->MCTL[1] = ADC14_MCTLN_EOS;
    // Enable interrupts in the ADC AFTER a value is written into MEM[1].
    ADC14->IER0 = ADC14_IER0_IE1;

    // NEW: This is not the same as what is demonstrated in the example
    // coding video.

    // Enable ADC Interrupt in the NVIC
    NVIC_EnableIRQ(ADC14_IRQn);
    // Turn ADC ON
    ADC14->CTL0 |= ADC14_CTL0_ON;
}
void ece353_MKII_RGB_LED(bool red, bool green, bool blue)
{   //control what portions of the RGB LED are turned on
    if(red){
            P2->OUT |= BIT6;
        }else{
            P2->OUT &= ~BIT6;
        }

        if(green){
            P2->OUT |= BIT4;
        }else{
            P2->OUT &= ~BIT4;
        }

        if(blue){
            P5->OUT |= BIT6;
        }else{
            P5->OUT &= ~BIT6;
        }
}

void ece353_T32_1_Interrupt_Ms(uint16_t ms){
    uint32_t ticks = ((SystemCoreClock * ms)/1000) -1;

    TIMER32_1->CONTROL = 0;

    TIMER32_1->LOAD = ticks;

    __enable_irq();
    NVIC_EnableIRQ(T32_INT1_IRQn);
    NVIC_SetPriority(T32_INT1_IRQn, 0);

    TIMER32_1->CONTROL |= TIMER32_CONTROL_ENABLE | TIMER32_CONTROL_MODE
                        | TIMER32_CONTROL_SIZE | TIMER32_CONTROL_IE;

}
void ece353_ADC14_PS2_XY_COMP(void)
{
    // Configure the X direction as an analog input pin.
    P6->SEL0 |= BIT0;
    P6->SEL1 |= BIT0;
    // Configure CTL0 to sample 16-times in pulsed sample mode.
    // Indicate that this is a sequence of samples.
    ADC14->CTL0 = ADC14_CTL0_SHT02 | ADC14_CTL0_SHP | ADC14_CTL0_CONSEQ_1;
    // Configure CTL1 to return 12-bit values
    ADC14->CTL1 = ADC14_CTL1_RES__12BIT;
    // Set up the HI0 Window
    //ADC14->CTL1 &= ~ADC14_CTL1_DF;
    ADC14->HI0 = VOLT_2P50;
    // Set up the LO0 Window
    ADC14->LO0 = VOLT_0P85;
    // Associate the X direction analog signal with MEM[0], indicate the end of sequence,
    // turn on the window comparator
    ADC14->MCTL[0] = ADC14_MCTLN_INCH_15;
    ADC14->MCTL[1] |= ADC14_MCTLN_EOS;
    ADC14->MCTL[0] &= ~ADC14_MCTLN_WINCTH;
    ADC14->MCTL[0] |= ADC14_MCTLN_WINC;
    // Enable interrupts when either the HI or LO thresholds of the window
    // comparator has been exceeded.  Disable all other interrupts
    ADC14->IER1 =  ADC14_IER1_HIIE | ADC14_IER1_LOIE;
    // Enable ADC Interrupt
    NVIC_EnableIRQ(ADC14_IRQn);
    // Turn ADC ON
    ADC14->CTL0 |= ADC14_CTL0_ON;
}

void ece353_MKII_S1_Init(void){
    //set our button's pin to be an input, enable pull up resistors
    P5->DIR &= ~BIT1;
    P5->REN |= BIT1;
    P5->OUT |= BIT1;
}

void ece353_MKII_S2_Init(void){
    //set our button's pin to be an input, enable pull up resistors
    P3->DIR &= ~BIT5;
    P3->REN |= BIT5;
    P3->OUT |= BIT5;

}

bool ece353_MKII_S1(void){
    //returns true if S1 is currently being pressed
    if((P5->IN & BIT1) == 0)
        return true;
    else
        return false;
}

bool ece353_MKII_S2(void){
    //returns true if S2 is currently being pressed
    if((P3->IN & BIT5) == 0)
        return true;
    else
        return false;
}

void ece353_MKII_Buzzer_Init(uint16_t ticks_period)
{   //initialize buzzer as output, set as primary function
    P2->DIR |= BIT7;
    P2->SEL0 |= BIT7;
    P2->SEL1 &= ~BIT7;
    //stop timer
    TIMER_A0->CTL = 0;
    //load timer_A with given period
    TIMER_A0->CCR[0] = ticks_period - 1;
    //we want a 50% duty cycle, so load half of given period into CCR[4] for buzzer
    TIMER_A0->CCR[4] = (ticks_period/2) - 1;
    //set timer to be Reset/Set mode
    TIMER_A0->CCTL[4] = TIMER_A_CCTLN_OUTMOD_7;
    //set timer to run based off of the system clock
    TIMER_A0->CTL = TIMER_A_CTL_SSEL__SMCLK;
}

void ece353_MKII_Buzzer_On(void){
    //clear current mode control
    TIMER_A0->CTL &= ~TIMER_A_CTL_MC_MASK;
    //set mode to up and clear counter
    TIMER_A0->CTL |= TIMER_A_CTL_MC__UP | TIMER_A_CTL_CLR;
}

void ece353_MKII_Buzzer_Off(void){
    TIMER_A0->CTL &= ~TIMER_A_CTL_MC_MASK;
}

bool ece353_MKII_Buzzer_Run_Status(void){
    //returns current status of timer
    if((TIMER_A0->CTL & TIMER_A_CTL_MC_MASK) == TIMER_A_CTL_MC__STOP)
        return false;
    else
        return true;
}


