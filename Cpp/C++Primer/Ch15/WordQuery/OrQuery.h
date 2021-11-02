#ifndef ORQUERY_H
#define ORQUERY_H

#include "TextQuery.h"
#include "BinaryQuery.h"
#include <memory>

class OrQuery: public BinaryQuery{
    friend Query operator|(const Query&, const Query&);

    OrQuery(const Query& lhs, const Query& rhs):
        BinaryQuery(lhs, rhs, "|"){std::cout << "OrQuery::OrQuery()\n";}

    QueryResult eval(const TextQuery&) const override;
};

Query operator|(const Query& lhs, const Query& rhs){
    return std::shared_ptr<QueryBase>(new OrQuery(lhs, rhs));
}

#endif