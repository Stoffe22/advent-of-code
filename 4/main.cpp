#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <string>
#include <string.h>

using namespace std;

int main() {

    vector<map<string, string>> passportInfo;
    ifstream inFile("input.txt");

    if(!inFile) {
        cout << "Unable to open file";
        exit(1);
    }

    string str;
    int passportFieldCounter = 0;
    int validPassportCounter = 0;

    while(getline(inFile, str)) {

        if (str.empty()) {
            if(passportFieldCounter == 7) {
                validPassportCounter++;
            }
            passportFieldCounter = 0;
        }

        char* word = strtok((char *)str.c_str(), " :");
        while(word != NULL) {

            if (!strcmp(word, "ecl") || !strcmp(word, "pid") || !strcmp(word, "hcl") || !strcmp(word, "byr") 
                || !strcmp(word, "iyr") || !strcmp(word, "hgt") || !strcmp(word, "eyr")) {
                passportFieldCounter++;
            }
            word = strtok(NULL, " :");
        }
        
    }
    cout << "The number of valid passports are: " << validPassportCounter << endl;   
}
