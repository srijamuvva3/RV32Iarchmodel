# RV32Iarchmodel
RV32I architecture model building from scratch, it has baseline 32-bit integer configuration of RISC-V containing 40 basic integer instructions and 32 32 bit GPRs
# Simulation model 
Block diagram
                    ┌──────────────────┐
                    │   RISC-V CPU     │
                    │                  │
 Program → Memory → │ Fetch            │
                    │   ↓              │
                    │ Decode           │
                    │   ↓              │
                    │ Register File    │
                    │   ↓              │
                    │ ALU              │
                    │   ↓              │
                    │ Memory Access    │
                    │   ↓              │
                    │ Writeback        │
                    └──────────────────┘
                             │
                             ↓
                           PC
