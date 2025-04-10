# TESTS

in this document the test results of the different dunctions of the HAL are listed:

## Test parameters:

 - mcu: atmega328p
 - compiler: avr-gcc 5.4.0 for ubuntu
 - programmer: avrdude 
 - compiler optimizations. -Os

## GPIO

### GPIO_writePin time test:

the GPIO_writePin Function was tested for exection time and correct execution. the function has to complete its operation in less than 10us and ouput the correct value on the selected pint to pass.

execution time: passed (/test/gpio/test_gpio.c --> test_gpio_writePin_time())

correct execution: passed  (/test/gpio/test_gpio.c --> test_gpio_writePin_value())

### GPIO_togglePin time test:

the GPIO_togglePin Function was tested for exection time and correct execution. the function has to complete its operation in less than 10us toggle the state of the selected output pin.

execution time: passed (/test/gpio/test_gpio.c --> test_gpio_togglePin_time())

correct execution: passed  (/test/gpio/test_gpio.c --> test_gpio_togglePin_value())

### GPIO_readPin time test:

the GPIO_writePin Function was tested for exection time and correct execution. the function has to complete its operation in less than 10us and read the current value of the selected input pin.

execution time: passed (/test/gpio/test_gpio.c --> test_gpio_readPin_time())

correct execution: passed  (/test/gpio/test_gpio.c --> test_gpio_readPin_value())