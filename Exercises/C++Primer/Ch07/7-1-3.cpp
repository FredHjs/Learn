#include "Person.h"
using namespace std;
int main(){
    Person person, &p = person;
    read(p, cin);
    print(p, cout);
}

