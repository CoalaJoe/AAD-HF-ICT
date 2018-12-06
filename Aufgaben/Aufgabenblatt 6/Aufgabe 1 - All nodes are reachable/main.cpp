/**
 * Diese Funktion erhält als Parameter einen Graphen, die Anzahl Knoten und den Start Knoten.
 * Die Funktion liefert true falls alle anderen Knoten im Graphen von start erreichbar sind.
 * Falls ein oder mehrere Knoten nicht erreichbar sind, so liefert die Funktion false.
 */

#include <iostream>
#include <unordered_set>
#include "Graph.h"

bool allNodeAreReachable(Graph *g, int start);

int main() {
    Graph demo;
    srand(2);
    demo.randomInit(5, 5);
    std::cout << demo;
    if (allNodeAreReachable(&demo, 0)) {
        std::cout << "All Noes are reachable";
    } else {
        std::cout << "All Noes are not reachable";
    }

    return 0;
}

bool allNodeAreReachable(Graph *g, int start) {
    return g->bfs(start).size() == g->getNumberOfNodes();
}
