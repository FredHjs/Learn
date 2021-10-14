#include "Message.h"
#include <set>
#include <string>

Message::Message(const Message& rhs): content(rhs.content), folders(rhs.folders){
    this->add_to_folders(rhs);
}

Message::~Message(){
    this->remove_from_folders();
}

Message& Message::operator=(const Message& rhs){
    this->remove_from_folders();
    this->add_to_folders(rhs);
    this->content = rhs.content;
    this->folders = rhs.folders;
    return *this;
}