#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include "Person.h"
#include <string>

using namespace std;
class Person{
    friend istream& read(Person& person, istream& is);
    friend ostream& print(Person& person, ostream& os);

    public:
        Person(const string& name, const string& address)
            :Name(name), Address(address){}

            //functions defined inside struct will be seen as inline functions
        string get_name() const {return Name;}
        string get_address() const {return Address;}
    private:
        string Name;
        string Address;
};

istream& read(Person& person, istream& is){
    getline(is, person.Name);
    getline(is, person.Address);
    return is;
}

ostream& print(Person& person, ostream& os){
    os << person.Name << ": " << person.Address;
    return os;
}

#endif