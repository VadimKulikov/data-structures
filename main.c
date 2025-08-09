#include "vector.h"
#include <assert.h>

void test_vector() {
    vector* v = new_vector();
    assert(v != NULL);

    for (int i = 0; i < 10; i++) {
        push(v, i);
    }

    assert(v->size == 10);
    assert(!is_empty(v));
    print(v);

    for (int i = 10; i < 20; i++) {
        prepend(v, i);
    }
    assert(v->size == 20);

    print(v);
    destroy_vector(v);
}

int main() {
    test_vector();
    return 0;
}