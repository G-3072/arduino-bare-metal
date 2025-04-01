#include <avr/io.h>
#include <util/delay.h>
#include <avr/wdt.h>

void main(void){

    DDRB |= (1 << 5);
    PORTB |= (1<<5);
    _delay_ms(1900);

    while(1){
        PINB |= (1 << 5);

        _delay_ms(200);
    }

}

