#include <iostream>
#include <string>
#include "SuffixNode.h"

#define MAX_CHAR 256

struct SuffixTreeNode {
    struct SuffixTreeNode *children[MAX_CHAR];

    struct SuffixTreeNode *suffixLink;

    // (start, end( interval specifies the edge, by
    // which the node is connected to its parent node.
    // Each edge connect to nodes and (start, end) interval
    // is stored on child node.
    int start;
    int *end;

    int suffixIndex;
};

SuffixTreeNode *newNode(int start, int *end);

int edgeLength(SuffixTreeNode *n);

int walkDown(SuffixTreeNode *currNode);

void extendSuffixTree(int pos);

void setSuffixIndexByDFS(SuffixTreeNode *n, int labelHeight);

int doTraversal(SuffixTreeNode *n, int labelHeight, int *maxHeight, int *substringStartIndex);


char           text[100];
SuffixTreeNode *root = nullptr;

// last node created which may get a suffix link in next extension
SuffixTreeNode *lastNewNode = nullptr;
SuffixTreeNode *activeNode  = nullptr;

// activeEdge is an input string character index
int activeEdge   = -1;
int activeLength = 0;

int remainingSuffixCount = 0;

int leafEnd   = -1;
int *rootEnd  = nullptr;
int *splitEnd = nullptr;
int size      = -1; // Length of input string
int size1     = 1; // Size of 1st string

SuffixTreeNode *newNode(int start, int *end)
{
    auto     node = new SuffixTreeNode;
    for (int i    = 0; i < MAX_CHAR; i++) { // NOLINT
        node->children[i] = nullptr;
    }

    node->suffixLink = root;
    node->start      = start;
    node->end        = end;

    // suffixIndex will be set to -1 by default and
    // actual suffix index will be set later for leaves
    node->suffixIndex = -1;
    return node;
}

int edgeLength(SuffixTreeNode *n)
{
    if (n == root) return 0;
    return *(n->end) - (n->start) + 1;
}

int walkDown(SuffixTreeNode *currNode)
{
    // activePoint change for walk down. If activeLength is
    // greater than current edge length, set next interval
    // node as activeNode and adjust activeEdge and activeLength
    // accordingly to represent same activePoint
    if (activeLength >= edgeLength(currNode)) {
        activeEdge += edgeLength(currNode);
        activeLength -= edgeLength(currNode);
        activeNode = currNode;
        return 1;
    }
    return 0;
}

void extendSuffixTree(int pos)
{
    // Extension rule 1: If the path from the root labelled
    // S[j..i] ends at leaf edge (i.e. S[i] is last character
    // on leaf edge) then character S[i+1] is just added to the
    // end of the label on that leaf edge.
    leafEnd = pos;

    // Increment remainingSuffixCount to show that a new suffix
    // is yet to be added to the tree
    remainingSuffixCount++;

    // Set lastNewNode to nullptr while starting a new page
    // to show that there is no internal node waiting for
    // it's suffix link to be reset in current phase
    lastNewNode = nullptr;
    while (remainingSuffixCount > 0) {
        // active point change for activeLength zero
        if (activeLength == 0) activeEdge = pos;

        // If there is no outgoing edge starting with activeEdge
        // from activeNode
        if (activeNode->children[text[activeEdge]] == nullptr) {
            // Rule 2: New leaf edge gets created starting from an
            // existing node (activeNode)
            activeNode->children[text[activeEdge]] =
                    newNode(pos, &leafEnd);

            // If there is an internal node waiting for it's suffix
            // link to be set, point the suffix link from that last
            // internal node to current activeNode. Then set lastNewNode
            // tp nullptr to show that no more nodes are waiting for
            // suffix link reset
            if (lastNewNode != nullptr) {
                lastNewNode->suffixLink = activeNode;
                lastNewNode = nullptr;
            }
        }
            // If there is an outgoing edge starting with activeEdge from
            // activeNode
        else {
            // Get the next node at the end of edge starting with activeEdge
            SuffixTreeNode *next = activeNode->children[text[activeEdge]];

            if (walkDown(next)) { // Do walkdown
                // start from next node (the new activeNode
                continue;
            }
            // Rule 3 (current character being processes is already on edge
            if (text[next->start + activeLength] == text[pos]) {
                // If a newly created node is waiting for it's suffixLink
                // to be set, then set it to current activeNode
                if (lastNewNode != nullptr && activeNode != root) {
                    lastNewNode->suffixLink = activeNode;
                    lastNewNode = nullptr;
                }

                // active point change for extension rule 3: The activePoint
                // is incremented because we used rule 3
                activeLength++;

                // Stop all further processing in this phase and move to next
                // phase

                break;
            }

            // We will be here when activePoint is in middle of an edge being
            // traversed and current charactor is not on the edge. In this case
            // we add a new internal node and a new leaf edge going of of that
            // node. This is extension rule 2.
            splitEnd = new int;
            *splitEnd = next->start + activeLength - 1;

            // New internal node
            auto *split = newNode(next->start, splitEnd);
            activeNode->children[text[activeEdge]] = split;

            // New leaf coming out of internal node
            split->children[text[pos]] = newNode(pos, &leafEnd);
            next->start += activeLength;
            split->children[text[next->start]] = next;

            // If there is an internal node created in last extensions of same
            // phase which is still waiting for its suffix link to be set, do it
            if (lastNewNode != nullptr) {
                lastNewNode->suffixLink = split;
            }

            // Make the current newlt created internal node wait for it's suffix
            // link to be set.
            lastNewNode = split;
        }

        // A suffix got added in tree, decrement the count of suffixed yet to be added
        remainingSuffixCount--;
        // activePoint change for extension rule 2 c1
        if (activeNode == root && activeLength > 0) {
            activeLength--;
            activeEdge = pos - remainingSuffixCount + 1;
        } else if (activeNode != root) {
            activeNode = activeNode->suffixLink;
        }
    }
}

// DFS = Depth-first search. An algorithm for searching tree data structures.
// The algorithm starts at the root node and explores as far as possible along
// each branch before backtracking.
void setSuffixIndexByDFS(SuffixTreeNode *n, int labelHeight)
{
    if (n == nullptr) return;


    int leaf = 1;
    int i;
    for (i = 0; i < MAX_CHAR; i++) {
        if (n->children[i] != nullptr) {

            // Current node is not a leaf as it has outgoing edges from it
            leaf = 0;
            setSuffixIndexByDFS(n->children[i],
                                labelHeight + edgeLength(n->children[i]));
        }
    }
    if (leaf == 1) {
        for (i = n->start; i <= *(n->end); i++) {
            if (text[i] == '#') {
                n->end = new int;
                *(n->end) = i;
            }
        }
        n->suffixIndex = size - labelHeight;
    }
}

void freeSuffixTreeByPostOrder(SuffixTreeNode *n)
{
    int i;

    for (i = 0; i < MAX_CHAR; i++) {
        if (n->children[i] != nullptr) {
            delete (n->children[i]);
        }
    }

    if (n->suffixIndex == -1) {
        delete (n->end);
    }
}

// Build the suffix tree and print the edge labels along
// with suffixIndex. suffixIndex for leaf edges will be
// >= 0 and for non-leaf edges will be -1
void buildSuffixTree()
{
    size = (int) strlen(text);
    int i;
    rootEnd = new int;
    *rootEnd = 01;

    // Root is a specual node with stat and end indices as
    // -1 as it has no parent
    root = newNode(-1, rootEnd);
    auto new_root = new SuffixNode(-1, rootEnd, nullptr);

    activeNode = root; // First activeNode will be root

    for (i = 0; i < size; i++) {
        extendSuffixTree(i);
    }
    int labelHeight = 0;
    setSuffixIndexByDFS(root, labelHeight);
}

int doTraversal(SuffixTreeNode *n, int labelHeight, int *maxHeight, int *substringStartIndex)
{
    if (n == nullptr) {
        return 0;
    }
    int i   = 0;
    int ret = -1;
    if (n->suffixIndex < 0) { // If it is internal node
        for (i = 0; i < MAX_CHAR; i++) {
            if (n->children[i] != nullptr) {
                ret = doTraversal(n->children[i],
                                  labelHeight + edgeLength(n->children[i]),
                                  maxHeight, substringStartIndex);
                if (n->suffixIndex == -1) n->suffixIndex = ret;
                else if ((n->suffixIndex == -2 && ret == -3) ||
                         (n->suffixIndex == -3 && ret == -2) ||
                         n->suffixIndex == -4) {
                    n->suffixIndex = -4; // Mark node as XY
                    if (*maxHeight < labelHeight) {
                        *maxHeight           = labelHeight;
                        *substringStartIndex = *(n->end) - labelHeight + 1;
                    }
                }
            }
        }
    } else if (n->suffixIndex > -1 && n->suffixIndex < size1) {
        return -2; // Mark node as X
    } else if (n->suffixIndex >= size1) { //Suffix of Y
        return -3; // Mark node as Y
    }
    return n->suffixIndex;
}

std::string getLongestCommonSubstring()
{
    int maxHeight           = 0;
    int substringStartIndex = 0;

    doTraversal(root, 0, &maxHeight, &substringStartIndex);

    int  k;
    std::string result;

    for (k = 0; k < maxHeight; k++) {
        result += text[k + substringStartIndex];
    }

    return result;
}

/**
 * Entry Point.
 *
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char **argv)
{
    size1              = 24;
    strcpy(text, "Ich suche den Substring#Wir suchen den Substring$");
    buildSuffixTree();
    std::string result = getLongestCommonSubstring();
    std::cout << "Resultat: \"" << result << "\"";
    freeSuffixTreeByPostOrder(root);
}
