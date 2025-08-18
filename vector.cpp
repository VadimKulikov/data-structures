#include "vector.hpp"

vector::vector(int s): elem { std::make_unique<int[]>(sz) }, sz{0}, cap{s} {}

int vector::size() { return sz; }

int& vector::operator[](int i) { return elem[i]; }

void vector::resize(int new_cap) {
    spdlog::info("Resizing to capacity {}", new_cap);
    std::unique_ptr<int[]> new_arr = std::make_unique<int[]>(new_cap);
    for (int i = 0; i < sz; i++) {
        new_arr[i] = elem[i];
    }
    elem = std::move(new_arr);
    cap = new_cap;
}

void vector::push(int item) {
    spdlog::info("Appending item {}", item);
    if (sz + 1 > cap) {
        resize(cap * 2);
    }
    elem[sz] = item;
    sz += 1;
}

void vector::prepend(int item) {
    spdlog::info("Prepending item {}", item);
    if (sz + 1 > cap) {
        resize(cap * 2);
    }
    for (int i = sz - 1; i >= 0; i--) {
        elem[i + 1] = elem[i];
    }
    elem[0] = item;
    sz += 1;
}

void vector::insert(int idx, int item) {
    spdlog::info("Inserting item {} at index {}", item, idx);
    if (sz + 1 > cap) {
        resize(cap * 2);
    }

    if (idx >= sz) {
        return this->push(item);
    } else if (idx < 0) {
        return this->prepend(item);
    } else {
        for (int i = sz - 1; i >= idx; i--) {
            elem[i + 1] = elem[i];
        }
        elem[idx] = item;
        sz += 1;
    }
}

int vector::pop() {
    spdlog::info("Removing item at the end");
    if (sz < 1) {
        throw -1;
    }

    sz -= 1;
    int val = elem[sz];
    if (sz <= cap / 4) {
        resize(cap / 2);
    }

    return val;
}

void vector::del(int idx) {
    spdlog::info("Removing elemnt at index {}", idx);
    if (idx < 0 || idx >= sz) {
        return;
    }

    for (int i = idx + 1; i < sz; i++) {
        elem[i-1] = elem[i]; // shift elements to the left, overriding removed element
    }
    sz -= 1;
    if (sz <= cap / 4) {
        resize(cap / 2);
    }
}

void vector::remove(int item) {
    spdlog::info("Removing all occurances of item {}", item);
    for (int i = 0; i < sz; i++) {
        if (elem[i] == item) {
            del(i);
        }
    }
}

int vector::find(int item) {
    for (int i = 0; i < sz; i++) {
        if (elem[i] = item) {
            spdlog::info("Found item {} at index {}", item, i);
            return i;
        }
    }
    spdlog::info("Did not find element {}", item);
    return -1;
}