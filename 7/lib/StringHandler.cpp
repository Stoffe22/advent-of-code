#include <algorithm>
#include <string>


void cleanString(std::string& str)
{
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
}

