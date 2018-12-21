#include <iostream>
#include <vector>

/**
 * Schreiben Sie eine Funktion, welche überprüft, ob es sich bei einem binären Baum
 * um einen MinHeap handelt. Falls der Baum ein Min Heap ist, soll die Funktion
 * den Wert `true` zurückgeben. Der Baum wird in Form eines vector Objektes
 * repräsentiert.
 *
 * @param tree
 * @return
 */
bool validate(const std::vector<int> &tree);

/**
 * Schreiben Sie eine Funktion, welche die Summe aller Knoten eines binären Baumes
 * eines bestimmten Levels zurückliefert. Ist das Level leer, respektive nicht
 * vorhanden, so wird -1 zurückgegegben.Der Root Knoten befindet sich in Level 0,
 * die beiden Kinder vom Root Knoten in Level 1, u.s.w. Der Baum wird in Form
 * eines vector Objektes repräsentiert. Ist an einer Stelle der Wert -1, so
 * bedeutet dies, dass es an dieser Stelle keinen Knoten gibt. Sie können davon
 * ausgehen, dass es sich beim übergebenen Objekt um einen korrekten Baum handelt.
 *
 * @param tree
 * @param level
 * @return
 */
int sum(const std::vector<int> &tree, unsigned int level);

int main() {

  // Aufgabe 3
  std::vector<int> minHeap = {1, 2, 3, 4, 5, 6, 7, 8};
  std::vector<int> bsTree = {8, 7, 6, 5, 4, 3, 2, 1};

  if (validate(minHeap)) {
    std::cout << "Korrekt - minHeap is minHeap\n";
  }

  if (!validate(bsTree)) {
    std::cout << "Korrekt - bsTree is not minHeap\n";
  }

  std::cout << "\n\n\n";

  // Aufgabe 4
  std::vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8};
  std::cout << "Level 0: " << sum(v1, 0) << "\n";
  std::cout << "Level 1: " << sum(v1, 1) << "\n";
  std::cout << "Level 2: " << sum(v1, 2) << "\n";
  std::cout << "Level 3: " << sum(v1, 3) << "\n";


  return 0;
}

bool validate(const std::vector<int> &tree, int currentNode);

bool validate(const std::vector<int> &tree) {
  return validate(tree, 0);
}

int leftNode(const std::vector<int> &tree, int node);

int rightNode(const std::vector<int> &tree, int node);

/**
 * Recursive inner function.
 *
 * @param tree
 * @param currentNode
 * @return
 */
bool validate(const std::vector<int> &tree, int currentNode) {
  bool state = true;
  if (leftNode(tree, currentNode) != -1) {
    if (tree[leftNode(tree, currentNode)] < tree[currentNode]) {
      return false;
    }
    state &= validate(tree, leftNode(tree, currentNode));
  }

  if (rightNode(tree, currentNode) != -1) {
    if (tree[rightNode(tree, currentNode)] < tree[currentNode]) {
      return false;
    }
    state &= validate(tree, rightNode(tree, currentNode));
  }

  return state;
}

int leftNode(const std::vector<int> &tree, int node) {
  int nodePos = node * 2 + 1;
  if (nodePos < tree.size()) {
    return nodePos;
  }

  return -1;
}

int rightNode(const std::vector<int> &tree, int node) {
  int nodePos = node * 2 + 2;
  if (nodePos < tree.size()) {
    return nodePos;
  }

  return -1;
}

// ----------------------------

/**
 * Schreiben Sie eine Funktion, welche die Summe aller Knoten eines binären Baumes
 * eines bestimmten Levels zurückliefert. Ist das Level leer, respektive nicht
 * vorhanden, so wird -1 zurückgegegben.Der Root Knoten befindet sich in Level 0,
 * die beiden Kinder vom Root Knoten in Level 1, u.s.w. Der Baum wird in Form
 * eines vector Objektes repräsentiert. Ist an einer Stelle der Wert -1, so
 * bedeutet dies, dass es an dieser Stelle keinen Knoten gibt. Sie können davon
 * ausgehen, dass es sich beim übergebenen Objekt um einen korrekten Baum handelt.
 *
 * @param tree
 * @param level
 * @return
 */
int sum(const std::vector<int> &tree, unsigned int level) {
  long long baseTwo = 1;
  baseTwo <<= level;
  int sum = 0;

  for (int i = 0; i<baseTwo; ++i) {
    if (tree.size() < baseTwo-1 +i)break;
    sum += tree[baseTwo-1 + i];
  }

  return sum;
}
