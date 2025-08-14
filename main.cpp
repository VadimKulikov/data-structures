#include <iostream>
import vector;

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
    std::cout << "Vector size is " << size << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << (*v)[i] << std::endl;
    }

    int val = v->pop();
    std::cout << "Last value is " << val << std::endl;

    delete(v);
}

