#include <tuple>
#include <vector>
#include <string>
#include <utility>
#include <iostream>

int main(){
    std::tuple<int, int, int> ints{10, 20, 30};
    std::tuple<std::string, std::vector<std::string>, std::pair<std::string, int>> item;
    auto i = std::get<0>(ints);
    std::get<2>(item) = {"111", 1};

    std::cout << i << " " << std::get<2>(item).second;
}