#include <interrupt.h>
#include <registers.h>
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
 * @param function 
 * @param interrupt 
 */
void interruptAttach(FuncPtr function, uint8_t interrupt){
    interrupts[interrupt] = function;
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
void default_handler(){             // default handler that does nothing
    return;
}

/**
 * @brief 
 * 
 */
static FuncPtr interrupts[25] = {   
    default_handler,
    default_handler,
    default_handler,
    default_handler,
    default_handler,
    default_handler,
    default_handler,
    default_handler,
    default_handler,
    default_handler,
    default_handler,
    default_handler,
    default_handler,
    default_handler,
    default_handler,
    default_handler,
    default_handler,
    default_handler,
    default_handler,
    default_handler,
    default_handler,
    default_handler,
    default_handler,
    default_handler,
    default_handler,
};

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

