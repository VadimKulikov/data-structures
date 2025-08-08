#include "vector.h"

vector* new_vector() {
    vector* v = (vector*) malloc(sizeof(vector));
    v->arr = (int*) malloc(2 * sizeof(int));
    v->size = 0;
    v->capacity = 2;
    return v;
}

void destroy_vector(vector* v) {
    if (v != NULL) {
        free(v->arr);
        free(v);
    }
}

int size(vector* v) {
    if (v != NULL) {
        return v->size;
    } else {
        return -1;
    }
}

int capacity(vector* v) {
    if (v != NULL) {
        return v->capacity;
    } else {
        return -1;
    }
}

bool is_empty(vector* v) {
    if (v != NULL) {
        return v->size == 0;
    } else {
        return true;
    }
}

int at(vector* v, int idx) {
    return *(v->arr + idx);
}

void* push(vector* v, int item) {
    if (v == NULL) {
        return v;
    }

    if (v->size < v->capacity) {
        v->arr[v->size] = item;
        v->size += 1;
    } else {
        int new_cap = v->capacity * 2;
        int* new_arr = malloc(new_cap * sizeof(int));
        int* old_arr = v->arr;
        v->arr = memcpy(new_arr, old_arr, v->size);
        v->arr[v->size] = item;
        v->size += 1;
        v->capacity = new_cap;
        free(old_arr);
    }
}