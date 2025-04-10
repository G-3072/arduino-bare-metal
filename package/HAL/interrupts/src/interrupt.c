#include <interrupt.h>
#include <registers.h>

static FuncPtr interrupts[25] = {
    INT0_isr,
    INT1_isr,
    PCINT0_isr,
    PCINT1_isr,
    PCINT2_isr,
    WDT_isr,
    TIM2_COMPA_isr,
    TIM2_COMPB_isr,
    TIM2_OVF_isr,
    TIM1_CAPT_isr,
    TIM1_COMPA_isr,
    TIM1_COMPB_isr,
    TIM1_OVF_isr,
    TIM0_COMPA_isr,
    TIM0_COMPB_isr,
    TIM0_OVF_isr,
    SPI_STC_isr,
    USART_RX_isr,
    USART_UDRE_isr,
    USART_TX_isr,
    ADC_isr,
    EE_READY_isr,
    AN_COMP_isr,
    TWI_isr,
    SPM_READY_isr
};

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
 * @param port 
 * @param pin 
 */
void enablePinChangeInterrupt(GPIO_Port *port, uint8_t pin){
    if(port == GPIOB){
        PCMSK0 |= (1<<pin);
    }else if(port == GPIOC){
        PCMSK1 |= (1<<pin);
    }else if (port == GPIOD){
        PCMSK2 |= (1<<pin);
    }
}
/**
 * @brief 
 * 
 * @param port 
 * @param pin 
 */
void disablePinChangeInterrupt(GPIO_Port *port, uint8_t pin){
    if(port == GPIOB){
        PCMSK0 &= ~(1<<pin);
    }else if(port == GPIOC){
        PCMSK1 &= ~(1<<pin);
    }else if (port == GPIOD){
        PCMSK2 &= ~(1<<pin);
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

void INT0_isr(){
    interrupts[0]();
}
void INT1_isr(){
    interrupts[1]();
}
void PCINT0_isr(){
    interrupts[2]();
}
void PCINT1_isr(){
    interrupts[3]();
}
void PCINT2_isr(){
    interrupts[4]();
}
void WDT_isr(){
    interrupts[5]();
}
void TIM2_COMPA_isr(){
    interrupts[6]();
}
void TIM2_COMPB_isr(){
    interrupts[7]();
}
void TIM2_OVF_isr(){
    interrupts[8]();
}
void TIM1_CAPT_isr(){
    interrupts[9]();
}
void TIM1_COMPA_isr(){
    interrupts[10]();
}
void TIM1_COMPB_isr(){
    interrupts[11]();
}
void TIM1_OVF_isr(){
    interrupts[12]();
}
void TIM0_COMPA_isr(){
    interrupts[13]();
}
void TIM0_COMPB_isr(){
    interrupts[14]();
}
void TIM0_OVF_isr(){
    interrupts[15]();
}
void SPI_STC_isr(){
    interrupts[16]();
}
void USART_RX_isr(){
    interrupts[17]();
}
void USART_UDRE_isr(){
    interrupts[18]();
}
void USART_TX_isr(){
    interrupts[19]();
}
void ADC_isr(){
    interrupts[20]();
}
void EE_READY_isr(){
    interrupts[21]();
}
void AN_COMP_isr(){
    interrupts[22]();
}
void TWI_isr(){
    interrupts[23]();
}
void SPM_READY_isr(){
    interrupts[24]();
}
