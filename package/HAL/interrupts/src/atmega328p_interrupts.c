#include <interrupt.h>
#include <registers.h>

#pragma GCC diagnostic ignored "-Wmisspelled-isr"

void default_handler(void){
    return;
};

volatile FuncPtr interrupts[25] = {
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

void __attribute__((signal, section(".interrupt_handlers"))) INT0_handler(void){
    interrupts[0]();
};
void __attribute__((signal, section(".interrupt_handlers"))) INT1_handler(void){
    interrupts[1]();
};
void __attribute__((signal, section(".interrupt_handlers"))) PCINT0_handler(void){
    interrupts[2]();
};
void __attribute__((signal, section(".interrupt_handlers"))) PCINT1_handler(void){
    interrupts[3]();
};
void __attribute__((signal, section(".interrupt_handlers"))) PCINT2_handler(void){
    interrupts[4]();
};
void __attribute__((signal, section(".interrupt_handlers"))) WDT_handler(void){
    interrupts[5]();
};
void __attribute__((signal, section(".interrupt_handlers"))) TIM2_COMPA_handler(void){
    interrupts[6]();
};
void __attribute__((signal, section(".interrupt_handlers"))) TIM2_COMPB_handler(void){
    interrupts[7]();
};
void __attribute__((signal, section(".interrupt_handlers"))) TIM2_OVF_handler(void){
    interrupts[8]();
};
void __attribute__((signal, section(".interrupt_handlers"))) TIM1_CAPT_handler(void){
    interrupts[9]();
};
void __attribute__((signal, section(".interrupt_handlers"))) TIM1_COMPA_handler(void){
    interrupts[10]();
};
void __attribute__((signal, section(".interrupt_handlers"))) TIM1_COMPB_handler(void){
    interrupts[11]();
};
void __attribute__((signal, section(".interrupt_handlers"))) TIM1_OVF_handler(void){
    interrupts[12]();
};
void __attribute__((signal, section(".interrupt_handlers"))) TIM0_COMPA_handler(void){
    interrupts[13]();
};
void __attribute__((signal, section(".interrupt_handlers"))) TIM0_COMPB_handler(void){
    interrupts[14]();
};
void __attribute__((signal, section(".interrupt_handlers"))) TIM0_OVF_handler(void){
    interrupts[15]();
};
void __attribute__((signal, section(".interrupt_handlers"))) SPI_STC_handler(void){
    interrupts[16]();
};
void __attribute__((signal, section(".interrupt_handlers"))) USART_RX_handler(void){
    interrupts[17]();
};
void __attribute__((signal, section(".interrupt_handlers"))) USART_UDRE_handler(void){
    interrupts[18]();
};
void __attribute__((signal, section(".interrupt_handlers"))) USART_TX_handler(void){
    interrupts[19]();
};
void __attribute__((signal, section(".interrupt_handlers"))) ADC_handler(void){
    interrupts[20]();
};
void __attribute__((signal, section(".interrupt_handlers"))) EE_READY_handler(void){
    interrupts[21]();
};
void __attribute__((signal, section(".interrupt_handlers"))) AN_COMP_handler(void){
    interrupts[22]();
};
void __attribute__((signal, section(".interrupt_handlers"))) TWI_handler(void){
    interrupts[23]();
};
void __attribute__((signal, section(".interrupt_handlers"))) SPM_READY_handler(void){
    interrupts[24]();
};


