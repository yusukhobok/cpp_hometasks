#include <memory>
#include <string>

template <typename T, int Size = 10>
class CustomAllocator {
public:
    using value_type = T;
    int counter = 0;
    T* allocated = nullptr;

    template<typename U>
    struct rebind {
        using other = CustomAllocator<U, Size>;
    };

    CustomAllocator() {
        allocated = nullptr;
        counter = 0;
    }

    template<typename U>
    explicit CustomAllocator(const CustomAllocator<U, Size>& allocator) {
        allocated = reinterpret_cast<T*>(allocator.allocated);
        counter = allocator.counter;
    }

    T* allocate(size_t sz) {
        if (counter >= Size) {
            throw std::bad_alloc();
        }
        if (!counter) {
            auto ptr = std::malloc(sz * Size * sizeof(T));
            if (!ptr) {
                throw std::bad_alloc();
            }
            allocated = reinterpret_cast<T*>(ptr);
        }
        ++counter;
        return allocated + counter - 1;
    }

    void deallocate(T* p, size_t sz) {
        if (Size == 1) {
            std::free(allocated);
            return;
        }
        if (counter == 1) {
            std::free(allocated);
            allocated = nullptr;
            return;
        }
        --counter;
    }

    template<typename U, typename ...Args>
    void construct(U *p, Args &&...args) {
        new (p) U(std::forward<Args>(args)...);
    }

    void destroy(T* p) {
        p->~T();
    }
    
    template<typename U, int SizeU>
    bool operator==(const CustomAllocator<U, SizeU>& other) const noexcept
    {
        return this == &other;
    }

    template<typename U, int SizeU>
    bool operator!=(const CustomAllocator<U, SizeU>& other) const noexcept
    {
        return this != &other;
    }
};