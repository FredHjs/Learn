#ifndef ANDQUERY_H
#define ANDQUERY_H

#include "TextQuery.h"
#include "BinaryQuery.h"
#include <memory>
#include <set>
#include <algorithm>

class AndQuery: public BinaryQuery{
    friend Query operator&(const Query&, const Query&);

    AndQuery(const Query& lhs, const Query& rhs):
        BinaryQuery(lhs, rhs, "&"){}

    QueryResult eval(const TextQuery&) const override;
};

Query operator&(const Query& lhs, const Query& rhs){
    return std::shared_ptr<QueryBase>(new AndQuery(lhs, rhs));
}

QueryResult AndQuery::eval(const TextQuery& tq) const {
    auto l_result = lhs.eval(tq), r_result = rhs.eval(tq);

    auto lines = std::make_shared<std::set<std::size_t>>();
    std::set_intersection(l_result.begin(), l_result.end(), r_result.begin(), 
        r_result.end(), std::inserter(*lines, lines->begin()));

    return QueryResult(l_result.get_file(), lines, rep());
}

#endif