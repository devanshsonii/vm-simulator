# Simple Virtual Machine (VM) Simulator

A minimalistic virtual machine simulator implemented in C++ designed to read and execute custom assembly-like instructions. This VM includes basic arithmetic, memory manipulation, and conditional operations, aiming to be an educational tool for learning the fundamentals of CPU emulation and instruction execution.

## Features

- **Basic Instruction Set**: Supports data manipulation (move, add, subtract), memory storage/loading, and output.
- **Conditional Jumps**: Implements conditional branching with `JMZ` and unconditional jumping with `JMP`.
- **Program Counter**: Tracks current instruction location, enabling sequential and conditional execution.
- **Debugging**: Displays register and memory states for easier debugging and understanding.
- **Expandable**: The instruction set can be easily expanded to support more complex operations.

## Getting Started

### Prerequisites

- C++ compiler (supporting C++11 or later)

### Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/devanshsonii/vm-simulator
   cd vm-simulator
   ```

2. Compile the project:
   ```bash
   g++ -o vm main.cpp
   ```

### Usage

1. Prepare a text file with your assembly-like instructions, e.g., `program.txt`. For example:
   ```
   MOV 0 5       # Set register 0 to 5
   ADD 0 1 2     # Add registers 0 and 1, store result in register 2
   OUTPUT 2      # Output the result from register 2
   HALT          # Stop the program
   ```

2. Run the VM with the instruction file:
   ```bash
   ./vm program.txt
   ```

### Instruction Set

| Instruction | Opcode | Description                                               |
|-------------|--------|-----------------------------------------------------------|
| `MOV`       | 0x01   | Move a value into a register.                             |
| `ADD`       | 0x02   | Add two registers and store the result in another.        |
| `SUB`       | 0x03   | Subtract one register from another and store the result.  |
| `LOAD`      | 0x04   | Load a value from memory into a register.                 |
| `STORE`     | 0x05   | Store a register's value into memory.                     |
| `OUTPUT`    | 0x06   | Output a register's value.                                |
| `JMZ`       | 0x07   | Jump to address if register value is zero.                |
| `JMP`       | 0x08   | Jump to specified instruction address unconditionally.    |
| `DEBUG`     | 0x09   | Print current memory and register states.                 |
| `HALT`      | 0xFF   | Stop execution.                                           |

## Implemented Parts

- **Arithmetic and Memory Instructions**: `MOV`, `ADD`, `SUB`, `LOAD`, and `STORE`.
- **Jump Instructions**: `JMZ` (Jump if zero), `JMP` (Unconditional jump).
- **Debugging**: Output register and memory states with `DEBUG`.
- **Program Control**: `HALT` for stopping program execution.
  
## To Implement

- **Labels**: To allow jumping to labeled sections instead of hard-coded addresses.
- **JNZ (Jump if Not Zero)**: For more flexible conditional branching.
- **Looping Constructs**: Using conditional and unconditional jumps to support loops.
- **Unbounded Memory Management**: Extending memory dynamically to mimic unbounded memory.
- **Additional Instructions**: Such as multiplication, division, and logical operations for expanded functionality.
  
## Example Program

Here's a sample program to demonstrate the VM:

```assembly
MOV 0 10       # Move 10 to register 0
MOV 1 5        # Move 5 to register 1
ADD 0 1 2      # Add register 0 and 1, store in register 2
OUTPUT 2       # Output register 2
HALT           # Stop execution
```

## Contributing

Contributions are welcome! Feel free to open issues or submit pull requests.
