#include <iostream>
int main(){
    int curr_val{0}, val{0};

    if (std::cin >> curr_val){
        int count{1};
        while (std::cin >> val){
            if (val == curr_val){
                count++;
            }else{
                std::cout << curr_val << " occours "
                        << count << " times " << std::endl;
                curr_val = val;
                count = 1;
            }
        }
        std::cout << curr_val << " occours "
                << count << " times " << std::endl;
    }
    return 0;
}