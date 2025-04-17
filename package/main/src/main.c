#include <gpio.h>
#include <registers.h>
#include <interrupt.h>
#include <usart.h>
#include <util/delay.h>

volatile uint8_t intFlag = 0;

void TIMER1_OVF_ISR(void){
    intFlag = 1;
}

void main(void){
    USART_init();

    while(1){
        USART_send("test\n");
        _delay_ms(500);
    }
}