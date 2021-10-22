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
    friend bool operator==(const StrBlob&, const StrBlob&);
    friend bool operator!=(const StrBlob& lhs, const StrBlob& rhs);
    friend bool operator<(const StrBlob& lhs, const StrBlob& rhs);
    
    public:
        StrBlob(): data(make_shared<vector<string>>()){}

        StrBlob(initializer_list<string> li): data(make_shared<vector<string>>(li)){}

        StrBlob(const StrBlob& rhs): data(make_shared<vector<string>>(rhs.data)){}

        StrBlob& operator=(const StrBlob&);

        vector<string>::size_type size() const {return data -> size();}

        void push_back(const string& s) const {data->push_back(s);}

        void push_back(string&& s) const {data->push_back(std::move(s));}

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

class StrBlobPtr{
    friend bool operator<(const StrBlobPtr&, const StrBlobPtr&);

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


#endif
