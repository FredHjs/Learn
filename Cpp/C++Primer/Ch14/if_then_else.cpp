#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class if_then_else{
    public:
        int operator()(bool condition, int if_true, int if_false) const {
            if (condition){
                return if_true;
            }

            return if_false;
        }
};

class ReadString{
    public:
        std::string operator()(std::istream&);
;
    private:
        std::string line;
};

class Equal{
    public:
        Equal(int n): m(n){}
        bool operator()(int n) const;

    private:
        int m;
};

std::string ReadString::operator()(std::istream& is){
    std::getline(is, line);
    if (is.good()) return line;
    return std::string();
}

bool Equal::operator()(int n) const {
    if (n == m) return true;
    return false;
}

int main(){
    if_then_else test;
    ReadString read_string;
    Equal equal(1);
    std::vector<int> vi{0,1,1,2,3,4,1,2,3,5,1};
    std::replace_if(vi.begin(), vi.end(), equal, 100);
    
    std::cout << test(true, 1, 0) << std::endl;
    std::cout << test(false, 1, 0) << std::endl;

    std::cout << "enter the string to read: ";
    std::cout << read_string(std::cin) << std::endl;

    std::for_each(vi.cbegin(), vi.cend(), [](int n){std::cout << n << " ";});
}