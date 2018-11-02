#include <iostream>
#include <vector>

int ggt(int a, int b)
{
    if (a == b) {
        return a;
    }
    if (a > b) {
        a -= b;
    } else {
        b -= a;
    }

    return ggt(a, b);
}

class Component {
private :
    int         id;
    std::string name;
    double      price;
public :
    // Testing purposes
    void setId(int id)
    {
        this->id = id;
    }

    int getId()
    { return id; }

    std::string getName()
    { return name; }

    double getPrice()
    { return price; }

    static Component **removeComponent(int id, Component **array, int &size);
};

Component **Component::removeComponent(int id, Component **array, int &size)
{
    Component **result = new Component *[size];

    int      counter = 0;
    for (int i       = 0; i < size; ++i) {
        auto component = array[i];
        if (id != component->getId()) {
            result[counter] = component;
            ++counter;
        }
    }
    size = counter;

    return result;
};


int main()
{
    // Aufgabe 1.
    std::cout << ggt(5, 10) << std::endl;

    // Aufgabe 2.
    int  size         = 2;
    auto **components = new Component *[size];
    auto *component1  = new Component();
    component1->setId(1);
    auto *component2 = new Component();
    component2->setId(2);
    components[0] = component1;
    components[1] = component2;
    for (int i; i < size; ++i) {
        std::cout << components[i]->getId() << "\n";
    }
    components = Component::removeComponent(1, components, size);
    for (int i; i < size; ++i) {
        std::cout << components[i]->getId() << "\n";
    }

    // Aufgabe 3.
    // Siehe Unten

    // Aufgabe 4.
    // Von Hand gezeichnet. Left, Right, Node

    // Aufgabe 5.
    // Nein. Die Klasse Vektor implementiert den +operator nicht.

    return 0;
}

class TreeElement {
protected:
    int                        id;
    int                        value;
    std::vector<TreeElement *> children;
public:
    int getId() const
    {
        return id;
    }

    void setId(int id)
    {
        TreeElement::id = id;
    }

    int getValue() const
    {
        return value;
    }

    void setValue(int value)
    {
        TreeElement::value = value;
    }

    const std::vector<TreeElement *> &getChildren() const
    {
        return children;
    }

    void setChildren(const std::vector<TreeElement *> &children)
    {
        TreeElement::children = children;
    }
};


class Tree {
protected:
    TreeElement *rootNode;

    TreeElement *getNode(int id, TreeElement *startNode);
};

TreeElement *Tree::getNode(int id, TreeElement *startNode)
{
    if (id == startNode->getId()) {
        return startNode;
    }

    for (const auto &node : startNode->getChildren()) {
        return this->getNode(id, node);
    }


    return nullptr;
}
