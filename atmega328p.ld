MEMORY
{
    RAM (rwx)   :   ORIGIN = 0x800100, LENGTH = 2K      /* RAM memory , 2KB Byte addressed --> 2048 * 8bit, offset = 0x800000,  */
    FLASH (rx)  :   ORIGIN = 0x000000, LENGTH = 32K     /* Flash memory, 32KB word addressed --> 16K * 16bit, offset = 0x0 */
    EEPROM (rw) :   ORIGIN = 0x810000, LENGTH = 1K      /* EEPROM memory, 1KB, (Byte addressed) , offset = 0x810000 */
}

/* ENTRY(Reset_Handler) */

SECTIONS
{
    .text :
    {
        *(.vectors)
        KEEP(*(.vectors))

        *(.interrupt_handlers)
        KEEP(*(.interrupt_handlers))

        . = ALIGN(2);
        __text_start = .;

        *(.text)
        . = ALIGN(2);

        *(.text*)

        . = ALIGN(2);
        __text_end = .;
    } > FLASH

    .data :
    {
        
        . = ALIGN(2);
        __data_start = .;   /* symbols needed for compiler optimizations */

        *(.data)
        *(.data.*)

        . = ALIGN(2);
        __data_end = .;     /* symbols needed for compiler optimizations */
    } >RAM AT> FLASH
    __data_load_start = LOADADDR(.data);  /* symbols needed for compiler optimizations */

    .bss : 
    {
        . = ALIGN(2);
        __bss_start = .;

        *(.bss)
        *(.bss*)
        *(COMMON)

        . = ALIGN(2);
        __bss_end = .;
    } > RAM
}