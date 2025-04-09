#ifndef GPIO_TIME_TEST_H
#define GPIO_TIME_TEST_H

#include <gpio.h>

#define TCCR1B (*(uint8_t *) 0x81)
#define TCNT1 (*(uint16_t *) 0x84)

void test_gpio_write_speed();
void test_gpio_toggle_speed();
void test_gpio_read_speed();

void test_gpio_port_write_speed();
void test_gpio_port_read_speed();

void test_gpio_readPin_value();
void test_gpio_readPort_value();

void test_gpio_writePin_value();
void test_gpio_togglePin_value();
void test_gpio_writePort_value();

#endif