#include <stdbool.h>
#include <stdio.h>

typedef struct
{
    int* arr; // pointer to an array
    int size; // current number of elements stored in vector
    int capacity; // maximum number of elements that can be stored in vector
} vector;

vector* new_vector();
void destroy_vector(vector* v);
int size(vector* v);
int capacity(vector* v);
bool is_empty(vector* v);
int at(vector* v, int idx);
void* push(vector* v, int item);
void* prepend(vector* v, int item);
void print(vector* v);