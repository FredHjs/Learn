#include "Query.h"
#include "QueryBase.h"
#include "NotQuery.h"
#include "QueryResult.h"
#include "TextQuery.h"
#include "OrQuery.h"
#include "AndQuery.h"
#include <iostream>
#include <fstream> 

int main(){
    Query q1("Mississippi"), q2("Alabama");
    std::ifstream file(".\\word_search_file.txt");
    TextQuery tq(file);
    auto result = (q1&q2).eval(tq);
    print(std::cout, result);
}