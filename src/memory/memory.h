#ifndef MEMORY_H
#define MEMORY_H

#include <cstdint>

class Memory
{
private:
    static constexpr uint32_t MEMORY_SIZE = 64 * 1024; // 64 KB memory byte addressable
    uint8_t data[MEMORY_SIZE];

public:
    Memory();
    //for MAR
    uint32_t read32(uint32_t address) const;
    void write32(uint32_t address, uint32_t value);
    //for MDR
    uint8_t read8(uint32_t address) const;
    void write8(uint32_t address, uint8_t value); 

    void reset();
};

#endif