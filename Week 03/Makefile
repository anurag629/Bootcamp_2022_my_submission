CC = g++-11 -Wno-write-strings
all: server

server: server.cpp http_server.cpp
	$(CC) server.cpp http_server.cpp -o server

clean:
	rm -f server