# Messaging1

Initial changes to the server, using a pthread to run the server.
If you have looked at the thread section and sockets/multicast seciton  there should be no new techniques to learn.

## Server
We basically create a new pthread that runs the server function.

The server is essentially the same code as found in the sockets/multicast section but we just update our shared_message. As shared_message is a static value in our server.c file it is available to any methods within the smae file.

## Client 
This is the same client as in the sockets/multicast section.

## Other
We have include time.h to allow us to see when a message is printed.

I have threaded the server because we want to be able to have a client and server in the same process. Because the server blocks and waits for a message to be recieved we would never be able to do anthing else until a message is recieved.

It would be useful to not have a shared_message variable as things can start getting complicated when threading is involved but we need some form of shared data to allow access by more than one thread.

