#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include <stdint.h>
#include <registers.h>


static void INT0_isr();
static void INT1_isr();
static void PCINT0_isr();
static void PCINT1_isr();
static void PCINT2_isr();
static void WDT_isr();
static void TIM2_COMPA_isr();
static void TIM2_COMPB_isr();
static void TIM2_OVF_isr();
static void TIM1_CAPT_isr();
static void TIM1_COMPA_isr();
static void TIM1_COMPB_isr();
static void TIM1_OVF_isr();
static void TIM0_COMPA_isr();
static void TIM0_COMPB_isr();
static void TIM0_OVF_isr();
static void SPI_STC_isr();
static void USART_RX_isr();
static void USART_UDRE_isr();
static void USART_TX_isr();
static void ADC_isr();
static void EE_READY_isr();
static void AN_COMP_isr();
static void TWI_isr();
static void SPM_READY_isr();

typedef void (*FuncPtr)(void);

void interruptAttach(FuncPtr function, uint8_t interrupt);

void enableGlobalInterrupts();
void disableGlobalInterrupts();

void setInterrupt(uint8_t interrupt, uint8_t enable);
    
FuncPtr interrupts[25] = {
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

#endif