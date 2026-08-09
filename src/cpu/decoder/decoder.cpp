#include "decoder.h"

Instruction Decoder::decode(uint32_t raw_instruction) const
{
    Instruction instruction{};

    instruction.raw = raw_instruction;

    // Common fields
    instruction.opcode = raw_instruction & 0x7F;
    instruction.rd     = (raw_instruction >> 7)  & 0x1F;
    instruction.funct3 = (raw_instruction >> 12) & 0x07;
    instruction.rs1    = (raw_instruction >> 15) & 0x1F;
    instruction.rs2    = (raw_instruction >> 20) & 0x1F;
    instruction.funct7 = (raw_instruction >> 25) & 0x7F;

    // Determine instruction format
    switch (instruction.opcode)
    {
        // R-type instructions
        case 0x33:
            instruction.format = InstructionFormat::R;
            break;

        // I-type ALU instructions
        // ADDI, SLTI, XORI, ORI, ANDI,
        // SLLI, SRLI, SRAI
        case 0x13:
            instruction.format = InstructionFormat::I;
            break;

        // I-type load instructions
        // LB, LH, LW, LBU, LHU
        case 0x03:
            instruction.format = InstructionFormat::I;
            break;

        // I-type JALR
        case 0x67:
            instruction.format = InstructionFormat::I;
            break;

        // S-type store instructions
        // SB, SH, SW
        case 0x23:
            instruction.format = InstructionFormat::S;
            break;

        // B-type branch instructions
        // BEQ, BNE, BLT, BGE, BLTU, BGEU
        case 0x63:
            instruction.format = InstructionFormat::B;
            break;

        // U-type LUI
        case 0x37:
            instruction.format = InstructionFormat::U;
            break;

        // U-type AUIPC
        case 0x17:
            instruction.format = InstructionFormat::U;
            break;

        // J-type JAL
        case 0x6F:
            instruction.format = InstructionFormat::J;
            break;

        default:
            instruction.format = InstructionFormat::UNKNOWN;
            break;
    }

    // Generate immediate according to instruction format
    instruction.immediate =
        decodeImmediate(raw_instruction, instruction.format);

    return instruction;
}