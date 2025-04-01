; .global __isr_vectors    ; make the vector table a global variable

.global main
.global Reset_Handler


; Linker symbols 
.word __data_start
.word __data_end
.word __data_LMA

.word __bss_start
.word __bss_end

.word __ram_end

.section .isr_vector, "a", @progbits    ; "a" = allocatble -> gets assigned space in final exec, @progbits = 
    .org 0x0000
    rjmp Reset_Handler
    rjmp INT0_isr
    rjmp INT1_isr
    ; add rest of vectors


Reset_Handler:
    ; set SP to 
    ldi SPH, high(__ram_end)    ; load high byte of __ram_end into SPH
    ldi SPL, low(__ram_end)     ; load low byte of __ram_end into SPL

    ; copy data from flash to RAM
    rcall copy_data

    ; clear bss in ram
    rcall clear_bss

    ; call main function
    rcall main


copy_data:
    ldi r30, low(__data_LMA)      ; load data section LMA to Z register
    ldi r31, high(__data_LMA)

    ldi r26, low(__data_start)        ; load data section VMA to X registers
    ldi r27, high(__data_start)

    ldi r1, low(__data_end)        ; load data section end address to Y register
    ldi r2, high(__data_end)

    rcall copyDataLoop
    ret

copyDataLoop:

    lpm r3, Z+          ; load high and low byte from flash into reg4 and reg3
    lpm r4, Z+

    st X+, r3           ; store values loaded into reg3 & 4 from Flash in RAM
    st X+, r4

    cp r1, r26          ; compare high byte of current address with data section end address
    brne copyDataLoop   ; if address bytes are the same continue else go to start  of copyDataLoop

    cp r2, r27          ; compare low byte of current address with data section end address
    brne copyDataLoop   ; if address bytes are the same continue else go to start  of copyDataLoop

    ret                 ; returns only if the current address is the same as data section end address meaning entire section was copied

clear_bss:
    ldi r30, low(__bss_end)      ; load bss section end address to Z register
    ldi r31, high(__bss_end)

    ldi r26, low(__bss_start)        ; load bss section start address to X registers
    ldi r27, high(__bss_start)

    clr r0

    rcall zeroBssLoop
    ret

zeroBssLoop:

    st X+, r0

    cp r27, r31
    brne zeroBssLoop

    cp r26, r30
    brne zeroBssLoop

    ret 