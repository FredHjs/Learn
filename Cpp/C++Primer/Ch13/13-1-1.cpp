#include <string>

class HasPtr{
    public:
    
        HasPtr(const std::string& s = std::string()): ps(new std::string(s)), i(0){}

        //A copy constructor must have a parameter which is the reference of its own type, and other parameters
        //must have default values.
        HasPtr(const HasPtr&);
    private:
        std::string* ps;
        int i;
};

HasPtr::HasPtr(const HasPtr& orig): ps(new std::string(*(orig.ps))), i(orig.i){}