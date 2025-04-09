#ifndef REGISTERS_H
#define REGISTERS_H

//GPIO registers
#define PINB    (*(uint8_t *)0x23)
#define DDRB    (*(uint8_t *)0x24)
#define PORTB   (*(uint8_t *)0x25)

#define PINC    (*(uint8_t *)0x26)
#define DDRC    (*(uint8_t *)0x27)
#define PORTC   (*(uint8_t *)0x28)

#define PIND    (*(uint8_t *)0x29)
#define DDRD    (*(uint8_t *)0x2A)
#define PORTD   (*(uint8_t *)0x2B)

#define EIFR    (*(uint8_t *)0x3D)
#define EIMSK   (*(uint8_t *)0x3C)

//timer registers
#define TIFR1   (*(uint8_t *)0x36)
#define TIFR2   (*(uint8_t *)0x37)

#define GTCCR   (*(uint8_t *)0x43)

#define TIFR0   (*(uint8_t *)0x35)
#define TCCR0A  (*(uint8_t *)0x44)
#define TCCR0B  (*(uint8_t *)0x45)
#define TCMT0   (*(uint8_t *)0x46)
#define OCR0A   (*(uint8_t *)0x47)
#define OCR0B   (*(uint8_t *)0x48)

//EEPROM registers
#define EECR   (*(uint8_t *)0x3F)
#define EEDR   (*(uint8_t *)0x40)
#define EEARL  (*(uint8_t *)0x41)
#define EEARH  (*(uint8_t *)0x42)

//spi registers
#define SPCR   (*(uint8_t *)0x4C)
#define SPSR   (*(uint8_t *)0x4D)
#define SPDR   (*(uint8_t *)0x4E)

//system registers
#define SMCR    (*(uint8_t *)0x53)
#define MCUSR   (*(uint8_t *)0x54)
#define MCUCR   (*(uint8_t *)0x55)
#define SPMCSR  (*(uint8_t *)0x57)
#define SP      (*(uint16_t *)0x5D)
#define SPL     (*(uint8_t *)0x5D)
#define SPH     (*(uint8_t *)0x5E)
#define SREG    (*(uint8_t *)0x5F)

#define WDTCSR  (*(uint8_t *)0x60)
#define PRR     (*(uint8_t *)0x64)

//clock registers
#define CLKPR   (*(uint8_t *)0x61)
#define OSCAL   (*(uint8_t *)0x66)
#endif