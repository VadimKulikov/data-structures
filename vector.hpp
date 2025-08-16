#include <memory>
#include "spdlog/spdlog.h"

class vector {
    public:
        vector(int s);
        int size();
        int& operator[](int i);
        void push(int item);
        void prepend(int item);
        void insert(int idx, int item);
        int pop();
        void del(int idx);
        void remove(int item);
    private:
        int sz;
        std::unique_ptr<int[]> elem;
        int cap;
        void resize(int new_cap);
};