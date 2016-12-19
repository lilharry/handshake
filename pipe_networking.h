#ifndef PIPE_NETWORKING_H
#define PIPE_NETWORKING_H
#endif

#define MESSAGE_BUFFER_SIZE 100

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>

#define WKP "mario"
int server_handshake( int * from_client);
int client_handshake( int * to_server );