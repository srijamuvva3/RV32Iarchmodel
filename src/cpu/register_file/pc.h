#ifndef PC_H
#define PC_H

#include <cstdint>

class PC{
    private:
        uint32_t value;
    public:
        PC();
        uint32_t read() const;
        void write(uint32_t new_value);
};

#endif
