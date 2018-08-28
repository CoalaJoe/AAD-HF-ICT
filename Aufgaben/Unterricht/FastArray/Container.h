#ifndef FASTARRAY_CONTAINER_H
#define FASTARRAY_CONTAINER_H


class Container {
public:
    Container();

    virtual void addElement(int value) = 0;

    virtual void insertElement(int value, int index) = 0;

    virtual int get(int index) = 0;

    virtual int set(int index) = 0;

    virtual int searchElement(int value, int startPos = 0) = 0;

    virtual bool deleteElement(int pos) = 0;

    virtual int length() = 0;

    virtual bool swap(int index1, int index2) = 0;

    virtual void print() = 0;

};


#endif //FASTARRAY_CONTAINER_H
