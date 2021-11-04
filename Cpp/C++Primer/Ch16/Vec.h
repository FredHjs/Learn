#ifndef VEC_H
#define VEC_H
#include <string>
#include <utility>
#include <memory>
#include <initializer_list>
#include <stdexcept>

template <typename T>
class Vec{
    public:
        Vec(): elements(nullptr), first_free(nullptr), cap(nullptr){}

        Vec(std::initializer_list<T>);

        Vec(const Vec&);

        Vec(Vec&&) noexcept;

        Vec& operator=(Vec&&);

        Vec& operator=(const Vec& rhs);

        ~Vec(){free();}

        T& operator[](std::size_t);

        const T& operator[](std::size_t) const;

        void push_back(const T&);

        std::size_t size() const {return first_free - elements;}

        std::size_t capacity() const {return cap - elements;}

        T* begin() const {return elements;}

        T* end() const {return first_free;}

        void reserve(std::size_t);

        void resize(std::size_t, const string&);

    private:
        static std::allocator<T> alloc;

        T* elements;

        T* first_free;

        T* cap;

        std::pair<T*, T*> alloc_n_copy(const T*, const T*);

        void alloc_n_move(std::size_t new_cap);

        void check_cap_alloc(){if (first_free == cap) reallocate();}

        void reallocate();

        void free();
};

template<typename T>
std::pair<T*, T*> Vec<T>::alloc_n_copy(const T* beg, const T* end){
    auto new_data = alloc.allocate(end - beg);
    return {new_data, std::uninitialized_copy(beg, end, new_data)};
}

template<typename T>
void Vec<T>::alloc_n_move(std::size_t new_cap){
    if (new_cap < size())
        throw std::out_of_range("new capacity too small");

    auto new_elem = alloc.allocate(new_cap);
    auto new_capacity = new_elem + new_cap;
    auto new_first_free = new_elem;

    for (auto i = elements; i != first_free; ++i){
        alloc.construct(first_free++, std::move(*i));
    }

    free();

    elements = new_elem;
    first_free = new_first_free;
    cap = new_capacity;
}


template<typename T> void Vec<T>::free(){
    if (elements){
        auto i = elements;
        while (i != first_free){
            alloc.destroy(i++);
        }

        alloc.deallocate(elements, first_free);

        elements = first_free = cap = nullptr;
    }
}

template<typename T> const T& Vec<T>::operator[](std::size_t index) const {
    if (first_free - elements > index)
        return elements[index];
    
    throw std::out_of_range("index beyond range");
}

template<typename T> Vec<T>::Vec(std::initializer_list<T> li){
    auto data_pair = alloc_n_copy(li.begin(), li.end());
    elements = data_pair.first;
    first_free = cap = data_pair.second;
}
#endif