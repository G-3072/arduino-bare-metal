#include <util/delay.h>
// #include <avr/io.h>
#include <gpio.h>

#define TCCR1B (*(uint8_t *) 0x81)
#define TCNT1 (*(uint16_t *) 0x84)

void main(void){

    TCCR1B |= (1<<0);

    uint16_t start, end = 0;

    GPIO_setPinMode(&PB5, OUTPUT);

    TCNT1 = 0;
    start = TCNT1;
    GPIO_togglePin(&PB5);
    end = TCNT1;

    uint16_t time = (end - start) * 62.5F;

    while(1){
        
        if (time == 3562){
            GPIO_writePin(&PB5, 1);
        }else{
            GPIO_writePin(&PB5, 0);

        }

    }

}

