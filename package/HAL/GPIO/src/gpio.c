#include <gpio.h>

#define MCUCR (*(uint8_t *)0x35)

void GPIO_setPinMode(GPIO_Pin *pin, uint8_t mode){
    if(mode != 0){
        pin->port->DDR |= (1<<pin->number);
    }else{
        pin->port->DDR &= ~(1<<pin->number);
    }
}

void GPIO_setPinPull(GPIO_Pin *pin, uint8_t pull){
    MCUCR &= ~(1<<4);       

    if (pull != 0){
        pin->port->PORT |= (1<<pin->number);
    }else{
        pin->port->PORT &= ~(1<<pin->number);
    }
}

void GPIO_writePin(GPIO_Pin *pin, uint8_t value){
    if (value != 0){
        pin->port->PORT |= (1<<pin->number);
    }else{
        pin->port->PORT &= ~(1<<pin->number);
    }
}

void GPIO_togglePin(GPIO_Pin *pin){
    pin->port->PIN = (1<<pin->number);
}

uint8_t GPIO_readPin(GPIO_Pin *pin){
    uint8_t pinVal = pin->port->PIN;

    pinVal &= (1<<pin->number);
    pinVal >>= pin->number;
    
    return pinVal;
}

void GPIO_setPortMode(GPIO_Port *port, uint8_t mode){
    port->DDR = mode;
}

void GPIO_setPortPull(GPIO_Port *port, uint8_t pull){
    port->PORT = pull;
}

void GPIO_writePort(GPIO_Port *port, uint8_t value){
    port->PORT = value;
}

uint8_t GPIO_readPort(GPIO_Port *port){
    uint8_t portVal = port->PIN;
    
    return portVal;
}