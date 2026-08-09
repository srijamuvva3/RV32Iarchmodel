#pragma once

#include <cstdint>
#include "instruction.h"

class Decoder {
public:
    Instruction decode(uint32_t raw_instruction) const;

private:
    int32_t decodeImmediate(uint32_t instruction, InstructionFormat format) const;
};