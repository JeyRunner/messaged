#ifndef SESSION_H_
#define SESSION_H_

#include <string>
#include "Socket.h"
#include <thread>
#include <iostream>
#include "Message.h"

class Session
{
public:

	Session(std::string identifier, Socket* socket);

    ~Session();

	bool send( Message* message );

	std::string Session::recv();

	void receive();

private:
    
	std::string identifier;
	Socket* socket;

	thread receivingThread;
};

#endif