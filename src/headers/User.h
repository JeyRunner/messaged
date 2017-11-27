#ifndef USER_H_
#define USER_H_

#include <iostream>
#include <string>
#include <vector>
#include "Session.h"
#include "Message.h"

class User {
public:
    User(std::string username, std::string password);

    // sends message to user (returns false, if receiver does not have at least one session)
    bool sendMessage(Message* message);

    bool verifyCredentials(std::string username, std::string password);

    void addSession(Session* newSession);


private:
    std::vector<Session*> sessions;

    std::string username;
    std::string password;

};

#endif