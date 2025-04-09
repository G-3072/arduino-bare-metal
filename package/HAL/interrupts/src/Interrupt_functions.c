#ifndef INTERRUPT_FUNCTIONS_H
#define INTERRUPT_FUNCTIONS_H

#include <interrupt.h>

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

#endif