#include <string>
#include <iostream>

class HasPtr{
    friend void swap(HasPtr& lhs, HasPtr& rhs);
    public:
        HasPtr(const std::string& s = std::string(), const int i = 0): ps(new std::string(s)), i(i){}

        //A copy constructor must have a parameter which is the reference of its own type, and other parameters
        //must have default values.
        HasPtr(const HasPtr&);
        
        HasPtr& operator=(const HasPtr& rhs);
        bool operator<(const HasPtr& rhs) const {return *ps < *(rhs.ps);}
        
        ~HasPtr();
        const std::string get_s() const {return *ps;} 
        const int get_i() const {return i;}
        void inline swap(HasPtr&);
    private:
        std::string* ps;
        int i;
};

HasPtr::HasPtr(const HasPtr& orig): ps(new std::string(*(orig.ps))), i(orig.i){}

HasPtr& HasPtr::operator=(const HasPtr& rhs){
    //make sure that an instance can copy itself
    std::string* newp = new std::string(*(rhs.ps));
    delete this->ps;
    ps = newp;
    this-> i = rhs.i;
    return *this;
}

HasPtr::~HasPtr(){
    delete ps;
    ps = nullptr;
}

void inline HasPtr::swap(HasPtr& rhs){
    using std::swap;
    std::cout << "calling swap(HasPtr&, HasPtr&)" << std::endl;
    swap(ps, rhs.ps);
    swap(i, rhs.i);
}

void swap(HasPtr& lhs, HasPtr& rhs){
    lhs.swap(rhs);
}