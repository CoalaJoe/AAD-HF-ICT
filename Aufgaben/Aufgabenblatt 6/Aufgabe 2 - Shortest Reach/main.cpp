/**
 * Gegeben ist ein ungerichteter Graph in der Form wie im Unterricht besprochen:
 *
 * Graph g ;
 *
 * Implementieren Sie die folgende Funktion
 *
 * int shortestReach (Graph ∗g, int start, int end);
 *
 * Diese Funktion liefert die minimale Anzahl Knoten, welche von start nach end passiert werden muss.
 * Falls start und end gleich sind, liefert die Funktion 0.
 * Falls kein Weg zwischen start und end existiert, so liefert die Funktion den Wert -1.
 */

#include <iostream>
#include "Graph.h"

int shortestReach(Graph *g, unsigned long start, unsigned long end);

int main() {
    Graph g;
    srand(5);
    g.randomInit(10, 20);
    std::cout << g;

    std::cout << shortestReach(&g, 0, 5);

    return 0;
}

int shortestReach(Graph *g, unsigned long start, unsigned long end) {
    if (start == end) return 0;

    // processed nodes
    std::vector<int> visited;
    // number of hops to visited node
    std::vector<int> hops;
    // tracks detected nodes
    std::vector<bool> detected(g->getNumberOfNodes(), false);

    visited.push_back(start);
    hops.push_back(0);
    detected.at(start) = true;

    for (unsigned long i = 0; i < visited.size(); ++i) {
        for (const auto &neighbour : g->getNeighbours(visited.at(i))) {
            // end node found
            if (neighbour == end) return hops.at(i) + 1;

            // add neighbours
            if (!detected.at(neighbour)) {
                visited.push_back(neighbour);
                hops.push_back(hops.at(i) + 1);
                detected.at(neighbour) = true;
            }
        }
    }

    return -1;
}
