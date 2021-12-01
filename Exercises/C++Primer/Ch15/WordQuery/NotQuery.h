#ifndef NOTQUERY_H
#define NOTQUERY_H
#include "QueryBase.h"
#include "Query.h"
#include <memory>

class NotQuery: public QueryBase{
    friend Query operator~(const Query&);

    private:
        Query query;
        QueryResult eval(const TextQuery&) const override;
        std::string rep() const override {return "~(" + query.rep() + ")";}
        NotQuery(const Query& q): query(q){}
};

Query operator~(const Query& q){
    return std::shared_ptr<QueryBase>(new NotQuery(q));
}

QueryResult NotQuery::eval(const TextQuery& tq) const {
    auto query_result = query.eval(tq);

    auto lines = std::make_shared<set<line_num>>();
    auto beg = query_result.begin(), end = query_result.end();
    for (std::size_t n = 1; n < query_result.get_file()->size(); ++n){
        if (beg == end || *beg != n)
            lines->insert(n);
        else if (beg != end)
            ++beg;

    }
    return QueryResult(query_result.get_file(), lines, rep());
}

#endif