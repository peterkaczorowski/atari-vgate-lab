/*
   Atari video-gate laboratory
     by Piotr D. Kaczorowski

   For PIC18F57Q43 - Curiosity Nano

   Inspired by UGV by MyTek

 */

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>


#define _XTAL_FREQ 64000000UL

#define GPIO_IN        1
#define GPIO_OUT       0

#define GPIO_ANALOG    1
#define GPIO_DIGITAL   0

#define HIGH           1
#define LOW            0

#define ENABLE         1
#define DISABLE        0

#define RISING_EDGE    1
#define FALLING_EDGE   0


void clock_init(void) {
    OSCCON1 = 0x60; // HFINTOSC
    OSCFRQ = 0x08;  // HFFRQ = 0b111 = 64 MHz

    while (!(OSCSTAT & (1 << 7)));  // ? HFINTOSC Ready
}

void interrupt_init(void) {

    // RB1
    TRISBbits.TRISB1 = GPIO_IN;             // Configure RB1 as input
    ANSELBbits.ANSELB1 = GPIO_DIGITAL;      // Set as digital input
    INTCON0bits.INT1EDG = FALLING_EDGE;     // INT1 interrupt on falling edge
    PIR6bits.INT1IF = DISABLE;              // Clear INT1 interrupt flag
    PIE6bits.INT1IE = ENABLE;               // Enable INT1 interrupt
    // IPR6bits.INT1IP = 1;                    // Set high priority for INT1



    // Enable global and peripheral interrupts
    INTCON0bits.GIE = ENABLE;               // Enable global interrupts
    // INTCON0bits.GIEH = ENABLE;  // Global High Priority Interrupt Enable

    // INTCON0bits.IPEN = ENABLE;              // Enable interrupt priorities
    INTCON0bits.IPEN = DISABLE;             // Disable interrupt priorities
}


#define STR(x) #x
#define XSTR(x) STR(x)

#define NOP_DELAY(N)                      \
    __asm(                                \
        "movlw " XSTR(N) "      \n"       \
        "loop_" XSTR(N) ":      \n"       \
        "addlw -1               \n"       \
        "bnz loop_" XSTR(N) "   \n"       \
    )

// CSYNC
void __interrupt(high_priority, irq(INT1), base(8)) INT1_ISR(void) {
    if (PIR6bits.INT1IF) {
        PIR6bits.INT1IF = 0;

        NOP_DELAY(65);
        LATFbits.LATF2 = HIGH;
        NOP_DELAY(246);
        LATFbits.LATF2 = LOW;
    }
}

void main(void) {
    clock_init();
    interrupt_init();

    LATFbits.LATF2 = LOW;
    TRISFbits.TRISF2 = GPIO_OUT;

    for (;;);
}
