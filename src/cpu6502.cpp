

#include "cpu6502.hpp"

namespace nes
{
    cpu6502::cpu6502()
    {
    }

    cpu6502::~cpu6502()
    {
    }

    uint8_t cpu6502::read(uint16_t addr)
    {
        return bus->read(addr, false);
    }

    void cpu6502::write(uint16_t addr, uint8_t data)
    {
        bus->write(addr, data);
    }
}

