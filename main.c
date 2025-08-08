#include "vector.h"

int main() {
    vector* v = new_vector();
    for (int i = 0; i < 10; i++) {
        push(v, i);
    }
    printf("%d\n", at(v, 1));
    printf("%s\n", is_empty(v) ? "true" : "false");
    destroy_vector(v);

    return 0;
}