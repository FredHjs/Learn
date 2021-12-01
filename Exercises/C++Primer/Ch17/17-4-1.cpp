#include <random>
#include <iostream>

unsigned int rand_int(const unsigned int& min = 0, const unsigned int& max = UINT_MAX, 
    const unsigned int& seed = 0){
        /* the random engine and distribution class are declared static to generate different numbers 
        between each function call of rand_int */
        static std::default_random_engine e(seed);
        static std::uniform_int_distribution<unsigned int> u(min, max);
        return u(e);
}

int main(){
    for (int i = 0; i < 10; ++i){
        std::cout << rand_int(0, 100, i * i) << " ";
    }
}