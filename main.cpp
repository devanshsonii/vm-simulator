#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Current Features:
    -> Store
    -> Add
    -> Subtract
    -> Load from memory
    -> Store in memory
    -> Jump forward
    
Turing Complete Requirements:
    -> Conditional Branching
    -> Modify Memory
    -> Arbitary Loops
    -> Unbounded Memory (somewhat)

Turing Complete TODO:  
    -> LABELS
    -> JMP: if register x equal to y jump to instruction z
    -> JMZ: Jump if not Zero
    -> Loops: Jump to instruction X if a condition is True
*/


enum Instructions {
    MOV = 0x01,
    ADD = 0x02,
    SUB = 0x03,
    LOAD = 0x04,
    STORE = 0x05,
    OUTPUT = 0x06,
    JMZ = 0x07,
    JMP = 0x08,
    DEBUG = 0x09,
    HALT = 0xFF,
};

class VM {
private:
    vector<int> memory;
    int index;
    int registers[8];
    int pc; // Program counter
    bool halt;
    unordered_map<string, int> instruction_map;
    void execute();

public:
    VM() : memory(200, 0), index(0), pc(0), halt(false) {        
        for (int &reg : registers) {   
            reg = 0;
        }
        instruction_map = {
            {"MOV", MOV},
            {"ADD", ADD},
            {"SUB", SUB},
            {"LOAD", LOAD},
            {"STORE", STORE},
            {"OUTPUT", OUTPUT},
            {"JMZ", JMZ},
            {"JMP", JMP},
            {"HALT", HALT},
            {"DEBUG", DEBUG}
        };
    }
    void load_from_file(const string &filename);
    void run();
};

void VM::run() {
    while (!halt) {
        execute();
    }
}

void VM::load_from_file(const string &filename){
    ifstream file(filename);
    if(!file.is_open()){
        cout << "ERROR OPENING\n";
        exit(1);
    }

    string line;
    while(getline(file, line)){
        istringstream iss(line);
        string token;

        while(iss >> token){
            if(instruction_map.find(token) != instruction_map.end()){
                memory[index++] = instruction_map[token]; 
            } else {
                memory[index++] = stoi(token);
            }
        }
    }
    file.close();
    pc = 0;
}

void VM::execute() {
    int instruc = memory[pc];
    switch (instruc) {
        case MOV:
            registers[memory[pc+1]] = memory[pc+2];
            pc += 3;
            break;
        case ADD:
            registers[memory[pc+3]] = registers[memory[pc+1]] + registers[memory[pc+2]];
            pc+=4;
            break;
        case SUB:
            registers[memory[pc+3]] = registers[memory[pc+1]] - registers[memory[pc+2]];
            pc+=4;
            break;
        case LOAD:
            registers[memory[pc+1]] = memory[memory[pc+2]];
            pc += 3;
            break;
        case STORE:
            if(memory[pc+1] >= memory.size()){
                cout << "STACK OVERFLOW\n";
                exit(2);
            }
            memory[memory[pc+1]] = registers[memory[pc+2]];
            pc += 3;
            break;
        case OUTPUT:
            cout << registers[memory[++pc]] << "\n";
            pc++;
            break;
        case JMZ:
            if (registers[memory[pc+1]] == 0){
                pc = memory[pc+2];
            } else {
                pc += 3;
            }
            break;
        case JMP:
            pc = memory[pc+1];
            break;
        case HALT:
            halt = true;
            break;
        case DEBUG:
            for(auto it: memory){
                cout << it << " ";
            }
            cout << "\n";
            for (int i = 0; i < 8; i++)
            {
                cout << i << ": " << registers[i] << "\n";
            }
            pc++;
            break;
        default:
            cout << "Unknown instruction at pc: " << pc << "\n";
            halt = true;
            break;
    }
}

int main(int argc, char *argv[]) {
    VM vm;
    string file = argv[1];
    vm.load_from_file(file);
    vm.run();
}
