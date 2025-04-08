#include <util/delay.h>
#include <gpio.h>


void main(void){

    GPIO_Pin PB5;
    PB5.number = 5;
    PB5.port = GPIOB;

    GPIO_setPinMode(&PB5, OUTPUT);

    while(1){
        
        GPIO_togglePin(&PB5);

    }

}

