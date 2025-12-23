#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <list>
#include <map>

using namespace std;

struct Node {
    string name;
    list<int> adj;
};

class Graph {
private:
    vector<Node> graph;
    int V;
    map<string, int> cityToIndex;
    void dfs(int u, vector<int>& disc, vector<int>& low, vector<int>& parent, vector<bool>& ap, vector<bool>& visited);

public:
    Graph(int V);
    void addEdge(string u, string v);
    void findCriticalPoints();
    void printGraph();
    void eventSimulation(string city, bool lockdown);
    void addCity(string name);
};

#endif
