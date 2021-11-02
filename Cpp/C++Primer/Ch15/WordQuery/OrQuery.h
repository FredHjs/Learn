#ifndef ORQUERY_H
#define ORQUERY_H

#include "TextQuery.h"
#include "BinaryQuery.h"
#include <memory>
#include <set>

class OrQuery: public BinaryQuery{
    friend Query operator|(const Query&, const Query&);

    OrQuery(const Query& lhs, const Query& rhs):
        BinaryQuery(lhs, rhs, "|"){}

    QueryResult eval(const TextQuery&) const override;
};

Query operator|(const Query& lhs, const Query& rhs){
    return std::shared_ptr<QueryBase>(new OrQuery(lhs, rhs));
}

QueryResult OrQuery::eval(const TextQuery& tq) const {
    auto l_result = lhs.eval(tq), r_result = rhs.eval(tq);

    //union of the two sets;
    auto lines = std::make_shared<std::set<std::size_t>>(l_result.begin(), l_result.end());
    lines->insert(r_result.begin(), r_result.end());

    return QueryResult(l_result.get_file(), lines, rep());
}

#endif