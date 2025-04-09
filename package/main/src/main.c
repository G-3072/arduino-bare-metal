#include <util/delay.h>
// #include <avr/io.h>
#include <gpio.h>

#define TCCR1B (*(uint8_t *) 0x81)
#define TCNT1 (*(uint16_t *) 0x84)

void main(void){

    GPIO_setPinMode(GPIOB, 5, OUTPUT);

    while(1){
        
        GPIO_togglePin(GPIOB, 5);
        _delay_ms(250);
    }

}

