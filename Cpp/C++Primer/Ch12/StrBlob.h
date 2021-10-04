#ifndef STR_BLOB_H
#define STR_BLOB_H
#include <memory>
#include <initializer_list>
#include <vector>
#include <stdexcept>
using namespace std;
class StrBlobPtr;

class StrBlob{
    friend class StrBlobPtr;
    public:
        StrBlob(): data(make_shared<vector<string>>()){}
        StrBlob(initializer_list<string> li): data(make_shared<vector<string>>(li)){}
        vector<string>::size_type size() const {return data -> size();}
        void push_back(const string& s) const {data->push_back(s);}
        void pop_back();
        string& front() {return get_front();}
        string& back() {return get_back();}
        const string& front() const {return get_front();}
        const string& back() const {return get_back();}
        StrBlobPtr begin();
        StrBlobPtr end(); 
        
    private:
        shared_ptr<vector<string>> data;
        bool check(vector<string>::size_type, const string& msg) const;
        string& get_front() const {if (check(0, "no data stored!")) return data->front();}
        string& get_back() const {if (check(0, "no data stored!")) return data->back();}
};

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

class StrBlobPtr{
    public:
        StrBlobPtr():curr(0){}
        StrBlobPtr(StrBlob& strBlob, size_t sz = 0): wp(strBlob.data), curr(sz){}
        string& deref() const;
        StrBlobPtr& incr();
        bool operator!=(const StrBlobPtr& rhs) {return this->curr != rhs.curr;}
    private:
        shared_ptr<vector<string>> check(const string& msg, vector<string>::size_type index) const;
        vector<string>::size_type curr;
        weak_ptr<vector<string>> wp;
};

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
#endif
