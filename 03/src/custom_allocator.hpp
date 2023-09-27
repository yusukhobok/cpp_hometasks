#ifndef CUSTOM_ALLOCATOR_H
#define CUSTOM_ALLOCATOR_H

//#include <array>
//#include <cstddef>
//#include <utility>
//#include <memory>
//
//template<typename T, size_t max_count>
//struct CustomAllocator {
//private:
//    size_t allocated_count = 0;
//    std::byte storage[sizeof(T) * max_count];
//
//public:
//
//    using value_type = T;
//
//    using pointer = T *;
//    using const_pointer = const T *;
//    using reference = T &;
//    using const_reference = const T &;
//
//    template <typename U>
//    struct rebind {
//        using other = CustomAllocator<U, max_count>;
//    };
//
//    CustomAllocator() = default;
//    ~CustomAllocator() = default;
//
//    template <typename U>
//    CustomAllocator(const CustomAllocator<U, max_count> &) {
//    }
//
//    T* allocate(std::size_t n) {
//        if (this->allocated_count + n > max_count) {
//            throw std::bad_alloc();
//        }
//        auto p = &storage[allocated_count * sizeof(T)];
//        allocated_count += n;
//        if (!p) {
//            throw std::bad_alloc();
//        }
//        return reinterpret_cast<T*>(p);
//    }
//
//    void deallocate(T *p, std::size_t n) {
//    }
//
//    template <typename U, typename... Args>
//    void construct(U *p, Args &&...args) {
//        new (p) U(std::forward<Args>(args)...);
//    };
//
//    template <typename U>
//    void destroy(U *p) {
//        p->~U();
//    }
//};

#endif //CUSTOM_ALLOCATOR_H
