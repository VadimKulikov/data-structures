export module utils;

export void* Memcpy(void* dst, void* src, int size) {
    char* d = (char*) dst;
    char* s = (char*) src;

    if (dst != nullptr && src != nullptr) {
         *(d)= *(s);
         *(d++);
         *(s++);
        --size;
    }
    return d;
}