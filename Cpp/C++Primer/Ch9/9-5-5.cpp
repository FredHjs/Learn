#include <string>
#include <iostream>

using namespace std;;
class DateTime{
    public: 
        unsigned year;
        unsigned month;
        unsigned day;

        DateTime(string& s){
        auto first_delimiter_pos = s.find_first_of(" /,-");
        auto month_str = s.substr(0,first_delimiter_pos);
        if (month_str.find_first_of("1234567890") != string::npos){
            month = stoi(month_str); 
        }else{
            for (string::size_type i{0}; i < 12; ++i){
                if (s.find(months[i]) != string::npos){
                    month = i+1;
                    break;
                }
            }
        }

        auto second_delimiter_pos = s.find_last_of(" /,-");
        day = stoi(s.substr(first_delimiter_pos + 1, second_delimiter_pos));

        year = stoi(s.substr(second_delimiter_pos + 1));
    }

    private:
        const string months[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep","Oct", "Nov", "Dec"};

    
};



int main(){
    string date;
    cout << "please enter a date: ";
    cin >> date;

    DateTime date_time(date);

    cout << date_time.month << "/" << date_time.day << "/" << date_time.year;
}