/*

guide: https://www.youtube.com/watch?v=NqSE_aVCJXg&t=6897s

IDT - Interrupt Descriptor Table

*/

#ifndef KERNEL_IDT_H
#define KERNEL_IDT_H

#include "types.h"

#define TRAP_GATE_FLAGS 0x8F // p = 1, DPL = 00, S = 0, Type = 1111 (32bit trap gate)
#define INT_GATE_FLAGS 0x8E // p = 1, DPL = 00, S = 0, Type = 1110 (32bit interrupt gate)
#define INT_GATE_USER_FLAGS 0xEE // p = 1, DPL = 11, S = 0, Type = 1110 (32bit interrupt gate, called from PL 3)

typedef struct {
    uint16 isr_address_low;     // lower 16 bits of isr addr
    uint16 kernel_cs;           // code segment for this ISR
    uint8  reserved;            // Set to 0, reserved by Intel
    uint8  attributes;          // Type and attributes; Flags
    uint16 isr_address_high;    // upper 16 bits of isr addr
} __attribute__ ((packed)) idt_entry_32;

// 2 byte limit
// 4 byte base
// IDTR layout
typedef struct {
    uint16 limit;
    uint32 base;
} __attribute__ ((packed)) idtr_32;


idt_entry_32 idt32[256]; // actual IDT
idtr_32 idtr32;          // IDT register instance


// interrupt frame to pass interrupt handlers/ISRs
typedef struct {
    uint32 eip;
    uint32 cs;
    uint32 eflags;
    uint32 sp;
    uint32 ss;
} __attribute__ ((packed)) int_frame_32;

// Default exception handler (no error code)
__attribute__((interrupt)) void default_exception_handler(int_frame_32 *frame) 
{

}

// Default exception handler (includes error code)
__attribute__((interrupt)) void default_exception_handler_err_code(int_frame_32 *frame, uint32 error_code) 
{

} 

// Default interrupt handler
__attribute__((interrupt)) void default_interrupt_handler(int_frame_32 *frame) 
{

}

// Add an ISR to the IDT
void set_idt_descriptor_32(uint8 entry_number, void *isr, uint8 flags) 
{
    idt_entry_32 *descriptor = &idt32[entry_number];
    descriptor->isr_address_low = (uint32)isr & 0xFFFF;
    descriptor->kernel_cs = 0x08; // look into this
    descriptor->reserved = 0; 
    descriptor->attributes = flags;
    descriptor->isr_address_high = ((uint32)isr >> 16) & 0xFFFF;
    
}

void init_idt() 
{
    idtr32.limit = (uint16)(8 * 255); // 256 descriptors (0-255)
    idtr32.base = (uint32)&idt32[0];

    // setup exception handlers (ISRs 0-31)
    for (uint8 entry = 0; entry < 32; entry++)
    {
        if (
            entry == 8  ||
            entry == 10 ||
            entry == 11 ||
            entry == 12 ||
            entry == 13 ||
            entry == 14 ||
            entry == 17 ||
            entry == 21 ) 
        {
            set_idt_descriptor_32(entry, default_exception_handler_err_code, TRAP_GATE_FLAGS);
        } else 
        {
            set_idt_descriptor_32(entry, default_exception_handler, TRAP_GATE_FLAGS);
        }        
    }

    // setup interrupts (ISRs 32-255)
    for (uint8 entry = 32; entry < 256; entry++)
    {
        set_idt_descriptor_32(entry, default_interrupt_handler, INT_GATE_FLAGS);
    }
    
    

    __asm__ __volatile__ ("lidt %0" : : "memory"(idtr32));
}


#endif