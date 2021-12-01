#ifndef FOLDER_H
#define FOLDER_H
#include <set>
#include <initializer_list>
#include "Message.h"
using namespace std;

class Folder{
    public:
        Folder() = default;
        Folder(initializer_list<Message*> messages);
        Folder& add_msg(Message*);
        Folder& remove_msg(Message*);

    private:
        set<Message*> messages;

};

#endif