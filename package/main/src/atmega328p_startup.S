.global vector_table    ; make the vector table a global variable

.section .isr_vector, "a", @progbits    ; "a" = allocatble -> gets assigned space in final exec, @progbits = 
.type vector_table, @object             ; declares vector table as object (var / struct) instead of func

.word __data_start
.word __data_end
.word __data_LMA

.word __bss_start

.word __ram_end

vector_table:
    .word Reset_Handler
    .word INT0_isr
    .word INT1_isr
    ; different interrupts
    ; .word Default_Handler


Reset_Handler:
    ; set SP to 
    ldi SPH, high(__ram_end)    ; load high byte of __ram_end into SPH
    ldi SPL, low(__ram_end)     ; load low byte of __ram_end into SPL

    ; copy data from flash to RAM
    ldi r0, low(__data_start)
    ldi r1, high(__data_start)

    ldi r2, low(__data_LMA)
    ldi r3, high(__data_LMA)

    ldi r2, low(__data_start)
    ldi r3, high(__data_end)
