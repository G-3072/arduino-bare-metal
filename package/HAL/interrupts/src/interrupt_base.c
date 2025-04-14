#include <interrupt.h>
#include <registers.h>

#pragma GCC diagnostic ignored "-Wmisspelled-isr"


void INT0_handler(void) __attribute__((signal));
void INT1_handler(void) __attribute__((signal));
void PCINT0_handler(void) __attribute__((signal));
void PCINT1_handler(void) __attribute__((signal));
void PCINT2_handler(void) __attribute__((signal));
void WDT_handler(void) __attribute__((signal));
void TIM2_COMPA_handler(void) __attribute__((signal));
void TIM2_COMPB_handler(void) __attribute__((signal));
void TIM2_OVF_handler(void) __attribute__((signal));
void TIM1_CAPT_handler(void) __attribute__((signal));
void TIM1_COMPA_handler(void) __attribute__((signal));
void TIM1_COMPB_handler(void) __attribute__((signal));
void TIM1_OVF_handler(void) __attribute__((signal));
void TIM0_COMPA_handler(void) __attribute__((signal));
void TIM0_COMPB_handler(void) __attribute__((signal));
void TIM0_OVF_handler(void) __attribute__((signal));
void SPI_STC_handler(void) __attribute__((signal));
void USART_RX_handler(void) __attribute__((signal));
void USART_UDRE_handler(void) __attribute__((signal));
void USART_TX_handler(void) __attribute__((signal));
void ADC_handler(void) __attribute__((signal));
void EE_READY_handler(void) __attribute__((signal));
void AN_COMP_handler(void) __attribute__((signal));
void TWI_handler(void) __attribute__((signal));
void SPM_READY_handler(void) __attribute__((signal));

void default_handler(void){
    return;
};

FuncPtr interrupts[25] = {
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
    default_handler
};

void INT0_handler(void){
    interrupts[0]();
};
void INT1_handler(void){
    interrupts[1]();
};
void PCINT0_handler(void){
    interrupts[2]();
};
void PCINT1_handler(void){
    interrupts[3]();
};
void PCINT2_handler(void){
    interrupts[4]();
};
void WDT_handler(void){
    interrupts[5]();
};
void TIM2_COMPA_handler(void){
    interrupts[6]();
};
void TIM2_COMPB_handler(void){
    interrupts[7]();
};
void TIM2_OVF_handler(void){
    interrupts[8]();
};
void TIM1_CAPT_handler(void){
    interrupts[9]();
};
void TIM1_COMPA_handler(void){
    interrupts[10]();
};
void TIM1_COMPB_handler(void){
    interrupts[11]();
};
void TIM1_OVF_handler(void){
    interrupts[12]();
};
void TIM0_COMPA_handler(void){
    interrupts[13]();
};
void TIM0_COMPB_handler(void){
    interrupts[14]();
};
void TIM0_OVF_handler(void){
    interrupts[15]();
};
void SPI_STC_handler(void){
    interrupts[16]();
};
void USART_RX_handler(void){
    interrupts[17]();
};
void USART_UDRE_handler(void){
    interrupts[18]();
};
void USART_TX_handler(void){
    interrupts[19]();
};
void ADC_handler(void){
    interrupts[20]();
};
void EE_READY_handler(void){
    interrupts[21]();
};
void AN_COMP_handler(void){
    interrupts[22]();
};
void TWI_handler(void){
    interrupts[23]();
};
void SPM_READY_handler(void){
    interrupts[24]();
};


