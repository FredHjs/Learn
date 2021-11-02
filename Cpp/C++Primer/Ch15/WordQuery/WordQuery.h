#ifndef WORDQUERY_H
#define WORDQUERY_H
#include <string>
#include <iostream>
#include "QueryBase.h"

class WordQuery: public QueryBase{
    friend class Query;

    private:
        std::string query_word;

        WordQuery(const std::string& s): query_word(s){std::cout << "WordQuery::WordQuery()\n";}

        QueryResult eval(const TextQuery& tq) const override {return tq.query(query_word);}

        std::string rep() const override {std::cout << "WordQuery::rep()\n"; return query_word;}
};

#endif