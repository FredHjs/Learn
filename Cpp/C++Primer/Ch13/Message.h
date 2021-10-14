#ifndef MESSAGE_H
#define MESSAGE_H
#include <string>
#include <set>

using namespace std;
class Folder;

class Message{
    friend class Folder;

    public:
        explicit Message(const string& s = ""): content(s){}
        Message(const Message&);
        Message& operator=(const Message&);
        ~Message();
        void save(Folder&);
        void remove(Folder&);

    private:
        string content;
        set<Folder*> folders;
        void add_to_folders(const Message&);
        void remove_from_folders();
};

void swap(Message&, Message&);

#endif