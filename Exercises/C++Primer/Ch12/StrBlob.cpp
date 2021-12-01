#include "StrBlob.h"

StrBlob& StrBlob::operator=(const StrBlob& rhs){
    auto new_data = make_shared<vector<string>>(*(rhs.data));

    this->data.reset(new_data.get());

    return *this;
}

bool StrBlob::check(vector<string>::size_type index, const string& msg) const {
    if (index >= data->size()){
        throw out_of_range(msg);
    }

    return true;
}
void StrBlob::pop_back(){
    if (check(0, "no data stored!")){
        data->pop_back();
    }
}

shared_ptr<vector<string>> StrBlobPtr::check(const string& msg, vector<string>::size_type index) const{
    auto shared_ptr = wp.lock();
    if (shared_ptr){
        if (shared_ptr->size() > index){
            return shared_ptr;
        }else{
            throw out_of_range(msg);
        }
    }else{
        throw runtime_error("object pointer not set to an object");
    }
}

string& StrBlobPtr::deref() const{
    auto shared_ptr = check("index out of range", this->curr);
    return (*shared_ptr)[this->curr];
}

StrBlobPtr& StrBlobPtr::incr(){
    auto shared_ptr = check("increament out of range", this->curr);
    ++this->curr;
    return *this;
}

StrBlobPtr StrBlob::begin() {return StrBlobPtr(*this, 0);}

StrBlobPtr StrBlob::end() {auto ret = StrBlobPtr(*this, this->data->size()); return ret;}

StrBlobPtr& StrBlobPtr::operator=(const StrBlobPtr& rhs){
    wp = rhs.wp;
    curr = rhs.curr;
}

bool operator==(const StrBlob& lhs, const StrBlob& rhs){
    return *lhs.data == *rhs.data;
}

bool operator!=(const StrBlob& lhs, const StrBlob& rhs){
    return !(*lhs.data == *rhs.data);
}

bool operator<(const StrBlob& lhs, const StrBlob& rhs){
    return *lhs.data < *rhs.data;
}

bool operator<(const StrBlobPtr& lhs, const StrBlobPtr& rhs){
    if (lhs.wp.lock() != rhs.wp.lock()) return false;

    if (lhs.curr == rhs.curr) return true;

    return false;
}

StrBlobPtr& StrBlobPtr::operator++(){
    check("increment out of range", ++curr);
    return *this;
}

StrBlobPtr& StrBlobPtr::operator--(){
    check("decrement out of range", --curr);
    return *this;
}

StrBlobPtr StrBlobPtr::operator++(int){
    auto temp = *this;
    ++(*this);
    return temp;
}

StrBlobPtr StrBlobPtr::operator--(int){
    auto temp = *this;
    --(*this);
    return temp;
}

std::string& StrBlobPtr::operator*() const {
    auto p = check("dereference out of range", curr);
    return (*p)[curr];
}

std::string* StrBlobPtr::operator->() const {
    return &(this->operator*());
}