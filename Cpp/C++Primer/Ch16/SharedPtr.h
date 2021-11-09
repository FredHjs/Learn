#ifndef SHAREDPTR_H
#define SHAREDPTR_H
#include <functional>
#include <memory>
#include <utility>

template<typename T> class SharedPtr{
    public:
        SharedPtr(T* _p = nullptr, std::function<void (T*)> _del = 
            std::function<void (T*)>([](T* p) -> void {delete p;})): ptr(_p), del(_del), 
            ref_count(new std::size_t(_p == nullptr ? 0 : 1)){}
        
        ~SharedPtr();

        SharedPtr(const SharedPtr&);

        SharedPtr(SharedPtr&& rhs) noexcept{
            swap(rhs);
        }

        void swap(SharedPtr& sp){
            std::swap(this->ptr, sp.ptr);
            std::swap(this->ref_count, sp.ref_count);
            std::swap(this->del, sp.del);
        }

        void reset(T* _p = nullptr, std::function<void (T*)> _del = 
            std::function<void (T*)>([](T* p) -> void {delete p;})){
                auto tmp = SharedPtr(_p, _del);
                swap(tmp);
        }

        T* get() const {return ptr;}

        T& operator*() const {return *(get());}

        T* operator->() const {return get();}

        std::size_t used_count() const {return *ref_count;}

        explicit operator bool() const {return bool(ptr);}
    
    private:
        T* ptr;
        std::size_t* ref_count;
        std::function<void (T*)> del = std::function<void (T*)>([](T* p) -> void {delete p;});
};

template<typename T> SharedPtr<T>::~SharedPtr(){
    if (ptr){
        if (*ref_count == 1){
            del(ptr);
            delete ref_count;
            
        }else{
            --(*ref_count);
        }

        ref_count = nullptr;
        ptr = nullptr;
    }
}

template<typename T> SharedPtr<T>::SharedPtr(const SharedPtr& rhs): ptr(rhs.ptr), del(rhs.del), 
            ref_count(rhs.ref_count){++*ref_count;}


template<typename Y, typename...Args> SharedPtr<Y> MakeShared(Args&&...args){
    std::allocator<Y> alloc;
    auto made_ptr = alloc.allocate(1);
    alloc.construct(made_ptr, std::forward<Args>(args)...);
    return SharedPtr<Y>(made_ptr);
}
#endif