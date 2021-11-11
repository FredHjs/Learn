#include <tuple>
#include <vector>
#include <string>
#include <utility>

int main(){
    std::tuple<int, int, int> ints{10, 20, 30};
    std::tuple<std::string, std::vector<std::string>, std::pair<std::string, int>> item;
}