#include <util/delay.h>
#include <gpio.h>
#include <registers.h>
#include <interrupt.h>
// #include <gpio_test.h>

void test(void);

void main(void){

    interruptAttach(test, PCINT0);
    GPIO_setPinMode(GPIOB, 5, OUTPUT);
    
    while(1){
        GPIO_togglePin(GPIOB, 5);
        _delay_ms(250);
    }
}

void test(void){

    uint8_t a;
    a += 5;

    return;
}