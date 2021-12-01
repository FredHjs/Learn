#ifndef QUERY_H
#define QUERY_H

#include <memory>
#include "QueryBase.h"
#include "QueryResult.h"
#include "WordQuery.h"

class Query{
    friend Query operator~(const Query&);
    friend Query operator&(const Query&, const Query&);
    friend Query operator|(const Query&, const Query&);

    public:
        Query(const std::string& s): query(new WordQuery(s)){}
        QueryResult eval(const TextQuery& tq) const {return query->eval(tq);}
        std::string rep() const {return query->rep();}

    private:
        std::shared_ptr<QueryBase> query;
        Query(std::shared_ptr<QueryBase> q): query(q){}

};

#endif