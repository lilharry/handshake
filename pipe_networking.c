#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include "pipe_networking.h"

int server_handshake( int * from_client ) {
  int err;
  err = mkfifo( WKP, 0664 );

  *from_client = open( WKP, O_RDONLY );
  char message[MESSAGE_BUFFER_SIZE];

  read( *from_client, message, MESSAGE_BUFFER_SIZE ); 
  remove( WKP );

  int to_client = open( message, O_WRONLY );

  char message2[MESSAGE_BUFFER_SIZE] = "Hello";
  write( to_client, message2, MESSAGE_BUFFER_SIZE );
  
  read( *from_client, message2, MESSAGE_BUFFER_SIZE );
  printf("Message received: %s",message2);
}

int client_handshake( int * to_server ) {
  int err;
  char pp[MESSAGE_BUFFER_SIZE] = "private";
  err = mkfifo(pp, 0664);

  *to_server = open( WKP, O_WRONLY );
  
  write( *to_server, pp, sizeof(pp) );

  int from_server = open( pp, O_RDONLY );

  char message[MESSAGE_BUFFER_SIZE];
  read( from_server, message, MESSAGE_BUFFER_SIZE );
  printf("Message received %s\n",message);
  remove(pp);
  write( *to_server, message, sizeof(message) );
  

}
