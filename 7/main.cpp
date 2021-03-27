#include "Graph.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>

#include "lib/StringHandler.hpp"
#include "lib/SrcNodesLoader.hpp"

using namespace std;

int main(int argc, char** argv) {

    // Construct graph
    const string file = "input.txt";
    Graph graph(file);

    // Load the source nodes
    vector<string> srcNodes;
    vector<string>* srcNodes_p = &srcNodes;
    LoadSrcNodes(file, srcNodes_p);

    // Loop over the src nodes and check if they are connected
    // to "shiny gold" node
    const string& destNode = "shinygold";
    bool isConnected = false;
    int counter = 0;
    for(auto& srcNode: srcNodes)
    {   
        isConnected = graph.isConnected(srcNode, destNode);
        graph.resetIsVisited();
        if (isConnected && srcNode != destNode)
            counter++;
    }

    // Print result
    cout << "The result is: " << counter;
    return 0;
}

