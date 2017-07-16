#multicast client/server

client.c

Simple example of creating a client to send a multicast request
Uses struct addrinfo to get the appropriate socket information.
```
man getaddrinfo.
```

Using the result to create a socket. 
```
man socket
```

Send message to socket descriptor
```
man sendto
```
server.c
Simple example of creating a serer to recieve a multicast request

Allow bind to a socket already in use with SO_REUSEADDR and join multicast group
```
man setsocketopt
```
