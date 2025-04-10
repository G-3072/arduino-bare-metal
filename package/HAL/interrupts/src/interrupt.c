#include <interrupt.h>
#include <registers.h>
/**
 * @brief
 * 
 * @param function 
 * @param interrupt 
 */
void interruptAttach(FuncPtr function, uint8_t interrupt){
    interrupts[interrupt] = function;
}
/**
 * @brief 
 * 
 */
void enableGlobalInterrupts(){
    SREG |= (1<<7);
}
/**
 * @brief 
 * 
 */
void disableGlobalInterrupts(){
    SREG &= ~(1<<7);
}
/**
 * @brief 
 * 
 * @param interrupt 
 * @param enable 
 */
void enableInterrupt(uint8_t interrupt){
    switch (interrupt) {
        case 0:
            EIMSK |= (1<<0);
            break;
        case 1:
            EIMSK |= (1<<1);
            break;
        case 2:
            PCICR |= (1<<0);
            break;
        case 3:
            PCICR |= (1<<1); // PCINT1
            break;
        case 4:
            PCICR |= (1<<2); // PCINT2
            break;
        case 5:
            WDTCSR |= (1<<6);
            break;
        case 6:
            TIMSK2 |= (1<<1);
            break;
        case 7:
            TIMSK2 |= (1<<2);
            break;
        case 8:
            TIMSK2 |= (1<<0);
            break;
            case 9:
            TIMSK1 |= (1<<5); // TIM1_CAPT
            break;
        case 10:
            TIMSK1 |= (1<<1);
            break;
        case 11:
            TIMSK1 |= (1<<2);
            break;
        case 12:
            TIMSK1 |= (1<<0);
            break;
        case 13:
            TIMSK0 |= (1<<1);
            break;
        case 14:
            TIMSK0 |= (1<<2);
            break;
        case 15:
            TIMSK0 |= (1<<0);
            break;
        case 16:
            SPCR |= (1<<7);
            break;
        case 17:
            UCSR0B |= (1<<7);
            break;
        case 18:
            UCSR0B |= (1<<5);
            break;
        case 19:
            UCSR0B |= (1<<6);
            break;
        case 20:
            ADCSRA |= (1<<3);
            break;
        case 21:
            EECR |= (1<<3);
            break;
        case 22:
            ACSR |= (1<<3);
            break;
        case 23:
            TWCR |= (1<<0);
            break;
        case 24:
            SPMCSR |= (1<<7);
            break;
        default:
            break;
    }
    
}

void disableInterrupt(uint8_t interrupt){
    switch (interrupt) {
        case 0:
            EIMSK &= ~(1<<0);
            break;
        case 1:
            EIMSK &= ~(1<<1);
            break;
        case 2:
            PCICR &= ~(1<<0);
            break;
        case 3:
            PCICR &= ~(1<<1); // PCINT1
            break;
        case 4:
            PCICR &= ~(1<<2); // PCINT2
            break;
        case 5:
            WDTCSR &= ~(1<<6);
            break;
        case 6:
            TIMSK2 &= ~(1<<1);
            break;
        case 7:
            TIMSK2 &= ~(1<<2);
            break;
        case 8:
            TIMSK2 &= ~(1<<0);
            break;
        case 9:
            TIMSK1 &= ~(1<<5); // TIM1_CAPT
            break;
        case 10:
            TIMSK1 &= ~(1<<1);
            break;
        case 11:
            TIMSK1 &= ~(1<<2);
            break;
        case 12:
            TIMSK1 &= ~(1<<0);
            break;
        case 13:
            TIMSK0 &= ~(1<<1);
            break;
        case 14:
            TIMSK0 &= ~(1<<2);
            break;
        case 15:
            TIMSK0 &= ~(1<<0);
            break;
        case 16:
            SPCR &= ~(1<<7);
            break;
        case 17:
            UCSR0B &= ~(1<<7);
            break;
        case 18:
            UCSR0B &= ~(1<<5);
            break;
        case 19:
            UCSR0B &= ~(1<<6);
            break;
        case 20:
            ADCSRA &= ~(1<<3);
            break;
        case 21:
            EECR &= ~(1<<3);
            break;
        case 22:
            ACSR &= ~(1<<3);
            break;
        case 23:
            TWCR &= ~(1<<0);
            break;
        case 24:
            SPMCSR &= ~(1<<7);
            break;
        default:
            break;
    }
}
