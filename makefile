GCC = gcc -g

all: server client

server: server.c pipe_networking.c
	$(GCC) server.c pipe_networking.c -o server

client: client.c pipe_networking.c
	$(GCC) client.c pipe_networking.c -o client

runserver: server
	./server

runclient: client
	./client