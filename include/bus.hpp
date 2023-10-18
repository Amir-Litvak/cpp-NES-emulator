#pragma once /* better use header guards */

#include <cstdint> /* rename std tyeps into explicit types */
#include <array>

#include "cpu6502.hpp"

namespace nes
{
    class Bus
    {
    public:
        Bus();
        ~Bus();
        void write(uint16_t addr, uint8_t data);
        uint8_t read(uint16_t addr, bool bReadOnly = false);

        /* devices on bus */
        cpu6502 cpu;
        std::array<uint8_t, 64 * 1024> ram; /* fake RAM for now */

    };
}

