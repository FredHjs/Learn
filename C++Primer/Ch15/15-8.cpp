#include "BulkQuote.h"
#include <vector>
#include <iostream>
#include <memory>
using std::shared_ptr;
using std::cout;
using std::endl;
using std::vector;

int main(){
    //similar as before, no dynamic-binding will happen if we store explicit instances within a container
    vector<Quote> v1;
    auto b1 = BulkQuote("123456", 10, 10, 0.5);
    vector<shared_ptr<Quote>> v2;
    v1.push_back(b1);
    v2.push_back(std::make_shared<BulkQuote>("123456", 10, 10, 0.5));

    cout << v1.back().net_price(10) << endl;
    cout << v2.back()->net_price(10) << endl;
}