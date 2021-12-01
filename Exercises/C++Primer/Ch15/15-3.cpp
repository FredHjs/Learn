#include "Quote.h"
#include "BulkQuote.h"
#include "LimitQuote.h"
#include <iostream>

int main(){
    Quote* pQ = new Quote("Quote_ISBN", 1);
    pQ->debug();
    std::cout << std::endl;
    delete pQ;

    //A reference or pointer of base class can be used on instances of derived classes, 
    //and which virtual function to call is determined at run-time, according to the dynamic-type that
    //this pointer (reference) points to;
    pQ = new BulkQuote("BulkQuote_ISBN", 10, 10, 0.5);
    pQ->debug();
    std::cout << std::endl;
    delete pQ;

    pQ = new LimitQuote("LimitQuote_ISBN", 10, 100, 100, 0.5);
    pQ->debug();
    std::cout << std::endl;
    delete pQ;

    pQ = nullptr;
}