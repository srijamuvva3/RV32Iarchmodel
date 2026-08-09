#include "pc.h"

PC::PC()
{
    reset();
}

uint32_t PC::read() const
{
    return value;
}

void PC::write(uint32_t new_value)
{
    value = new_value;
}

void PC::reset()
{
    value = 0;
}