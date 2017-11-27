#ifndef MESSAGE_H_
#define MESSAGE_H_

#include <string>
class User;

/*
 * This is a message
 * A message is not only a text, but can also be any kind of data (e.g. a file)
 * A session always sends a message object, not a text
 */
class Message {
public:
    
    Message(std::string text);
    std::string getText();

private:
    
    User* sender;
    User* receiver;
    
    std::string text;

    uint sendTimestamp;
    uint receivedTimestamp;
};

#endif