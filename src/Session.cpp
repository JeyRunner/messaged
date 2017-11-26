#include "headers/Session.h"

Session::Session(Socket* socket)
{
	this->socket = socket;

	// every Session has an own thread for receiving incoming messages
	this->receivingThread = std::thread(&Session::receive, this);

	// detaching receivingThread
	this->receivingThread.detach();

	// sending initial welcome message to client
	this->socket->send("de.thelittlemax.chat:0.4");
}

Session::~Session()
{
	//this->receivingThread.terminate();

	this->socket->close();

	delete socket;
}


bool Session::send(Message* message)
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



void Session::receive()
{

	std::string recvBuf;

	while (socket->recv(recvBuf))
		std::cout << "\"" << recvBuf << "\"" << std::endl;
}
