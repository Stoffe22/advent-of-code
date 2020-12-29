#include <iostream>
#include <vector>

using namespace std;

typedef struct node node;
typedef struct graph graph;

struct node {
    string name;
    vector<string> neighbours;

    void addNeighbour();
};

struct graph {
    vector<node> nodes;
    static int nrOfNodes;

    void insertNode(node& n);
    void traverse();
};