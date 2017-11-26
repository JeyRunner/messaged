/* 
 * CPP Message Server
 * github.com/cyberuserful/messaged
*/



#include "headers/Socket.h"
#include "headers/Session.h"
#include <string>
#include <iostream>
#include <fstream>

#define MAXTHREADS 100
#define DEBUG

bool accepting = true; 	// accepts connection


int main (int argc, char* argv[]) {

    if (argc < 2)  {

        std::cerr << "please use: \"program <port>\"" << std::endl;
        exit(1);
    }


    for (uint i = 0; i < MAXTHREADS; i++)
      pool[i] = NULL;


    cout << "[system]: setting up socket on port: 1234 ... ";
    Socket mainSocket( 100 );
    mainSocket.create();
    mainSocket.bind( atoi( argv[1] ) );
    mainSocket.listen();
    cout << "done" << endl;




    // free id
    uint id;
    // buffer for accepted socket
    Socket* buf;

    // server accept loop
    while (accepting) {

      id = Session::getFreeSessionIndex();
      if (id == -1)
      {
        cout << "[system]: No more connection slots available!" << endl;
        sleep(100);
      }

      if ( mainSocket.accept( buf ) )
      {
        Session::pool[id] = new Session(id, buf);
        Session::pool[id]->detach();
        cout << "[system]: detached session with id: " << id << endl;
      }
    }


    mainSocket.close();
    return 0;
}
