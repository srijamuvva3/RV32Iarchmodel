#include <iostream>
#include <cassert>

#include "../src/cpu/cpu.h"
#include "../src/memory/memory.h"

int main()
{
    Memory memory;
    CPU cpu(memory);

    cpu.reset();

    // ADDI x1, x0, 10
    memory.write32(0x00, 0x00A00093);

    // ADDI x2, x0, 20
    memory.write32(0x04, 0x01400113);

    // ADD x3, x1, x2
    memory.write32(0x08, 0x002081B3);

    // Execute the three instructions
    cpu.step();
    cpu.step();
    cpu.step();

    // Check results
    assert(cpu.getRegister(1) == 10);
    assert(cpu.getRegister(2) == 20);
    assert(cpu.getRegister(3) == 30);

    std::cout << "Arithmetic test PASSED!" << std::endl;

    return 0;
}