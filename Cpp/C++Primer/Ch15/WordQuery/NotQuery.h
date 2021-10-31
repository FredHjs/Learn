#ifndef NOTQUERY_H
#define NOTQUERY_H
#include "QueryBase.h"
#include "Query.h"
#include <memory>

class NotQuery: public QueryBase{
    friend Query operator~(const Query&);

    private:
        Query query;
        //QueryResult eval(const TextQuery&) const override;
        std::string rep() const override {std::cout << "NotQuery::rep()\n";return "(" + query.rep() + ")";}
        NotQuery(const Query& q): query(q){std::cout << "NotQuery::NotQuery()\n";}
};

Query operator~(const Query& q){
    return std::shared_ptr<QueryBase>(new NotQuery(q));
}

#endif