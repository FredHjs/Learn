#ifndef ANDQUERY_H
#define ANDQUERY_H

#include "TextQuery.h"
#include "BinaryQuery.h"
#include <memory>

class AndQuery: public BinaryQuery{
    friend Query operator&(const Query&, const Query&);

    AndQuery(const Query& lhs, const Query& rhs):
        BinaryQuery(lhs, rhs, "&"){std::cout << "AndQuery::AndQuery()\n";}

    QueryResult eval(const TextQuery&) const override;
};

Query operator&(const Query& lhs, const Query& rhs){
    return std::shared_ptr<QueryBase>(new AndQuery(lhs, rhs));
}

#endif