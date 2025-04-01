ENTRY(Reset_Handler)

MEMORY
{
    RAM (rwx)   :   ORIGIN = 0x800100, LENGTH = 2K      /* RAM memory , 2KB Byte addressed --> 2048 * 8bit, offset = 0x800000,  */
    FLASH (rx)  :   ORIGIN = 0x000000, LENGTH = 32K     /* Flash memory, 32KB word addressed --> 16K * 16bit, offset = 0x0 */
    EEPROM (rw) :   ORIGIN = 0x810000, LENGTH = 1K      /* EEPROM memory, 1KB, (Byte addressed) , offset = 0x810000 */
}

__ram_end = ORIGIN(RAM) + LENGTH(RAM) - 1;
/*
    offsets for RAM and EEPROM because gcc compiles for devices with one address space (0x0 --> 0xN). but AVR has Multiple addressing spaces (FLASH, RAM, EEPROM)
    so gcc can create an ELF file.

    SRAM starts at 0x800100 because 0x800000 - 0x8000FF are special registers
*/

SECTIONS
{
    /*
        .text section contains code / instructions for the cpu to execute.
        at the start of text section is vector table because Reset_Handler / startup code needs to be at address 0x0
    */
    .text :
    {
        . = ALIGN(2);       /* Aligning Location pointer to 2Bytes */
        __text_start = .;   /* sets the __text_start symbol to current value of location counter --> start of text section (VMA)*/

        KEEP(.isr_vector);
        *(.text)            /* tells linker to put all .text sections of all object files here */
        
        . = ALIGN(2);       
        __text_end = .;     /*sets the __text_end symbol to current value of location counter --> end of text section*/
    } > FLASH
    __data_LMA = LOADADDR(.data); /* gives the byte address of data section in Flash memory (LMA)*/
    .data :
    {
        . = ALIGN(2);
        __data_start = .;

        *(.data)

        . = ALIGN(2);
        __data_end = .;
    } > RAM AT> FLASH

    .bss :
    {
        . = ALIGN(2);
        __bss_start = .;

        *(.bss)

        . = ALIGN(2);
        __bss_end = .;
    } > RAM
}


/*
    . is the location counter in linker scripts, it is the currten place in memory where stuff gets placed. 
    eg: . is 0x800100 and .data section is defined without giving a specifc addres means it gets placed at 0x800100
        and if .data size is 0x100 means the next section gets placed at 0x800100 + 0x100 = 0x800200


        .rodata : 
    {
        . = ALIGN(2);

        *(.rodata)

        . = ALIGN(2);
    } > FLASH
    
    
*/