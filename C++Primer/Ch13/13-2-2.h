#include <string>

class HasPtr{
    public:
        //when an object is instanciated, its reference count is 1. When count == 0, release the obj.
        HasPtr(const std::string& s = std::string()): ps(new std::string(s)), i(0), use(new std::size_t{1}){}

        HasPtr(const HasPtr&);

        HasPtr& operator=(const HasPtr& rhs);

        ~HasPtr();

    private:
        std::string* ps;

        int i;

        //reference count
        std::size_t* use;
};

//copy the ptrs directly, share of bottom values
HasPtr::HasPtr(const HasPtr& rhs): ps(rhs.ps), i(rhs.i), use(rhs.use) {++*use;}

HasPtr::~HasPtr(){
    --*use;
    if (*use == 0){
        delete ps;
        delete use;
    }
}

HasPtr& HasPtr::operator=(const HasPtr& rhs){
    ++*(rhs.use);
    --*(this->use);
    
    if (*(this-> use) == 0){
        delete use;
        delete ps;
    }

    use = rhs.use;
    ps = rhs.ps;
    i = rhs.i;
    return *this;
}