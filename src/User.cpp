#include "headers/User.h"

User::User(std::string username, std::string password) {
    this->username = username;
    this->password = password;
}

// sends message to user (returns false, if receiver does not have at least one session)
bool User::sendMessage(Message* message)
{
    uint sessionCount = this->sessions.size();

    if (sessionCount == 0)
        return false;

    for (uint i; i < sessionCount; i++)
    {
        this->sessions[i]->send(message);
    }

    return true;
}


bool User::verifyCredentials(std::string username, std::string password)
{
    if (username == this->username && password == this->password)
    {
        return true;
    }
    

    return false;
}


void User::addSession(Session* newSession)
{
    this->sessions.push_back(newSession);
}