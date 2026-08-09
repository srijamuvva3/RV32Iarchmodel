#pragma once

#include <cstdint>

enum class InstructionFormat{
    R,
    I,
    S,
    B,
    U,
    J,
    UNKNOWN
};


struct Instruction
{
    InstructionFormat format;
    uint32_t raw;
    uint32_t opcode;
    uint32_t rd;
    uint32_t rs1;
    uint32_t rs2;
    uint32_t funct3;
    uint32_t funct7;
    int32_t immediate;
};