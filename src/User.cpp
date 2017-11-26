#include <iostream>
#include <string>
#include <vector>
#include "Session.cpp"
#include "Message.cpp"

class User {

public:
    User(std::string username, std::string password)
    {
        this->username = username;
        this->password = password;
    }

    // sends message to user (returns false, if receiver does not have at least one session)
    bool sendMessage(Message* message)
    {
        uint sessionCount = sessions.size();

        if (sessionCount == 0)
            return false;

        for (uint i; i < sessionCount; i++)
        {
            sessions[i].send(message);
        }

        return true;
    }


    bool verifyCredentials(std::string username, std::string password)
    {
        if (username == this.username && password == this.password)
        {
            return true;
        }
        

        return false;
    }


    void addSession(Session* newSession)
    {
        this.mySessions.push_back(newSession);
    }


private:
    std::vector<Session*> sessions();

    std::string username;
    std::string password;

};