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
void setInterrupt(uint8_t interrupt, uint8_t enable){
    switch (interrupt){
        case 1:

        break;
        case 2:

        break;
        case 3:

        break;
    }
}