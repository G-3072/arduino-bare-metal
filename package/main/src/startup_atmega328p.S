.section .vectors, "ax"         ; "ax" = a: section is allocatable x: contains executable code

.global __vectors               ; declare vector table as global label

__vectors:                      ; vector table
    .org 0x00                   ; set starting point of vector table at address 0x00 (as per refernce manual)
    rjmp Reset_Handler          ; Reset vector 
    rjmp INT0_handler
    rjmp INT1_handler
    rjmp PCINT0_handler
    rjmp PCINT1_handler
    rjmp PCINT2_handler
    rjmp WDT_handler
    rjmp TIM2_COMPA_handler
    rjmp TIM2_COMPB_handler
    rjmp TIM2_OVF_handler
    rjmp TIM1_CAPT_handler
    rjmp TIM1_COMPA_handler
    rjmp TIM1_COMPB_handler
    rjmp TIM1_OVF_handler
    rjmp TIM0_COMPA_handler
    rjmp TIM0_COMPB_handler
    rjmp TIM0_OVF_handler
    rjmp SPI_STC_handler
    rjmp USART_RX_handler
    rjmp USART_UDRE_handler
    rjmp USART_TX_handler
    rjmp ADC_handler
    rjmp EE_READY_handler
    rjmp AN_COMP_handler
    rjmp TWI_handler
    rjmp SPM_READY_handler

.section .interrupt_handlers, "ax"        ; "ax" = a: section is allocatable x: contains executable code

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

    ldi r16, lo8(0x08FF)     ; load low byte of 0x8FF  (end of SRAM address) into register 16
    ldi r17, hi8(0x08FF)     ; load high byte of 0x8FF  (end of SRAM address) into register 17
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
    cpc r27, r29
    brlo ZeroBssInnerLoop       ; jump to inner loop if Carry flag is set (if X < Y)

    rjmp enableInterrupts       ; if X >= Y jump to next block

    ZeroBssInnerLoop:
    st X+, r16                  ; store value of r16 (0) in RAM and increment address (X reg)

    rjmp ZeroBssLoop           ; jump back to start of loop

    enableInterrupts:
    sei                         ; set global interrupt bit in SREG
    
    ; clearSREG:                  ; clear the status register flags (bc seen in avr std startup code)
    ; .equ SREG, 0x3F             ; gove address 0x3F name SREG
    ; ldi r16, 0x00               
    ; out SREG, r16               ; load r16 (0) int SREG

    callMain:
    rcall main                  ; call main function
    
    infiniteLoop:               ; infinite loop to catch program should it return from main
    rjmp infiniteLoop

.global interrupts
interrupts:
    .word Reset_Handler
    .rept 25
    .word default_handler
    .endr

save_registers:
    push	r1
    push	r0
    in	r0, 0x3f
    push	r0
    eor	r1, r1
    push	r18
    push	r19
    push	r20
    push	r21
    push	r22
    push	r23
    push	r24
    push	r25
    push	r26
    push	r27
    push	r30
    push	r31
    ret

restore_registers:
    pop	r31
    pop	r30
    pop	r27
    pop	r26
    pop	r25
    pop	r24
    pop	r23
    pop	r22
    pop	r21
    pop	r20
    pop	r19
    pop	r18
    pop	r0
    out	0x3f, r0
    pop	r0
    pop	r1
    ret

.global default_handler, Reset_Handler
.weak default_handler, Reset_Handler

default_handler:
    reti            ;do anothing and return


;-------------------------------------- interrupt standard functions --------------------------------------------------

.global INT0_handler, INT1_handler, PCINT0_handler, PCINT1_handler, PCINT2_handler
.weak INT0_handler, INT1_handler, PCINT0_handler, PCINT1_handler, PCINT2_handler

INT0_handler:
    rcall save_registers
    ldi	r30, lo8(interrupts)
    ldi	r31, hi8(interrupts)
    adiw r30, 0x2
    ld r24, Z+
    ld r25, Z
    movw r30, r24
    icall
    rcall restore_registers
    reti
INT1_handler:
    rcall save_registers
    ldi	r30, lo8(interrupts)
    ldi	r31, hi8(interrupts)
    adiw r30, 0x4
    ld r24, Z+
    ld r25, Z
    movw r30, r24
    icall
    rcall restore_registers
    reti
PCINT0_handler:
    rcall save_registers
    ldi	r30, lo8(interrupts)
    ldi	r31, hi8(interrupts)
    adiw r30, 0x6
    ld r24, Z+
    ld r25, Z
    movw r30, r24
    icall
    rcall restore_registers
    reti
PCINT1_handler:
    rcall save_registers
    ldi	r30, lo8(interrupts)
    ldi	r31, hi8(interrupts)
    adiw r30, 0x8
    ld r24, Z+
    ld r25, Z
    movw r30, r24
    icall
    rcall restore_registers
    reti
PCINT2_handler:
    rcall save_registers
    ldi	r30, lo8(interrupts)
    ldi	r31, hi8(interrupts)
    adiw r30, 0xA
    ld r24, Z+
    ld r25, Z
    movw r30, r24
    icall
    rcall restore_registers
    reti

.global WDT_handler
.weak WDT_handler
WDT_handler:
    rcall save_registers
    ldi	r30, lo8(interrupts)
    ldi	r31, hi8(interrupts)
    adiw r30, 0xC
    ld r24, Z+
    ld r25, Z
    movw r30, r24
    icall
    rcall restore_registers
    reti

.global TIM2_COMPA_handler, TIM2_COMPB_handler, TIM2_OVF_handler
.weak TIM2_COMPA_handler, TIM2_COMPB_handler, TIM2_OVF_handler
TIM2_COMPA_handler:
    rcall save_registers
    ldi	r30, lo8(interrupts)
    ldi	r31, hi8(interrupts)
    adiw r30, 0xE
    ld r24, Z+
    ld r25, Z
    movw r30, r24
    icall
    rcall restore_registers
    reti
TIM2_COMPB_handler:
    rcall save_registers
    ldi	r30, lo8(interrupts)
    ldi	r31, hi8(interrupts)
    adiw r30, 0x10
    ld r24, Z+
    ld r25, Z
    movw r30, r24
    icall
    rcall restore_registers
    reti
TIM2_OVF_handler:
    rcall save_registers
    ldi	r30, lo8(interrupts)
    ldi	r31, hi8(interrupts)
    adiw r30, 0x12
    ld r24, Z+
    ld r25, Z
    movw r30, r24
    icall
    rcall restore_registers
    reti

.global TIM1_CAPT_handler, TIM1_COMPA_handler, TIM1_COMPB_handler, TIM1_OVF_handler
.weak TIM1_CAPT_handler, TIM1_COMPA_handler, TIM1_COMPB_handler, TIM1_OVF_handler
TIM1_CAPT_handler:
    rcall save_registers
    ldi	r30, lo8(interrupts)
    ldi	r31, hi8(interrupts)
    adiw r30, 0x14
    ld r24, Z+
    ld r25, Z
    movw r30, r24
    icall
    rcall restore_registers
    reti
TIM1_COMPA_handler:
    rcall save_registers
    ldi	r30, lo8(interrupts)
    ldi	r31, hi8(interrupts)
    adiw r30, 0x16
    ld r24, Z+
    ld r25, Z
    movw r30, r24
    icall
    rcall restore_registers
    reti
TIM1_COMPB_handler:
    rcall save_registers
    ldi	r30, lo8(interrupts)
    ldi	r31, hi8(interrupts)
    adiw r30, 0x18
    ld r24, Z+
    ld r25, Z
    movw r30, r24
    icall
    rcall restore_registers
    reti
TIM1_OVF_handler:
    rcall save_registers
    ldi	r30, lo8(interrupts)
    ldi	r31, hi8(interrupts)
    adiw r30, 0x1A
    ld r24, Z+
    ld r25, Z
    movw r30, r24
    icall

    rcall restore_registers
    reti

.global TIM0_COMPA_handler, TIM0_COMPB_handler, TIM0_OVF_handler
.weak TIM0_COMPA_handler, TIM0_COMPB_handler, TIM0_OVF_handler
TIM0_COMPA_handler:
    rcall save_registers
    ldi	r30, lo8(interrupts)
    ldi	r31, hi8(interrupts)
    adiw r30, 0x1C
    ld r24, Z+
    ld r25, Z
    movw r30, r24
    icall
    rcall restore_registers
    reti
TIM0_COMPB_handler:
    rcall save_registers
    ldi	r30, lo8(interrupts)
    ldi	r31, hi8(interrupts)
    adiw r30, 0x1E
    ld r24, Z+
    ld r25, Z
    movw r30, r24
    icall
    rcall restore_registers
    reti
TIM0_OVF_handler:
    rcall save_registers
    ldi	r30, lo8(interrupts)
    ldi	r31, hi8(interrupts)
    adiw r30, 0x20
    ld r24, Z+
    ld r25, Z
    movw r30, r24
    icall
    rcall restore_registers
    reti

.global SPI_STC_handler
.weak SPI_STC_handler
SPI_STC_handler:
    rcall save_registers
    ldi	r30, lo8(interrupts)
    ldi	r31, hi8(interrupts)
    adiw r30, 0x22
    ld r24, Z+
    ld r25, Z
    movw r30, r24
    icall
    rcall restore_registers
    reti

.global USART_RX_handler, USART_TX_handler, USART_UDRE_handler
.weak USART_RX_handler, USART_TX_handler, USART_UDRE_handler
USART_RX_handler:
    rcall save_registers
    ldi	r30, lo8(interrupts)
    ldi	r31, hi8(interrupts)
    adiw r30, 0x24
    ld r24, Z+
    ld r25, Z
    movw r30, r24
    icall
    rcall restore_registers
    reti
USART_TX_handler:
    rcall save_registers
    ldi	r30, lo8(interrupts)
    ldi	r31, hi8(interrupts)
    adiw r30, 0x26
    ld r24, Z+
    ld r25, Z
    movw r30, r24
    icall
    rcall restore_registers
    reti
USART_UDRE_handler:
    rcall save_registers
    ldi	r30, lo8(interrupts)
    ldi	r31, hi8(interrupts)
    adiw r30, 0x28
    ld r24, Z+
    ld r25, Z
    movw r30, r24
    icall
    rcall restore_registers
    reti

.global ADC_handler
.weak ADC_handler
ADC_handler:
    rcall save_registers
    ldi	r30, lo8(interrupts)
    ldi	r31, hi8(interrupts)
    adiw r30, 0x2A
    ld r24, Z+
    ld r25, Z
    movw r30, r24
    icall
    rcall restore_registers
    reti

.global EE_READY_handler
.weak EE_READY_handler
EE_READY_handler:
    rcall save_registers
    ldi	r30, lo8(interrupts)
    ldi	r31, hi8(interrupts)
    adiw r30, 0x2C
    ld r24, Z+
    ld r25, Z
    movw r30, r24
    icall
    rcall restore_registers
    reti

.global AN_COMP_handler
.weak AN_COMP_handler
AN_COMP_handler:
    rcall save_registers
    ldi	r30, lo8(interrupts)
    ldi	r31, hi8(interrupts)
    adiw r30, 0x2E
    ld r24, Z+
    ld r25, Z
    movw r30, r24
    icall
    rcall restore_registers
    reti

.global TWI_handler
.weak TWI_handler
TWI_handler:
    rcall save_registers
    ldi	r30, lo8(interrupts)
    ldi	r31, hi8(interrupts)
    adiw r30, 0x30
    ld r24, Z+
    ld r25, Z
    movw r30, r24
    icall
    rcall restore_registers
    reti

.global SPM_READY_handler
.weak SPM_READY_handler
SPM_READY_handler:
    rcall save_registers
    ldi	r30, lo8(interrupts)
    ldi	r31, hi8(interrupts)
    adiw r30, 0x32
    ld r24, Z+
    ld r25, Z
    movw r30, r24
    icall
    rcall restore_registers
    reti
