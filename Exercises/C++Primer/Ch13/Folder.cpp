#include "Message.h"
#include "Folder.h"

Folder::Folder(initializer_list<Message*> messages){
    for (auto& m : messages){
        this->messages.insert(m);
    }
}

Folder& Folder::add_msg(Message* msg){
    messages.insert(msg);
    return *this;
}

Folder& Folder::remove_msg(Message* msg){
    messages.erase(msg);
    return *this;
}

