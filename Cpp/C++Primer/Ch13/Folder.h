#ifndef FOLDER_H
#define FOLDER_H
#include <set>
#include "Message.h"
using namespace std;

class Folder{
    public:
        Folder() = default;
        Folder& add_msg(Message*);
        Folder& remove_msg(Message*);

    private:
        set<Message*> messages;

};

#endif