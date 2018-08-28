#ifndef FASTARRAY_ARRAYCONTAINER_H
#define FASTARRAY_ARRAYCONTAINER_H


#include "Container.h"

class ArrayContainer : public Container {
public:
    void addElement(int value) override;

    void insertElement(int value, int index) override;

    int get(int index) override;

    int set(int index) override;

    int searchElement(int value, int startPos) override;

    bool deleteElement(int pos) override;

    int length() override;

    bool swap(int index1, int index2) override;

    void print() override;
};


#endif //FASTARRAY_ARRAYCONTAINER_H
