#include <iostream>
#include "vector.hpp"

int main() {
    vector* v = new vector(2);
    for (int i = 5; i < 10; i++) {
        v->push(i);
    }
    for (int i = 4; i >= 0; i --) {
        v->prepend(i);
    }
    v->insert(4, 1);
    int size = v->size();
    int val = v->pop();
    v->push(1);
    v->remove(1);
    for (int i = 0; i < v->size(); i++) {
        std::cout << (*v)[i] << std::endl;
    }


    delete(v);
}

