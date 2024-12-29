ENTRY(Reset_Handler)

MEMORY
{
    ITCM_RAM(xw):   ORIGIN = 0x00000000, LENGTH = 16K
    ROM(xr):        ORIGIN = 0x08000000, LENGTH = 2048K
    DTCM_RAM(xw):   ORIGIN = 0x20000000, LENGTH = 128K
    SRAM1(xw):      ORIGIN = 0x20020000, LENGTH = 368K
    SRAM2(xw):      ORIGIN = 0x2007C000, LENGTH = 16K
}

SECTIONS
{
    .text :
    {
        __text_start__ = .;
        *(.vectors)
        *(.text)
        *(.text.*)
        *(.init)
        *(.fini)
        . = ALIGN(32);
        __text_end__ = .;
    }> ROM

    .fastcode :
    {
        __fastcode_start__ = .;
        *(.fastcode)
        . = ALIGN(32);
        __fastcode_end__ = .;
    }> ITCM_RAM AT> ROM
    __fastcode_load__ = LOADADDR(.fastcode);

    .rodata :
    {
        __rodata_start__ = .;
        *(.rodata)
        *(.rodata.*)
        . = ALIGN(32);
        __rodata_end__ = .;
    }> DTCM_RAM AT> ROM
    __rodata_load__ = LOADADDR(.rodata);

    .data :
    {
        __data_start__ = .;
        *(.data)
        *(.data.*)
        . = ALIGN(32);
        __data_end__ = .;
    }> DTCM_RAM AT> ROM
    __data_load__ = LOADADDR(.data);

    .bss (NOLOAD) :
    {
        __bss_start__ = .;
        *(.bss)
        *(.bss.*)
        *(COMMON)
        . = ALIGN(32);
        __bss_end__ = .;
        end = .;     
    }> DTCM_RAM

    .heap (NOLOAD) :
    {
        __heap_start = .;
        . = . + 0x4000; /* 16KB for heap */
        . = ALIGN(32);
        __heap_end = .;
    }> DTCM_RAM

    .stack (NOLOAD) :
    {
        __stack_start__ = .;
        . = . + 0x10000; /* 64KB minimum for stack */
        . = ALIGN(32);
        __stack_end__ = .;
    }> DTCM_RAM
}