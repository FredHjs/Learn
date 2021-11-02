#include "Query.h"
#include "QueryBase.h"
#include "NotQuery.h"
#include "QueryResult.h"
#include "TextQuery.h"
#include <iostream>
#include <fstream> 

int main(){
    Query q("dream");
    std::ifstream file(".\\word_search_file.txt");
    TextQuery tq(file);
    auto result = (~q).eval(tq);
    print(std::cout, result);
}