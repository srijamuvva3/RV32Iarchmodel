#include "control.h"

#include "../common/instruction.h"
#include "../common/control_signals.h"
ControlSignals ControlUnit::generate(
    const Instruction& instruction) const
{
    ControlSignals signals;

    switch (instruction.opcode)
    {
        // R-type: ADD, SUB, AND, OR, XOR, SLT, SLL, SRL, SRA
        case 0x33:
        {
            signals.reg_write = true;
            signals.alu_source = ALUSource::REGISTER;

            switch (instruction.funct3)
            {
                case 0x0:
                    if (instruction.funct7 == 0x00)
                        signals.alu_operation = ALUOperation::ADD;
                    else if (instruction.funct7 == 0x20)
                        signals.alu_operation = ALUOperation::SUB;
                    break;

                case 0x7:
                    signals.alu_operation = ALUOperation::AND;
                    break;

                case 0x6:
                    signals.alu_operation = ALUOperation::OR;
                    break;

                case 0x4:
                    signals.alu_operation = ALUOperation::XOR;
                    break;

                case 0x2:
                    signals.alu_operation = ALUOperation::SLT;
                    break;

                case 0x1:
                    signals.alu_operation = ALUOperation::SLL;
                    break;

                case 0x5:
                    if (instruction.funct7 == 0x00)
                        signals.alu_operation = ALUOperation::SRL;
                    else if (instruction.funct7 == 0x20)
                        signals.alu_operation = ALUOperation::SRA;
                    break;
            }

            break;
        }

        // I-type arithmetic: ADDI, ANDI, ORI, XORI, SLTI, ...
        case 0x13:
        {
            signals.reg_write = true;
            signals.alu_source = ALUSource::IMMEDIATE;

            switch (instruction.funct3)
            {
                case 0x0:
                    signals.alu_operation = ALUOperation::ADD;
                    break;

                case 0x7:
                    signals.alu_operation = ALUOperation::AND;
                    break;

                case 0x6:
                    signals.alu_operation = ALUOperation::OR;
                    break;

                case 0x4:
                    signals.alu_operation = ALUOperation::XOR;
                    break;

                case 0x2:
                    signals.alu_operation = ALUOperation::SLT;
                    break;

                case 0x1:
                    signals.alu_operation = ALUOperation::SLL;
                    break;

                case 0x5:
                    if (instruction.funct7 == 0x00)
                        signals.alu_operation = ALUOperation::SRL;
                    else if (instruction.funct7 == 0x20)
                        signals.alu_operation = ALUOperation::SRA;
                    break;
            }

            break;
        }

        // LW
        case 0x03:
        {
            signals.reg_write = true;
            signals.alu_source = ALUSource::IMMEDIATE;
            signals.alu_operation = ALUOperation::ADD;

            signals.mem_read = true;
            signals.mem_to_reg = true;

            break;
        }

        // SW
        case 0x23:
        {
            signals.alu_source = ALUSource::IMMEDIATE;
            signals.alu_operation = ALUOperation::ADD;

            signals.mem_write = true;

            break;
        }

        // Branch instructions: BEQ, BNE, BLT, ...
        case 0x63:
        {
            signals.branch = true;
            signals.alu_source = ALUSource::REGISTER;
            signals.alu_operation = ALUOperation::SUB;

            break;
        }

        // JAL
        case 0x6F:
        {
            signals.jump = true;
            signals.reg_write = true;

            break;
        }

        // JALR
        case 0x67:
        {
            signals.jump = true;
            signals.reg_write = true;

            signals.alu_source = ALUSource::IMMEDIATE;
            signals.alu_operation = ALUOperation::ADD;

            break;
        }

        default:
        {
            // Unsupported instruction.
            // Default signals remain false/NONE.
            break;
        }
    }

    return signals;
}