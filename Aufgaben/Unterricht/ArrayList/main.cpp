#include <iostream>

using namespace std;

class Container {
public:
    virtual void addElement(int value) = 0;

    virtual void insertElement(int value, int index) = 0;

    virtual int get(int index) = 0;

    virtual void set(int value, int index) = 0;

    virtual int searchElement(int value, int startPos = 0) = 0;

    virtual bool deleteElement(int index) = 0;

    virtual int length() = 0;

    virtual bool swap(int index1, int index2) = 0;

    virtual void print() = 0;
};

struct Element {
public:
    int     data;
    Element *next = nullptr;
};

class List : public Container {
private:
    Element *start;
    Element *end;
    int     size;
public:
    List();

    ~List();

    List(const List &obj);

    List operator=(const List &obj);

    virtual void addElement(int value);

    virtual void insertElement(int value, int index);

    virtual int get(int index);

    virtual void set(int value, int index);

    virtual int searchElement(int value, int startPos = 0);

    virtual bool deleteElement(int index);

    virtual int length();

    virtual bool swap(int index1, int index2);

    virtual void print();
};

List::List() : start(0), end(0), size(0)
{
}

List::~List()
{
}

List::List(const List &obj)
{
    // dueblin
}

List List::operator=(const List &obj)
{
}

void List::addElement(int value)
{
    Element *obj = new Element();
    obj->data = value;

    if (size == 0) {
        start = obj;
    } else {
        end->next = obj; // this->end->next = obj;
    }

    end = obj; // this->end = obj;
    size++; // this->size++;
}

void List::insertElement(int value, int index)
{
    // thommen
}

int List::get(int index)
{
    auto *tmp = this->start;

    for (int i = 0; i < size; ++i) {
        if (i == index) return tmp->data;
        tmp = tmp->next;
    }

    return -1;
}

void List::set(int value, int index)
{
    // genhart
}

int List::searchElement(int value, int startPos)
{
    // haenni
}

bool List::deleteElement(int index)
{
    // lang
}

int List::length()
{
    // herzig
}

bool List::swap(int index1, int index2)
{
    // bernstein
}

void List::print()
{
    Element *temp = start;
    cout << "start " << start << endl;
    cout << "end " << end << endl;
    for (int i = 0; i < size; i++) {
        cout << "***" << endl;
        cout << "My Address: " << temp << endl;
        cout << "Data: " << temp->data << endl;
        cout << "Next: " << temp->next << endl;
        temp = temp->next;
    }
    cout << endl;
}

class Array : public Container {
private:
    int *values;
    int maxSize;
    int currentSize;

    void checkSize();

public:
    Array();

    virtual void addElement(int value);

    virtual void insertElement(int value, int index);

    virtual int get(int index);

    virtual void set(int value, int index);

    virtual int searchElement(int value, int startPos = 0);

    virtual bool deleteElement(int index);

    virtual int length();

    virtual bool swap(int index1, int index2);

    virtual void print();
};

Array::Array()
{
    values      = new int[10];
    maxSize     = 10;
    currentSize = 0;
}

void Array::addElement(int value)
{
    currentSize++;
    checkSize();
    values[currentSize - 1] = value;
}

void Array::insertElement(int value, int index)
{
    currentSize++;
    checkSize();
    for (int i    = currentSize; i >= index; i--) {
        values[i] = values[i - 1];
    }
    values[index] = value;
}

int Array::get(int index)
{
    return values[index];
}

void Array::set(int value, int index)
{
    values[index] = value;
}

int Array::searchElement(int value, int startPos)
{
    for (int i = startPos; i < currentSize; i++) {
        if (values[i] == value) {
            return i;
        }
    }
    return -1;
}

bool Array::deleteElement(int index)
{
    if (index < 0 || index >= currentSize) {
        return false;
    }

    int      tmp = index;
    for (int i   = index; i < currentSize; i++) {
        values[i] = values[i + 1];
    }

    currentSize--;
    checkSize();
    return true;
}

int Array::length()
{
    return currentSize;
}

bool Array::swap(int index1, int index2)
{
    if (index1 >= currentSize || index2 >= currentSize || index1 < 0 || index2 < 0) {
        return false;
    }
    int tmp = values[index1];
    values[index1] = values[index2];
    values[index2] = tmp;
    return true;
}

void Array::print()
{
    for (int i = 0; i < currentSize; i++) {
        cout << values[i] << ",";
    }
    cout << " maxSize: " << maxSize << ", currentSize: " << currentSize << endl;
    cout << endl;
}

void Array::checkSize()
{
    bool check = false;
    if (currentSize > maxSize) {
        maxSize = maxSize * 2;
        check   = true;
    } else if (currentSize < maxSize / 4) {
        maxSize = maxSize / 2;
        check   = true;
    }

    if (check) {
        int      *tmp = new int[maxSize];
        for (int i    = 0; i < currentSize; i++) {
            tmp[i] = values[i];
        }
        delete values;
        values = tmp;
    }
}

int main(int argc, char **argv)
{
    List obj;
    obj.addElement(5);
    obj.addElement(7);
    obj.addElement(9);
    obj.print();

    std::cout << obj.get(2);

    return 0;
}

