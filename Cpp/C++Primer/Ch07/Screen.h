#ifndef SCREEN_H
#define SCREEN_H
#include <iostream>
#include <vector>
using namespace std;

class Screen;
class Window_mgr{
    using ScreenIndex = vector<Screen>::size_type;

    public:
        void clear_screen(ScreenIndex);

    private:
        vector<Screen> Screens;
};

class Screen{
    using pos = string::size_type;
    friend void Window_mgr::clear_screen(ScreenIndex);

    public: 
        Screen() = default;
        Screen(pos height, pos width): 
            height(height), width(width), content(height * width, ' '){}
        Screen(pos height, pos width, char c):
            height(height), width(width), content(height * width, c){}

        char get(){return content[cursor];}
        inline char get (pos, pos) const;
        //most of the functions in this class return Screen&, so they can be chained together
        Screen& move(pos, pos);
        Screen& set(pos, pos, char);
        Screen& display(ostream&);      
        //--added const version of display() so that this function can be 
        //      called on both const and non-const Screen objects
        //--altough we can call this const version on both const and non-const objects, the non-const 
        //      version would be the best match for non-const objects because it returns non-const Screen
        //      so we can chain other functions after displaying the contents;
        const Screen& display(ostream&) const;      
    
    private:
        pos cursor = 0;
        pos height = 0, width = 0;
        string content;
        void do_display(ostream& os) const {os << content;}
};

void Window_mgr::clear_screen(ScreenIndex i){
    Screen& s = Screens[i];
    //s.content = 
}
inline char Screen::get(pos row, pos col) const {
    auto position = row * width + col;
    return content[position];
}

Screen& Screen::move(pos row, pos col){
    cursor = row * width + col;
    return *this;
}

Screen& Screen::set(pos row, pos col, char c){
    auto position = row * width + col;
    content[position] = c;
    return *this;
}

Screen& Screen::display(ostream& os){
    do_display(os);
    return *this;
}

//in a const member function, the ptr "this" points to a const object, and that's why this function
//  returns const Screen& 
const Screen& Screen::display(ostream& os) const{
    do_display(os);
    return *this;
}

#endif