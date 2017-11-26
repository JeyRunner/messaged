server: 
	g++ src/Socket.cpp src/User.cpp src/Session.cpp -std=c++11 -pthread -o server
thread:
	g++ src/threadTest.cpp -std=c++11 -pthread -o threadTest
