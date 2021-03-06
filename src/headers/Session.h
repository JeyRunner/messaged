#ifndef SESSION_H_
#define SESSION_H_

#include "Socket.h"
#include "Message.h"
#include <string>
#include <thread>
#include <iostream>

class Session {
public:
	Session(Socket* socket);

    ~Session();

	bool send( Message* message );

	std::string recv();

	void receive();

private:

	std::string identifier;
	Socket* socket;

	std::thread receivingThread;
};

#endif