
CC = gcc
CLIENT_FILE = c.c
SERVER_FILE = s.c

all: c s

client: $(CLIENT_FILE)
	$(CC) $(CLIENT_FILE) -o c

server: $(SERVER_FILE)
	$(CC) $(SERVER_FILE) -o s

clean:
	rm -f c s