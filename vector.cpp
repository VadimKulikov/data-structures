export module vector;
import utils;

export class vector {
    public:
        vector(int s);
        ~vector();
        int size();
        int& operator[](int i);
        void push(int item);
        void prepend(int item);
    private:
        int sz;
        int* elem;
        int cap;
        void resize(int new_cap);
};

vector::vector(int s): elem {new int[s]}, sz{0}, cap{s} {}

vector::~vector() {
    delete[] elem;
}

int vector::size() { return sz; }

int& vector::operator[](int i) { return elem[i]; }

void vector::resize(int new_cap) {
    int* new_arr = new int[new_cap];
    Memcpy(new_arr, elem, sz * sizeof(int));
    delete[] elem;
    elem = new_arr;
    cap = new_cap;
}

void vector::push(int item) {
    if (sz + 1 <= cap) {
        elem[sz] = item;
        sz += 1;
    } else {
        resize(cap * 2);
        elem[sz] = item;
        sz += 1;
    }
}

void vector::prepend(int item) {
    if (sz + 1 <= cap) {
        for (int i = sz - 1; i >= 0; i--) {
            elem[i + 1] = elem[i];
        }
        elem[0] = item;
    } else {
        resize(cap * 2);
        for (int i = sz - 1; i >= 0; i--) {
            elem[i + 1] = elem[i];
        }
        elem[0] = item;
    }
    sz += 1;
}