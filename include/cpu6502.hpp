#pragma once /* better use header guards */

#include "bus.hpp"

namespace nes
{
    class cpu6502
    {
    public:
        cpu6502();
        ~cpu6502();

        void ConnectBus(Bus *n)
        {
            bus = n;
        }

    public:
        uint8_t a = 0x00; /* Accumulator register */
        uint8_t x = 0x00; /* X register */
        uint8_t y = 0x00; /* Y register */
        uint8_t stkp = 0x00; /* Stack Pointer (points to location on bus) */
        uint16_t pc = 0x0000; /* Program Counter */
        uint8_t status = 0x00; /* Status Register */
        
        /* The status register stores 8 flags. Ive enumerated these here for ease
           of access. You can access the status register directly since its public.
           The bits have different interpretations depending upon the context and 
           instruction being executed. */
        enum FLAGS6502
        {
            C = (1 << 0),	 /* Carry Bit */
            Z = (1 << 1),	 /* Zero */
            I = (1 << 2),	 /* Disable Interrupts */
            D = (1 << 3),	 /* Decimal Mode (unused in this implementation) */
            B = (1 << 4),	 /* Break */
            U = (1 << 5),	 /* Unused */
            V = (1 << 6),	 /* Overflow */
            N = (1 << 7),	 /* Negative */
        };

    private:
        Bus *bus = nullptr;
        uint8_t read(uint16_t addr);
        void write(uint16_t addr, uint8_t data);

        uint8_t GetFlag(FLAGS6502 f);
        void SetFlag(FLAGS6502 f, bool v);

    };
}

