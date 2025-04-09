#include <util/delay.h>
// #include <avr/io.h>
#include <gpio.h>
#include <gpio_time_test.h>


void main(void){

    GPIO_setPinMode(GPIOB, 5, OUTPUT);

    while(1){
        
        GPIO_togglePin(GPIOB, 5);
        _delay_ms(250);
    }

}

