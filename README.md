# RV32Iarchmodel
RV32I architecture model building from scratch, it has baseline 32-bit integer configuration of RISC-V containing 40 basic integer instructions and 32 32 bit GPRs
# Simulation model 
RISC-V Assembly / Machine Code -> Instruction Memory -> Fetch Instruction -> Decode -> Execute -> Register File / Memory -> Update PC -> Repeat
# Important to understand
**Registers:** There are 32 registers each of 32 bits\
**Program Counter:** Indicates address of current instruction, each instruction is of 32 bits PC -> PC+4 [memory is byte-addressable, 1byte = 8bits]\
**Instruction Types:** R-type: reg-reg (add, sub,..) I-type: Short immediate constants and loads (addi, lw) S-type: Store to memory (sw) B-type: Conditional branch (sometimes called SB-type) U-type: Upper immediate(e.g., lui, auipc) J-type: Unconditional jump (jal)
    Bit field Layout: <img width="942" height="327" alt="image" src="https://github.com/user-attachments/assets/8cf8390f-9ba6-4e99-a4b0-b1433388b627" />


