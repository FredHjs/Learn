#ifndef QUERYBASE_H
#define QUERYBASE_H

#include <vector>
#include <string>
#include <iostream>
#include "TextQuery.h"
#include "Query.h"

class QueryBase{
    friend class Query;

    protected:
        using line_num = std::vector<std::string>::size_type;
        virtual ~QueryBase() = default;

    private: 
        //virtual QueryResult eval(const TextQuery&) const = 0;
        virtual std::string rep() const = 0;
};

#endif