#include <vector>


template <typename T, typename Alloc = std::allocator<T>>
class CustomVector {
private:
    T* arr;
    size_t sz;
    size_t cap;
    Alloc alloc;
    using AllocTraits = std::allocator_traits<Alloc>;

public:
    explicit CustomVector() {
        sz = 0;
        cap = 10;
        arr = alloc.allocate(cap);
    }

    size_t size() const {
        return this->sz;
    }
    void resize(size_t newsize);

    size_t capacity() const {
        return this->cap;
    }
    void reserve(size_t newcap) {
        if (newcap > this->sz) {
            return;
        }
        if (newcap <= this->cap) {
            return;
        }
        T* newarr = alloc.allocate(newcap);
        for (size_t i = 0; i < this->sz; ++i) {
            try {
                new(newarr + i) T(arr[i]);
                AllocTraits::construct(alloc, newarr+i, arr[i]);
            } catch (...) {
                for (size_t j = 0; j < i; ++j) {
                    AllocTraits::destroy(alloc, newarr + i);
                }
                alloc.deallocate(newarr, newcap);
                throw;
            }
        }
        for (size_t i = 0; i < sz; ++i) {
            AllocTraits::destroy(alloc, this->arr + i);
        }
        alloc.deallocate(this->arr, this->cap);
        this->cap = newcap;
        this->arr = newarr;
    }

    void push_back(const T& value) {
        if (this->sz >= this->cap) {
            this->reserve(this->cap * 2);
        }
        new(this->arr + this->sz) T(value);
        ++(this->sz);
    }

    void pop_back() {
        --sz;
        (arr+sz)->~T();
    }

    T &operator[](size_t index) {
        return *(this->arr + index);
    }
};
