.section .vectors, "ax"         ; "ax" = a: section is allocatable x: contains executable code

.global __vectors               ; declare vector table as global label

__vectors:                      ; vector table
    .org 0x00                   ; set starting point of vector table at address 0x00 (as per refernce manual)
    rjmp Reset_Handler          ; Reset vector 
    rjmp INT0_isr
    rjmp INT1_isr
    rjmp PCINT0_isr
    rjmp PCINT1_isr
    rjmp PCINT2_isr
    rjmp WDT_isr
    rjmp TIM2_COMPA_isr
    rjmp TIM2_COMPB_isr
    rjmp TIM2_OVF_isr
    rjmp TIM1_CAPT_isr
    rjmp TIM1_COMPA_isr
    rjmp TIM1_COMPB_isr
    rjmp TIM1_OVF_isr
    rjmp TIM0_OVF_isr
    rjmp TIM0_COMPA_isr
    rjmp TIM0_COMPB_isr
    rjmp SPI_STC_isr
    rjmp USART_RX_isr
    rjmp USART_UDRE_isr
    rjmp USART_TX_isr
    rjmp ADC_isr
    rjmp EE_READY_isr
    rjmp AN_COMP_isr
    rjmp TWI_isr
    rjmp SPM_READY_isr

.section .text, "ax"        ; "ax" = a: section is allocatable x: contains executable code

.word __data_start                ; .data section starting address in RAM (VMA)
.word __data_end                ; .data section ending address in RAM (VMA)
.word __data_load_start               ; .data section starting address in FLASH (LMA)

.word __bss_start                 ; .bss section start address in RAM
.word __bss_end                 ; .bss section end address in RAM

.global main                ; declare main function as global
.weak main                  ; decalre main function as weak so it is overwritten by user

Reset_Handler:
    setStackPointer:
    .equ SPH, 0x3E          ; give address 0x3E (Stack Pointer High byte register) name SPH
    .equ SPL, 0x3D          ; give address 0x3D (Stack Pointer Low byte register) name SPL

    ldi r16, lo8(0x8FF)     ; load low byte of 0x8FF  (end of SRAM address) into register 16
    ldi r17, hi8(0x8FF)     ; load high byte of 0x8FF  (end of SRAM address) into register 17
    out SPL, r16            ; transfer value from r16 to SPL
    out SPH, r17            ; transfer value from r17 to SPL

    copyDataSection:
    ldi r30, lo8(__data_load_start)      ; store data load Memory Address in Z register (FLash address)
    ldi r31, hi8(__data_load_start)

    ldi r26, lo8(__data_start)        ; store data virtual memory address in X register (Ram Address)
    ldi r27, hi8(__data_start)

    ldi r28, lo8(__data_end)        ; store data section end address (RAM)  in Y register
    ldi r29, hi8(__data_end)

    copyDataLoop:
    cp r26, r28                 ; compare low bytes of values -> r26 - r28 -> if r26 < 28 Carry flage set
    cpc r27, r29                ; compare high bytes with carry -> r27 - r29 -> if r27 < r29 + C carry flag is set again
    brlo copyDataInnerLoop      ; if carry flag is set jump to inner loop (if X < Y)

    rjmp zeroBssSection         ; if carry flag wasnt set jump zeroBssSection label

    copyDataInnerLoop:
    lpm r16, Z+                 ; load byte from flash memory into reg16 + increment address (Z register)
    st X+, r16                  ; store byte loaded int r16 in RAM 

    rjmp copyDataLoop           ; jump back to start of loop

    zeroBssSection:             ; zero out the .bss section in Ram
    ldi r26, lo8(__bss_start)         ; store bss start address in X register
    ldi r27, hi8(__bss_start)

    ldi r28, lo8(__bss_end)         ; store bss end address in Y register
    ldi r29, hi8(__bss_end)

    ldi r16, 0x00               ; load 0 int r16

    ZeroBssLoop:

    cp r26, r28                 ; compare high and low bytes (high with carry) 
    cpc r27, r28
    brlo ZeroBssInnerLoop       ; jump to inner loop if Carry flag is set (if X < Y)

    rjmp enableInterrupts       ; if X >= Y jump to next block

    ZeroBssInnerLoop:
    st X+, r16                  ; store value of r16 (0) in RAM and increment address (X reg)

    rjmp copyDataLoop           ; jump back to start of loop

    enableInterrupts:
    sei                         ; set global interrupt bit in SREG
    
    clearSREG:                  ; clear the status register flags (bc seen in avr std startup code)
    .equ SREG, 0x3F             ; gove address 0x3F name SREG
    ldi r16, 0x00               
    out SREG, r16               ; load r16 (0) int SREG

    callMain:
    rcall main                  ; call main function
    
    infiniteLoop:               ; infinite loop to catch program should it return from main
    rjmp infiniteLoop



;-------------------------------------------------------------------------------------------------------------------------
;                                             ISR weak function definitions
;-------------------------------------------------------------------------------------------------------------------------
.global default_handler
.weak default_handler
default_handler:
    
    rjmp default_handler    ; infinite loop to make sure program doesnt do upredictable stuff

.weak INT0_isr
INT0_isr:
    rjmp default_handler

.weak INT1_isr
INT1_isr:
    rjmp default_handler

.weak PCINT0_isr
PCINT0_isr:
    rjmp default_handler

.weak PCINT1_isr
PCINT1_isr:
    rjmp default_handler

.weak PCINT2_isr
PCINT2_isr:
    rjmp default_handler

.weak WDT_isr
WDT_isr:
    rjmp default_handler

.weak TIM2_COMPA_isr
TIM2_COMPA_isr:
    rjmp default_handler

.weak TIM2_COMPB_isr
TIM2_COMPB_isr:
    rjmp default_handler

.weak TIM2_OVF_isr
TIM2_OVF_isr:
    rjmp default_handler

.weak TIM1_CAPT_isr
TIM1_CAPT_isr:
    rjmp default_handler

.weak TIM1_COMPA_isr
TIM1_COMPA_isr:
    rjmp default_handler

.weak TIM1_COMPB_isr
TIM1_COMPB_isr:
    rjmp default_handler

.weak TIM1_OVF_isr
TIM1_OVF_isr:
    rjmp default_handler

.weak TIM0_COMPA_isr
TIM0_COMPA_isr:
    rjmp default_handler

.weak TIM2_COMPB_isr
TIM0_COMPB_isr:
    rjmp default_handler

.weak TIM2_OVF_isr
TIM0_OVF_isr:
    rjmp default_handler

.weak SPI_STC_isr
SPI_STC_isr:
    rjmp default_handler

.weak USART_RX_isr
USART_RX_isr:
    rjmp default_handler

.weak USART_UDRE_isr
USART_UDRE_isr:
    rjmp default_handler

.weak USART_TX_isr
USART_TX_isr:
    rjmp default_handler

.weak ADC_isr
ADC_isr:
    rjmp default_handler

.weak EE_READY_isr
EE_READY_isr:
    rjmp default_handler

.weak AN_COMP_isr
AN_COMP_isr:
    rjmp default_handler

.weak TWI_isr
TWI_isr:
    rjmp default_handler

.weak SPM_READY_isr
SPM_READY_isr:
    rjmp default_handler