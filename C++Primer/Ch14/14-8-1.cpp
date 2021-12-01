#include <string>
#include <vector>
#include <iostream>
class Test{
    public:
        Test(std::size_t l, std::size_t u): lower(l), upper(u){}
        bool operator()(const std::string&) const;

    private:
        std::size_t upper, lower;
};

bool Test::operator()(const std::string& s) const {
    return s.length() >= lower && s.length() <= upper;
}

int main(){
    Test shorter_than_9(0, 9);
    Test longer_than_10(10, UINT64_MAX);
    std::size_t shorter_than_9_count = 0, longer_than_10_count = 0;
    std::vector<std::string> vs = {"", "12345", "123456789", "1234567890", "12345678900000"};

    for(auto& s : vs){
        if (shorter_than_9(s)) ++shorter_than_9_count;
        else if(longer_than_10(s)) ++longer_than_10_count;
    }

    std::cout << shorter_than_9_count << " " << longer_than_10_count;
}