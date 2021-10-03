#include <memory>
#include <initializer_list>
#include <vector>
#include <stdexcept>
using namespace std;

class strBlob{
    public:
        strBlob();
        strBlob(initializer_list<string> li): data(make_shared<vector<string>>(li)){}
        vector<string>::size_type size() const {return data -> size();}
        void push_back(const string& s) const {data->push_back(s);}
        void pop_back();
        string& front() {return get_front();}
        string& back() {return get_back();}
        const string& front() const {return get_front();}
        const string& back() const {return get_back();}
    private:
        shared_ptr<vector<string>> data;
        bool check(vector<string>::size_type, const string& msg) const;
        string& get_front() const {if (check(0, "no data stored!")) return data->front();}
        string& get_back() const {if (check(0, "no data stored!")) return data->back();}
};

bool strBlob::check(vector<string>::size_type index, const string& msg) const {
    if (index >= data->size()){
        throw out_of_range(msg);
    }

    return true;
}
void strBlob::pop_back(){
    if (check(0, "no data stored!")){
        data->pop_back();
    }
}
