#ifndef AUFGABE_1_ALL_NODES_ARE_REACHABLE_GRAPH_H
#define AUFGABE_1_ALL_NODES_ARE_REACHABLE_GRAPH_H

#include<vector>
#include<iostream>
#include<cstdlib>
#include<list>
#include<algorithm>

class Graph {
    // Properties
private:
    std::vector<std::vector<int>> neighbours;
    std::vector<std::vector<int>> weights;

    // Methods
private:
    void dfs(int current, std::vector<int> &result, std::vector<bool> &detected);

public:
    Graph();

    void randomInit(int nNodes = 5, int nConnections = 8, bool directed = false);

    int getNumberOfNodes();

    std::vector<int> getNeighbours(int node);

    std::vector<int> getWeights(int node);

    void addNode(std::vector<int> neighbours, std::vector<int> weights);

    std::vector<int> dfs(int start);

    std::vector<int> bfs(int start);

    bool allNodesAreReachable(int start);

    int shortestReach(int start, int end);

    std::vector<int> getPath(int start, int end);

    friend std::ostream &operator<<(std::ostream &s, const Graph &obj);
};

std::ostream &operator<<(std::ostream &s, const Graph &obj);


#endif //AUFGABE_1_ALL_NODES_ARE_REACHABLE_GRAPH_H
