/**
 * Gegeben ist ein gerichteter, gewichteter Graph in der Form wie im Unterricht besprochen:
 *
 * Graph g;
 *
 * Implementieren Sie die folgende Funktion
 *
 * vector<int> getPath(Graph ∗g, int start, int end);
 *
 * Diese Funktion liefert einen Vector, welche alle Knoten (günstigster Weg) beinhaltet,
 * welche von start nach end passiert werden müssen.
 */

#include <iostream>
#include <queue>
#include "Graph.h"

std::vector<int> getPath(Graph *g, unsigned int start, unsigned int end);

int main() {
    Graph g;
    srand(3);
    g.randomInit(10, 20, true);
    std::cout << g;
    auto path = getPath(&g, 0, 4);
    
    for (auto n : path) {
        std::cout << n << ", ";
    }
    std::cout << "\n";

    return 0;
}

std::vector<int> getPath(Graph *g, unsigned int start, unsigned int end) {
    // validate params
    std::vector<int> result;
    int numberOfNodes = g->getNumberOfNodes();

    if (start >= numberOfNodes || end >= numberOfNodes) return result;

    if (start == end) {
        result.push_back(start);
        return result;
    }

    // initialize table
    std::vector<int> distance(numberOfNodes, INT_MAX);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
            std::greater<std::pair<int, int>>>
            prioQueue;
    std::vector<bool> marked(numberOfNodes, false);
    std::vector<int> predecessor(numberOfNodes, -1);

    // write start node to table
    distance.at(start) = 0;
    prioQueue.push(std::make_pair(0, start));
    predecessor.at(start) = start;

    // process path
    while (!prioQueue.empty()) {
        int current = prioQueue.top().second;
        prioQueue.pop();
        if (marked.at(current)) continue;
        marked.at(current) = true;

        std::vector<int> neighbours = g->getNeighbours(current);
        std::vector<int> weights = g->getWeights(current);

        for (int i = 0; i < neighbours.size(); i++) {
            auto neighbour = static_cast<unsigned long>(neighbours.at(i));
            if (marked.at(neighbour)) continue;
            int newDist = distance.at(current) + weights.at(i);
            if (newDist < distance.at(neighbour)) {
                distance.at(neighbour) = newDist;
                prioQueue.push(std::make_pair(newDist, neighbour));
                predecessor.at(neighbour) = current;
            }
        }
    }

    // return shortest path
    if (predecessor.at(end) != -1) {  // fill result only if end is reachable
        result.push_back(end);
        int prev = predecessor.at(end);
        while (prev != start) {
            result.push_back(prev);
            prev = predecessor.at(prev);
        }
        result.push_back(start);
    }
    reverse(result.begin(), result.end());
    return result;
}
