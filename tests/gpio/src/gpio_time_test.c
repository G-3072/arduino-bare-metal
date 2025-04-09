#include <gpio_time_test.h>
#include <util/delay.h>

void test_setup(){
    TCCR1B |= (1<<1);       //set prescaler to 8 so timer inc / 500ns
    GPIO_setPinMode(GPIOB, 5, OUTPUT);
    TCNT1 = 0;
}
/**
 * @brief 
 * 
 */
void test_gpio_write_time(){

    uint16_t time, start, end = 0;
    test_setup();
    
    start = TCNT1;
    GPIO_writePin(GPIOB, 5, 1);
    end = TCNT1;

    time = (end - start) * 0.5F;   //time in us

    while(1){
        if (time < 10){
            GPIO_writePin(GPIOB, 5, 1);     //test passed
        }else{
            GPIO_writePin(GPIOB, 5, 0);     //test failed
        }
    }
}
/**
 * @brief 
 * 
 */
void test_gpio_toggle_time(){
    uint16_t time, start, end = 0;
    test_setup();
    
    start = TCNT1;
    GPIO_togglePin(GPIOB, 5);
    end = TCNT1;

    time = (end - start) * 0.5F;   //time in us

    while(1){
        if (time < 10){
            GPIO_writePin(GPIOB, 5, 1);     //test passed
        }else{
            GPIO_writePin(GPIOB, 5, 0);     //test failed
        }
    }
}
/**
 * @brief 
 * 
 */
void test_gpio_read_time(){
    uint16_t time, start, end = 0;
    uint8_t val = 0;

    TCCR1B |= (1<<1);       //set prescaler to 8 so timer inc / 500ns
    GPIO_setPinMode(GPIOB, 5, INPUT);
    TCNT1 = 0;
    
    start = TCNT1;
    val = GPIO_readPin(GPIOB, 5);
    end = TCNT1;

    time = (end - start) * 0.5F;   //time in us

    while(1){
        if (time < 10){
            GPIO_writePin(GPIOB, 5, 1);     //test passed
        }else{
            GPIO_writePin(GPIOB, 5, 0);     //test failed
        }
    }
}
/**
 * @brief 
 * 
 */
void test_gpio_port_write_time(){
    uint16_t time, start, end = 0;
    
    TCCR1B |= (1<<1);       //set prescaler to 8 so timer inc / 500ns
    GPIO_setPortMode(GPIOB, OUTPUT);
    TCNT1 = 0;

    start = TCNT1;
    GPIO_writePort(GPIOB, 0xFF);
    end = TCNT1;

    time = (end - start) * 0.5F;   //time in us

    while(1){
        if (time < 10){
            GPIO_writePin(GPIOB, 5, 1);     //test passed
        }else{
            GPIO_writePin(GPIOB, 5, 0);     //test failed
        }
    }
}
/**
 * @brief 
 * 
 */
void test_gpio_port_read_time(){
    uint16_t time, start, end = 0;
    uint8_t val = 0;

    TCCR1B |= (1<<1);       //set prescaler to 8 so timer inc / 500ns
    GPIO_setPortMode(GPIOB, INPUT);
    TCNT1 = 0;
    
    start = TCNT1;
    val = GPIO_readPort(GPIOB);
    end = TCNT1;

    time = (end - start) * 0.5F;   //time in us

    while(1){
        if (time < 10){
            GPIO_writePin(GPIOB, 5, 1);     //test passed
        }else{
            GPIO_writePin(GPIOB, 5, 0);     //test failed
        }
    }
}
