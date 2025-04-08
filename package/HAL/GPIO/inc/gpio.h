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

#define PB0 ((GPIO_Pin *) {GPIOB, 0})
#define PB1 ((GPIO_Pin *) {GPIOB, 1})
#define PB2 ((GPIO_Pin) {GPIOB, 2})
#define PB3 ((GPIO_Pin) {GPIOB, 3})
#define PB4 ((GPIO_Pin) {GPIOB, 4})
#define PB5 ((GPIO_Pin) {GPIOB, 5})
#define PB6 ((GPIO_Pin) {GPIOB, 6})
#define PB7 ((GPIO_Pin) {GPIOB, 7})

#define PC0 ((GPIO_Pin) {GPIOC, 0})
#define PC1 ((GPIO_Pin) {GPIOC, 1})
#define PC2 ((GPIO_Pin) {GPIOC, 2})
#define PC3 ((GPIO_Pin) {GPIOC, 3})
#define PC4 ((GPIO_Pin) {GPIOC, 4})
#define PC5 ((GPIO_Pin) {GPIOC, 5})
#define PC6 ((GPIO_Pin) {GPIOC, 6})

#define PD0 ((GPIO_Pin) {GPIOD, 0})
#define PD1 ((GPIO_Pin) {GPIOD, 1})
#define PD2 ((GPIO_Pin) {GPIOD, 2})
#define PD3 ((GPIO_Pin) {GPIOD, 3})
#define PD4 ((GPIO_Pin) {GPIOD, 4})
#define PD5 ((GPIO_Pin) {GPIOD, 5})
#define PD6 ((GPIO_Pin) {GPIOD, 6})
#define PD7 ((GPIO_Pin) {GPIOD, 7})


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