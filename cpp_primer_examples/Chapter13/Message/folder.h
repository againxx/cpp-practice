#ifndef FOLDER_H_
#define FOLDER_H_

#include <iostream>
#include <string>
#include <set>

class Message;

class Folder {
public:
    explicit Folder(const std::string &str = "") :
        name(str) { }
    ~Folder();

    void addMsg(Message *msg) { messages.insert(msg); }
    void remMsg(Message *msg) { messages.erase(msg); }

    void printMsg() const;

private:
    std::string name;
    std::set<Message*> messages;
};

#endif  // FOLDER_H_
