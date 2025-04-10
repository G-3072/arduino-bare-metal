#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include <stdint.h>
#include <gpio.h>
#include <registers.h>

typedef enum {
    INT0 = 0,
    INT1,
    PCINT0,
    PCINT1,
    PCINT2,
    WDT,
    TIM2_COMPA,
    TIM2_COMPB,
    TIM2_OVF,
    TIM1_CAPT,
    TIM1_COMPA,
    TIM1_COMPB,
    TIM1_OVF,
    TIM0_COMPA,
    TIM0_COMPB,
    TIM0_OVF,
    SPI_STC,
    USART_RX,
    USART_UDRE,
    USART_TX,
    ADCINT,
    EE_READY,
    AN_COMP,
    TWI,
    SPM_READY
} InterruptType;

typedef enum{
    LOW = 0,
    CHANGE,
    FALLING_EDGE,
    RISING_EDGE
} extINTsenseMode;

typedef void (*FuncPtr)(void);

void interruptAttach(FuncPtr function, uint8_t interrupt);

void enableGlobalInterrupts();
void disableGlobalInterrupts();

void enableInterrupt(uint8_t interrupt);
void disableInterrupt(uint8_t interrupt);

void setINT0sense(uint8_t mode);
void setINT1sense(uint8_t mode);
    
void enablePinChangeInterrupt(GPIO_Port *port, uint8_t pin);
void disablePinChangeInterrupt(GPIO_Port *port, uint8_t pin);

#endif