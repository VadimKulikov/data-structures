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

static void resize(vector *v, int new_capacity) {
    int* new_arr = malloc(new_capacity * sizeof(int));
    int* old_arr = v->arr;
    memcpy(new_arr, old_arr, v->size * sizeof(int));
    v->arr = new_arr;
    v->capacity = new_capacity;
    free(old_arr);
}

void print(vector* v) {
    if (v == NULL) {
        printf("NULL\n");
    } else {
        for (int i = 0; i < v->size; i++) {
            if (i != v->size -1) {
                printf("%d ", v->arr[i]);
            } else {
                printf("%d\n", v->arr[i]);
            }
        }
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

    if (v->size + 1 <= v->capacity) {
        v->arr[v->size] = item;
        v->size += 1;
    } else {
        resize(v, v->capacity * 2);
        v->arr[v->size] = item;
        v->size += 1;
    }
    return v;
}

void* prepend(vector* v, int item) {
    if (v == NULL) {
        return v;
    }

    if (v->size + 1 <= v->capacity) {
        for (int i = v->size - 1; i >= 0; i--) {
            v->arr[i + 1] = v->arr[i];
        }
        v->arr[0] = item;
    } else {
        resize(v, v->capacity * 2);
        for (int i = v->size - 1; i >= 0; i--) {
            v->arr[i + 1] = v->arr[i];
        }
        v->arr[0] = item;
    }
    v->size += 1;
    return v;
}