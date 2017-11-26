#ifndef SESSION_H_
#define SESSION_H_

#include "Socket.h"
#include "Message.h"
#include <string>
#include <thread>
#include <iostream>

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