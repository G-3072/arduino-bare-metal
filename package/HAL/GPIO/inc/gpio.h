#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>

#define INPUT 0
#define OUTPUT 255

#define PullUp 255
#define PullDown 0

typedef struct
{
    uint8_t PIN;
    uint8_t DDR;
    uint8_t PORT;
}GPIO_Port;

typedef struct{
    GPIO_Port *port;
    uint8_t number;
}GPIO_Pin;

#define GPIOB ((GPIO_Port *)0x23)
#define GPIOC ((GPIO_Port *)0x26)
#define GPIOD ((GPIO_Port *)0x29)

#define PB0 ((GPIO_Pin *))

void GPIO_setPinMode(GPIO_Pin *pin, uint8_t mode);
void GPIO_setPinPull(GPIO_Pin *pin, uint8_t pull);

void GPIO_writePin(GPIO_Pin *pin, uint8_t value);
void GPIO_togglePin(GPIO_Pin *pin);

uint8_t GPIO_readPin(GPIO_Pin *pin);

void GPIO_setPortMode(GPIO_Port *port, uint8_t mode);
void GPIO_setPortPull(GPIO_Port *port, uint8_t pull);

void GPIO_writePort(GPIO_Port *port, uint8_t value);
uint8_t GPIO_readPort(GPIO_Port *port);

#endif