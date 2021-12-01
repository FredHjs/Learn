#include <regex>
#include <string>
#include <iostream>
int main(){
    std::string pattern = "(\\d{5})(\\-)?(\\d{4})?";
    std::regex r(pattern);
    std::string codes;
    std::cout << "enter some postal codes for test: ";
    std::getline(std::cin, codes);

    for (std::sregex_iterator it(codes.cbegin(), codes.cend(), r), it_end; it != it_end; ++it){
        std::cout << it->str() << std::endl;
    }
}