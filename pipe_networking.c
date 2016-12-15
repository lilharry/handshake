#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>

#define WKP "mario"
#define PP_SIZE 10

int server_handshake( int * from_client ) {
  int err;
  err = mkfifo( WKP, 0664 );

  *from_client = open( WKP, O_RDONLY );
  char pp[ PP_SIZE ];

  read( *from_client, pp, sizeof(pp) ); 
  remove( WKP );

  int to_client = open( pp, O_WRONLY );

  char message[10] = "hello";
  write( to_client, message, strlen(message) );
  
  read( *from_client, message, sizeof(message) );
  
}

int client_handshake( int * to_server ) {
  int err;
  char pp[ PP_SIZE ] = "private"
  err = mkfifo(pp, 0664);

  *to_server = open( WKP, O_WRONLY );
  
  write( *to_server, pp, sizeof(pp) );

  int from_server = open( pp, O_RDONLY );

  char message[10];
  read( from_server, message, sizeof(message) );

  write( *to_server, message, sizeof(message) );
  

}
