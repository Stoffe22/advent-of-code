#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <boost/algorithm/string.hpp>
#include <boost/tuple/tuple.hpp>

using namespace std;

enum instruction
{
    acc,
    jmp,
    nop
};

void loadInstructions(const string& file, vector<map<int, boost::tuple<enum instruction, int>>>* instructions)
{
    ifstream inFile(file);
    int i = 0;
    while(!inFile.eof())
    {
        string line;
        getline(inFile, line);
        vector<string> lineSplit;
        boost::split(lineSplit, line, [](char c){return c == ' ';});
        map<int, boost::tuple<enum instruction, int>> tuple_map;

        if (lineSplit[0] == "acc")
        {   
            tuple_map[i] = boost::make_tuple(acc, stoi(lineSplit[1]));
            instructions->push_back(tuple_map);

        } else if (lineSplit[0] == "jmp")
        {   
            tuple_map[i] = boost::make_tuple(jmp, stoi(lineSplit[1]));
            instructions->push_back(tuple_map);
        } else if (lineSplit[0] == "nop")
        {
            tuple_map[i] = boost::make_tuple(nop, stoi(lineSplit[1]));
            instructions->push_back(tuple_map);
        }
        i++;      
    }
}
