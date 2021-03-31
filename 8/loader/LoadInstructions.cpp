#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <boost/algorithm/string.hpp>

using namespace std;

enum instruction
{
    acc,
    jmp,
    nop
};

void loadInstructions(const string& file, vector<map<enum instruction, int>>* instructions)
{
    ifstream inFile(file);
    while(!inFile.eof())
    {
        string line;
        getline(inFile, line);
        vector<string> lineSplit;
        boost::split(lineSplit, line, [](char c){return c == ' ';});
        map<enum instruction, int> temp;

        if (lineSplit[0] == "acc")
        {   
            temp[acc] = stoi(lineSplit[1]);
            instructions->push_back(temp);

        } else if (lineSplit[0] == "jmp")
        {
            temp[jmp] = stoi(lineSplit[1]);
            instructions->push_back(temp);
        } else if (lineSplit[0] == "nop")
        {
            temp[nop] = stoi(lineSplit[1]);
            instructions->push_back(temp);
        }
            
    }
}
