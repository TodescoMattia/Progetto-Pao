#ifndef DEEPPTR_H
#define DEEPPTR_H


template<class T>
class DeepPtr {
private:
    T* ptr;

public:
    DeepPtr(): ptr(nullptr) {}
    DeepPtr(const DeepPtr& other) : ptr(nullptr){ *this = other; }
    ~DeepPtr() { delete ptr; }
    DeepPtr& operator=(const DeepPtr& other) {
        if(this != &other) {
            if(ptr != nullptr) delete ptr;
            ptr = other.ptr != nullptr ? other.ptr->clone() : nullptr;
        }
        return *this;
    }

    DeepPtr(const T& t): ptr(t.clone()){}

    T* operator->() { return ptr; }
    const T* operator->() const { return ptr; }
    T& operator*() { return *ptr; }
    const T& operator*() const { return *ptr; }
    bool operator== (const DeepPtr& other) const{
        return ptr==other.ptr;
    }
};
#endif // DEEPPTR_H
