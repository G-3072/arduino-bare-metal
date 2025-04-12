#include <interrupt.h>
/**
 * @brief 
 * 
 * @param mode 
 */
void setINT0sense(uint8_t mode){
    switch(mode){
        case LOW:
            EICRA &= ~((1<<0)|(1<<1));
            break;
        case CHANGE:
            EICRA &= ~(1<<1);
            EICRA |= (1<<0);
            break;
        case FALLING_EDGE:
            EICRA &= ~(1<<0);
            EICRA |= (1<<1);
            break;
        case RISING_EDGE:
            EICRA |= ((1<<0)|(1<<1));
            break;
    }
}
/**
 * @brief 
 * 
 * @param mode 
 */
void setINT1sense(uint8_t mode){
    switch(mode){
        case LOW:
            EICRA &= ~((1<<2)|(1<<3));
            break;
        case CHANGE:
            EICRA &= ~(1<<3);
            EICRA |= (1<<2);
            break;
        case FALLING_EDGE:
            EICRA &= ~(1<<2);
            EICRA |= (1<<3);
            break;
        case RISING_EDGE:
            EICRA |= ((1<<2)|(1<<3));
            break;
    }
}
/**
 * @brief 
 * 
 * @param interrupt 
 * @param enable 
 */
void enableInterrupt(uint8_t interrupt){
    switch (interrupt) {
        case INT0:
            EIMSK |= (1<<0);
            break;
        case INT1:
            EIMSK |= (1<<1);
            break;
        case PCINT0:
            PCICR |= (1<<0);
            break;
        case PCINT1:
            PCICR |= (1<<1); // PCINT1
            break;
        case PCINT2:
            PCICR |= (1<<2); // PCINT2
            break;
        case WDT:
            WDTCSR |= (1<<6);
            break;
        case TIM2_COMPA:
            TIMSK2 |= (1<<1);
            break;
        case TIM2_COMPB:
            TIMSK2 |= (1<<2);
            break;
        case TIM2_OVF:
            TIMSK2 |= (1<<0);
            break;
        case TIM1_CAPT:
            TIMSK1 |= (1<<5); // TIM1_CAPT
            break;
        case TIM1_COMPA:
            TIMSK1 |= (1<<1);
            break;
        case TIM1_COMPB:
            TIMSK1 |= (1<<2);
            break;
        case TIM1_OVF:
            TIMSK1 |= (1<<0);
            break;
        case TIM0_COMPA:
            TIMSK0 |= (1<<1);
            break;
        case TIM0_COMPB:
            TIMSK0 |= (1<<2);
            break;
        case TIM0_OVF:
            TIMSK0 |= (1<<0);
            break;
        case SPI_STC:
            SPCR |= (1<<7);
            break;
        case USART_RX:
            UCSR0B |= (1<<7);
            break;
        case USART_UDRE:
            UCSR0B |= (1<<5);
            break;
        case USART_TX:
            UCSR0B |= (1<<6);
            break;
        case ADCINT:
            ADCSRA |= (1<<3);
            break;
        case EE_READY:
            EECR |= (1<<3);
            break;
        case AN_COMP:
            ACSR |= (1<<3);
            break;
        case TWI:
            TWCR |= (1<<0);
            break;
        case SPM_READY:
            SPMCSR |= (1<<7);
            break;
        default:
            break;
    }
}
/**
 * @brief 
 * 
 * @param interrupt 
 */
void disableInterrupt(uint8_t interrupt){
    switch (interrupt) {
        case INT0:
            EIMSK &= ~(1<<0);
            break;
        case INT1:
            EIMSK &= ~(1<<1);
            break;
        case PCINT0:
            PCICR &= ~(1<<0);
            break;
        case PCINT1:
            PCICR &= ~(1<<1); // PCINT1
            break;
        case PCINT2:
            PCICR &= ~(1<<2); // PCINT2
            break;
        case WDT:
            WDTCSR &= ~(1<<6);
            break;
        case TIM2_COMPA:
            TIMSK2 &= ~(1<<1);
            break;
        case TIM2_COMPB:
            TIMSK2 &= ~(1<<2);
            break;
        case TIM2_OVF:
            TIMSK2 &= ~(1<<0);
            break;
        case TIM1_CAPT:
            TIMSK1 &= ~(1<<5); // TIM1_CAPT
            break;
        case TIM1_COMPA:
            TIMSK1 &= ~(1<<1);
            break;
        case TIM1_COMPB:
            TIMSK1 &= ~(1<<2);
            break;
        case TIM1_OVF:
            TIMSK1 &= ~(1<<0);
            break;
        case TIM0_COMPA:
            TIMSK0 &= ~(1<<1);
            break;
        case TIM0_COMPB:
            TIMSK0 &= ~(1<<2);
            break;
        case TIM0_OVF:
            TIMSK0 &= ~(1<<0);
            break;
        case SPI_STC:
            SPCR &= ~(1<<7);
            break;
        case USART_RX:
            UCSR0B &= ~(1<<7);
            break;
        case USART_UDRE:
            UCSR0B &= ~(1<<5);
            break;
        case USART_TX:
            UCSR0B &= ~(1<<6);
            break;
        case ADCINT:
            ADCSRA &= ~(1<<3);
            break;
        case EE_READY:
            EECR &= ~(1<<3);
            break;
        case AN_COMP:
            ACSR &= ~(1<<3);
            break;
        case TWI:
            TWCR &= ~(1<<0);
            break;
        case SPM_READY:
            SPMCSR &= ~(1<<7);
            break;
        default:
            break;
    }
}