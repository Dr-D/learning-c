# Messaging1.1

# Main - Server

The server is essentially the same code as found in Messaging1 it has been moved to its own multicast server file mserver.c.

The shared_message has been moved to be a static value in our mserver.c file, with a getter method to allow access to it.

The printed message is now only 

## Client 
This is essentially the same client as in the sockets/multicast section, but has been modified to allow a message to be entered which will be the message multicasted to all the servers.

## Other
Make sure you are happy that you can enter a message and that it is broadcast to multiple servers.

