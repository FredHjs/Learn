#include <bitset>
#include <iostream>
#include <string>
#include <sstream>
using std::bitset;

template <std::size_t N> struct Response{
    public:
        Response(const std::string& s): response(bitset<N>(s, 0, N)){}
        
        void record(std::size_t, bool);

        std::size_t score(const unsigned long long);

    private:
        bitset<N> response;
};

template <std::size_t N> void Response<N>::record(std::size_t question_num, bool answer){
    response.set(question_num, answer);
}

template <std::size_t N> std::size_t Response<N>::score(const unsigned long long answer_key){
    std::size_t ret = 0;
    bitset<N> b(answer_key);
    for (std::size_t i{0}; i < N; ++i){
        ret += (response[i] == b[i]);
    }

    return ret;
}

int main(){
    const unsigned long long answer_key = 0b1000101110;
    auto response_1 = Response<10>("1111111111"), response_2 = Response<10>("0000000000");
    std::cout << response_1.score(answer_key) << " " << response_2.score(answer_key);
    
}