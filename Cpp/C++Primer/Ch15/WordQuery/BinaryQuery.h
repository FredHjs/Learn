#ifndef BINARYQUERY_H
#define BINARYQUERY_H

#include "QueryBase.h"
#include "Query.h"
#include <string>

class BinaryQuery: public QueryBase{
    protected:
        std::string symbol;
        Query lhs, rhs;
        std::string rep() const override {std::cout << "BinaryQuery::rep()\n"; return "(" + lhs.rep() + ")"
                                        + symbol + "(" + rhs.rep() + ")";}

        BinaryQuery(const Query& lhs, const Query& rhs, const std::string& s): 
            lhs(lhs), rhs(rhs), symbol(s){std::cout << "BinaryQuery::BinaryQuery()\n";}
};

#endif