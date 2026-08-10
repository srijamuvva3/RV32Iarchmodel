#ifndef CONTROL_SIGNALS_H
#define CONTROL_SIGNALS_H

#include <cstdint>
#include "../alu/alu.h"

enum class aluSource{
    REGISTER,
    IMMEDIATE
};

struct ControlSignals{
    ALUoperation alu_op;
    aluSource alu_src;
    bool mem_read = false;
    bool mem_write = false;
    bool mem_to_reg = false;
    bool jump = false;
    bool branch = false;
};

#endif // CONTROL_SIGNALS_H
