#include "BulkQuote.h"

int main(){
    Quote q("12345", 10);
    Quote rq(q);
    BulkQuote bq("bq", 10, 10, 0.5);
    BulkQuote bq_2(bq);
    BulkQuote bq3;
    bq3 = bq;
}