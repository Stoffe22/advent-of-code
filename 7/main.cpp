#include "Graph.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>

#include "lib/StringHandler.hpp"

int main(int argc, char** argv) {
    
   
    /*const char* fileNameBuffer;
    fileNameBuffer = argv[1];
    std::string fileName(fileNameBuffer);
    std::string filePath = "../../" + fileName;*/

    // Construct graph
    std::string filePath = "input.txt";
    Graph graph(filePath);

    // Get src nodes
    std::ifstream inFile(filePath);
    std::string line;
    std::vector<std::string> srcNodes;

    while(!inFile.eof())
    {
        getline(inFile, line);
        std::vector<std::string> result;
        boost::split(result, line, [] (char c){return c == ',';});
        std::string srcName = result[0];
        removeCharacter(srcName, ' ');
        removeWord(srcName, "contain");
        removeWord(srcName, "bag");
        removeWord(srcName, "bags");
        srcNodes.push_back(srcName);
    } 

    //graph.print();
    //std::cout << Graph::nrOfNodes;

    // Choose origin-node and traverse graph from there
    /*char str[30];
    printf("Enter origin node: ");
    scanf("%s", str);
    std::string originNode(str);*/
    // const std::string destNode = "vibrantpurple";


    // bool result = graph.isConnected(src, dest);

    // std::cout << result << std::endl;

    return 0;
    
}