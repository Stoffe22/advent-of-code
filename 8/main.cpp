#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "loader/LoadInstructions.hpp"

using namespace std;


int main() {

    // Load instructions
    const string& file = "input.txt";
    vector<map<enum instruction, int>> instructions;
    loadInstructions(file, &instructions);

    // Use this
    

    int accumolator = 0;
    // Loop over and perform the instructions
    for(auto& instructions: instructions)
    {
        // Use
        
    }

    return 0;
}