#include "Message.h"
#include "Folder.h"
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

void Message::save_in(Folder& folder){
    folders.insert(&folder);
    folder.add_msg(this);
}

void Message::remove_from(Folder& folder){
    folders.erase(&folder);
    folder.remove_msg(this);
}

void Message::add_to_folders(const Message& msg){
    for (auto& f : msg.folders){
        f->add_msg(this);
    }
}

void Message::remove_from_folders(){
    for (auto& f : folders){
        f->remove_msg(this);
    }
}

void swap(Message& lhs, Message& rhs){
    using std::swap;
    for (auto& f : lhs.folders){
        f->remove_msg(&lhs);
    }

    for (auto& f : rhs.folders){
        f->remove_msg(&rhs);
    }

    swap(lhs.content, rhs.content);
    swap(lhs.folders, rhs.folders);

    for (auto& f : lhs.folders){
        f->add_msg(&lhs);
    }

    for(auto& f : rhs.folders){
        f->add_msg(&rhs);
    }

}