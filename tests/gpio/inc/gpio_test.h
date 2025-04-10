#ifndef GPIO_TESTS_H
#define GPIO_TESTS_H

#include <gpio.h>

void test_gpio_writePin_time();     //passed
void test_gpio_togglePin_time();    //passed
void test_gpio_readPin_time();      //passed

void test_gpio_writePort_time();    //passed
void test_gpio_readPort_time();     //passed

void test_gpio_readPin_value();     //passed
void test_gpio_readPort_value();    //passed

void test_gpio_writePin_value();    //passed
void test_gpio_togglePin_value();   //passed
void test_gpio_writePort_value();   //passed


#endif