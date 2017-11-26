/* 
 * CPP Message Server
 * github.com/cyberuserful/messaged
*/

#include "headers/Socket.h"
#include "headers/Session.h"
#include <string>
#include <vector>
#include <iostream>

#define MAXTHREADS 100
#define DEBUG

int main (int argc, char** argv) {

  if (argc < 2)  {
    std::cerr << "usage: \"" << argv[0] << " <port>\"" << std::endl;
    return 1;
  }

  // queues a maximum of 1000 incoming connections
  Socket socket(1000);
  socket.create();
  // server listens on port 1
  socket.bind(1);
  socket.listen();

  // TODO: find better way to store active sessions
  std::vector<Session*> sessions(100);

  bool accepting = true;
  Socket* newSocket;

  // server accept loop
  while (accepting) {
    if (socket.accept(newSocket)) {

      sessions.push_back(new Session(newSocket));
      std::cout << "[system]: detached session" << std::endl;
    }
  }

  
  // terminating
  socket.close();
  return 0;
}
