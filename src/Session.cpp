#include <string>
#include "Socket.h"
#include <thread>
#include <iostream>
#include "Message.cpp"

class Session
{

public:
	Session(std::string identifier, Socket* socket)
	{
		this->socket = socket;

		// every Session has an own thread for receiving incoming messages
		this->receivingThread = std::thread(&Session::receive, this);

		// detaching receivingThread
		this->receivingThread.detach();

		// sending initial welcome message to client
		this->socket->send("de.thelittlemax.chat:0.4");
	}

  ~Session()
	{
		//this->receivingThread.terminate();

		this->socket->close();

		delete socket;
	}


	bool send( Message* message )
	{
		// serialize message first, then send serialized via network
		return socket->send(message->getText());
	}

	std::string Session::recv()
	{
		// receive serialized message object, deserialize it and return object
		string buffer;
		socket->recv(buffer);

		return buffer;
	}



	void receive()
	{

		std::string recvBuf;

		while (socket->recv(recvBuf))
			std::cout << "\"" << recvBuf << "\"" << std::endl;
	}

private:
	std::string identifier;
	Socket* socket;

	thread receivingThread;
};