#include <algorithm>
#include <string>


void removeCharacter(std::string& str, const char& c)
{
    str.erase(remove(str.begin(), str.end(), c), str.end());
}

// Only works when word to remove is at the end of the string
void removeWord(std::string& str, std::string&& wordToRemove)
{   
    std::string newString;
    size_t len = wordToRemove.length();
    size_t j = 0;
    size_t counter;
    size_t startIndex;
    for (size_t i = 0; i < str.length(); i++) 
    {
        if (str[i] == wordToRemove[j]) 
        {   
            if (counter == 0)
            {
                startIndex = i;
            }
            counter++;
            j++;
        } else {
            counter = 0;
            j = 0;
        }

        if (counter == len)
        {   
            //std::string::iterator itStart = str.begin() + startIndex;
            //std::string::iterator itEnd = str.begin() + startIndex + len;
            str.erase(startIndex, startIndex + len);
            //newString = str.substr(0, startIndex);
        }  
    }
} 

