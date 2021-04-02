#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <boost/tuple/tuple.hpp>

#include "loader/LoadInstructions.hpp"
#include "helper/helper.hpp"

using namespace std;

enum instruction
{
    acc,
    jmp,
    nop
};

int main() {
    // Load instructions
    const string& file = "input.txt";
    vector<map<int, boost::tuple<enum instruction, int>>> instructions;
    loadInstructions(file, &instructions);

    // Loop over and perform the instructions
    int accumolator = 0;
    int index = 0;
    vector<int> mem;
    size_t len = instructions.size();
    while (index < len && !numIsInVector(mem, index))
    {   
        switch (instructions[index].at(index).get<0>())
        {
        case acc:
            accumolator += instructions[index].at(index).get<1>();
            mem.push_back(index);
            index++;
            break;
        case jmp:
            mem.push_back(index);
            index += instructions[index].at(index).get<1>();
            break;
        case nop:
            mem.push_back(index);
            index++;
            break;
        default:
            break;
        }  
    }

    cout << "The answer is " << accumolator << endl;

    return 0;
}