#include <string>
#include "User.cpp"

/*
 * This is message
 * A message is not only a text, but can also be any kind of data (e.g. a file)
 * A session always sends a message object, not a text
 */
class Message {

    Message()
    {
        
    }

    string getText()
    {
        return this.text;
    }

private:
    
    User* sender;
    User* receiver;
    
    std::string text;

    uint sendTimestamp;
    uint receivedTimestamp;
};