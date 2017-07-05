#socket-accept

Simple example of creating a socket to accept incoming requests. 
Uses struct addrinfo to get the appropriate socket information.
```
man getaddrinfo.

Using the result to create a socket. 
```
man socket

Binding the socket.
```
man bind

Listen
```
man listen

Set up the while loop so that we can keep the socket open. Using accept to 
wait for incoming requests.
```
man 2 accept

Then reading and writing to the socket descriptor. Make the main executable and run it. Use a web brower, curl or similar to connect e.g. http://localhost:6000. You should see the http request from your client in the terminal and curl will show the message recieved.

