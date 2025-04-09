#include <util/delay.h>
#include <gpio_test.h>

void test_setup(){
    TCCR1B |= (1<<1);       //set prescaler to 8 so timer inc / 500ns
    GPIO_setPinMode(GPIOB, 5, OUTPUT);
    TCNT1 = 0;
}
/**
 * @brief this function tests if the GPIO_writePin fnction executes in under 10us.
 * if yes then the builtin LED will be on else it will be off
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


/**
 * @brief this is a test function to evaluate if reading pins gets the correct value.
 * this test is done with PB0 as an input w/ internal pullDown. the hardware is just a 4.7k pull up resistor pulling PB0 to 5V.
 * expected return is 1. if correct LED on else LED off.
 * 
 */
void test_gpio_readPin_value(){
    GPIO_setPinMode(GPIOB, 0, INPUT);
    GPIO_setPinMode(GPIOB, 5, OUTPUT);

    GPIO_setPinPull(GPIOB, 0, PullDown);

    uint8_t pinValue = GPIO_readPin(GPIOB, 0);

    while(1){
        if (pinValue == 1){
            GPIO_writePin(GPIOB, 5, 1);
        }else{
            GPIO_writePin(GPIOB, 5, 0);
        }
    }

}
/**
 * @brief this function is to test if the readPort function reads the correct value.
 * this test is done with port D as input port w/ internal PullDown. pins PD0 and PD7 are pulled high with 4.7k resistors.
 * expected return value is 129. which Pins of port D are pulled high doesnt matter just adjust expected value.
 * 
 */
void test_gpio_readPort_value(){
    GPIO_setPortMode(GPIOD, INPUT);
    GPIO_setPinMode(GPIOB, 5, OUTPUT);

    GPIO_setPortPull(GPIOD, PullDown);

    uint8_t portValue = GPIO_readPort(GPIOD);

    while(1){
        if (portValue == 129){
            GPIO_writePin(GPIOB, 5, 1);
        }else{
            GPIO_writePin(GPIOB, 5, 0);
        }
    }
}
/**
 * @brief 
 * 
 */
void test_gpio_writePin_value(){
    GPIO_setPinMode(GPIOB, 5, OUTPUT);

    while(1){
        GPIO_writePin(GPIOB, 5, 1);
        _delay_ms(500);
        GPIO_writePin(GPIOB, 5, 0);
        _delay_ms(500);
    }
}
/**
 * @brief 
 * 
 */
void test_gpio_togglePin_value(){
    GPIO_setPinMode(GPIOB, 5, OUTPUT);

    while(1){
        GPIO_togglePin(GPIOB, 5);
        _delay_ms(250);
    }
}
/**
 * @brief for this test it is best to use a Oscilloscope or Voltmeter. the Value 0xAA(0b10101010) is written to Port B
 * and you would have to measure each pin if the value is correct. exepected = PB7, PB5, PB3, PB1 = 1 & PB6, PB4, PB2, PB0 = 0
 * 
 */
void test_gpio_writePort_value(){
    GPIO_setPortMode(GPIOB, OUTPUT);

    while (1)
    {
        GPIO_writePort(GPIOB, 0xAA);
    }
    
}