#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

struct Node {
public:
    int  data;
    Node *left  = nullptr;
    Node *right = nullptr;
};

class Tree {
private:
    Node *root = nullptr;

    void insert(int value, Node *n);

    void preorder(Node *n);

    int height(Node *n);

    bool getPath(int sum, vector<int> &path, Node *n);

public:
    void insert(int value);

    void preorder();


    int height();

    vector<int> getPath(int sum);
};

int Tree::height(Node *n)
{
    if (n == nullptr) {
        return 0;
    }
    int lHeight = 1 + height(n->left);
    int rHeight = 1 + height(n->right);

    return (rHeight > lHeight) ? rHeight : lHeight;
}

int Tree::height()
{
    return this->height(this->root);
}

int calcLeft(Node *n, int sum)
{
    if (n == nullptr) {
        return sum;
    }

    return calcLeft(n->left, sum);
}

int calcRight(Node *n, int sum)
{
    if (n == nullptr) {
        return sum;
    }

    return calcRight(n->left, sum);
}

vector<int> recusiveGetPath(Node *n, vector<int> &calculatedSum, int iSum)
{
    return calculatedSum;
}

bool Tree::getPath(int sum, vector<int> &path, Node *n)
{
    if (n == nullptr) {
        return false;
    }

    path.push_back(n->data);
    if (n->left == nullptr && n->right == nullptr) {
        int       lSum = 0;
        for (auto i : path) {
            std::cout << i << ",";
            lSum += i;
        }
        if (sum == lSum) {
            return true;
        }
    } else {
        if (getPath(sum, path, n->left)) return true;
        if (getPath(sum, path, n->right)) return true;
    }
    path.pop_back();

    return false;
}

vector<int> Tree::getPath(int sum)
{
    vector<int> path;
    if (!this->getPath(sum, path, this->root)) {
        // Not found
    }

    return path;
}

void Tree::preorder()
{
    preorder(root);
}

void Tree::preorder(Node *n)
{
    if (n == nullptr) return;
    cout << n->data << endl;
    preorder(n->left);
    preorder(n->right);
}

void Tree::insert(int value, Node *n)
{
    if (n->data > value) {
        // insert left
        if (n->left == nullptr) {
            n->left       = new Node();
            n->left->data = value;
        } else {
            insert(value, n->left);
        }
    } else {
        // insert right
        if (n->right == nullptr) {
            n->right       = new Node();
            n->right->data = value;
        } else {
            insert(value, n->right);
        }
    }
}

void Tree::insert(int value)
{
    if (root == nullptr) {
        root = new Node();
        root->data = value;
        return;
    }
    insert(value, root);
}

int main(int argc, char **argv)
{

    Tree     t;
    /*for (int i=0; i<14; i++) {
      int v = rand() % 1000;
      t.insert(v);
      cout << v << ",";
    }
    cout << endl;*/
    int      values[] = {8, 4, 10, 1, 6, 14, 7, 13};
    int      size     = 8;
    for (int i        = 0; i < size; i++) {
        t.insert(values[i]);
    }
    //t.preorder();
    std::cout << t.height();

    return 0;
}
