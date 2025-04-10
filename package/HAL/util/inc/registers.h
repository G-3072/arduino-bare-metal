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
#define EEICRA  (*(uint8_t *)0x69)

#define PCICR   (*(uint8_t *)0x68)

#define PCMSK0  (*(uint8_t *)0x6B)
#define PCMSK1  (*(uint8_t *)0x6C)
#define PCMSK2  (*(uint8_t *)0x6D)

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

#define TIMSK0   (*(uint8_t *)0x6E)
#define TIMSK1   (*(uint8_t *)0x6F)
#define TIMSK2   (*(uint8_t *)0x70)

#define TCCR1A   (*(uint8_t *)0x80)
#define TCCR1B   (*(uint8_t *)0x81)
#define TCCR1C   (*(uint8_t *)0x82)

#define TCNT1L   (*(uint8_t *)0x84)
#define TCNT1H   (*(uint8_t *)0x85)
#define TCNT1    (*(uint16_t *)0x84)

#define ICR1L    (*(uint8_t *)0x86)
#define ICR1H    (*(uint8_t *)0x87)
#define ICR1     (*(uint16_t *)0x86)

#define OCR1AL   (*(uint8_t *)0x88)
#define OCR1AH   (*(uint8_t *)0x89)
#define OCR1A    (*(uint16_t *)0x88)

#define OCR1BL   (*(uint8_t *)0x8A)
#define OCR1BH   (*(uint8_t *)0x8B)
#define OCR1B    (*(uint16_t *)0x8A)

#define TCCR2A   (*(uint8_t *)0xB0)
#define TCCR2B   (*(uint8_t *)0xB1)
#define TCNT2    (*(uint8_t *)0xB2)
#define OCR2A    (*(uint8_t *)0xB3)
#define OCR2B    (*(uint8_t *)0xB4)

#define ASSR     (*(uint8_t *)0xB5)


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

// ADC registers
#define ADCL   (*(uint8_t *)0x78)
#define ADCH   (*(uint8_t *)0x79)
#define ADC    (*(uint16_t *)0x78)

#define ADCSRA (*(uint8_t *)0x7A)
#define ADCSRB (*(uint8_t *)0x7B)
#define ADMUX  (*(uint8_t *)0x7C)

#define DIDR0   (*(uint8_t *)0x7E)
#define DIDR1   (*(uint8_t *)0x7F)

//TWI registers
#define TWBR    (*(uint8_t *)0xB8)
#define TWSR    (*(uint8_t *)0xB9)
#define TWAR    (*(uint8_t *)0xBA)
#define TWDR    (*(uint8_t *)0xBB)
#define TWCR    (*(uint8_t *)0xBC)
#define TWAMR   (*(uint8_t *)0xBD)

//USART registers
#define UCSR0A    (*(uint8_t *)0xC0)
#define UCSR0A    (*(uint8_t *)0xC1)
#define UCSR0A    (*(uint8_t *)0xC2)

#define UBRR0L    (*(uint8_t *)0xC4)
#define UBRR0H    (*(uint8_t *)0xC5)
#define UBRR0     (*(uint16_t *)0xC4)

#define UDR0    (*(uint8_t *)0xC6)


#endif