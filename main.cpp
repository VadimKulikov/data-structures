#include <iostream>
import vector;

int main() {
    vector* v = new vector(2);
    for (int i = 5; i < 10; i++) {
        v->push(i);
    }
    for (int i = 0; i < 5; i ++) {
        v->prepend(i);
    }
    std::cout << "Vector size is " << v->size() << std::endl;
    delete(v);
}

