#include "Query.h"
#include "QueryBase.h"
#include "AndQuery.h"
#include "OrQuery.h"
#include "WordQuery.h"



int main(){
    Query q = Query("fiery") & Query("bird") | Query("wind");
    return 0;
}