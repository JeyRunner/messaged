#ifndef SOCKET_H_
#define SOCKET_H_

#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>

// Max. Anzahl an Daten die aufeinmal empfangen werden
const int MAXRECV = 1024;

// Die Klasse Socket
class Socket {
private:
   // Max. Anzahl Verbindungen
   const int MAXCONNECTIONS;
   // Socketnummer (Socket-Deskriptor)
   int m_sock;
   // Struktur sockaddr_in
   sockaddr_in m_addr;

public:
   // Konstruktor
   Socket(const int MAXCONNECTIONS);
   // virtueller Destruktor
   virtual ~Socket();

   // Socket erstellen - TCP
   bool create();
   // Socket erstellen - UDP
   bool UDP_create();
   bool bind( const int port );
   bool listen() const;
   bool accept( Socket* ) const;
   bool connect ( const std::string host, const int port );
   // Datenübertragung - TCP
   bool send ( const std::string ) const;
   int recv ( std::string& ) const;
   // Datenübertragung - UDP
   bool UDP_send( const std::string, const std::string,
                  const int port ) const;
   int UDP_recv( std::string& ) const;
   // Socket schließen
   bool close() const;
   // WSAcleanup()
   void cleanup() const;
   bool is_valid() const { return m_sock != -1; }
};
#endif
