# Messaging1.2

# Main - Client

The client is essentially the same code as found in Messaging1 it has been moved to its own multicast client file mclient.c.

The client now sends the host ip address and unique id for the multicast message.

# Configuration File
Have added in the code from the config-file project. This allows us to set the multicast address and port manually.

Note that we are using global varaiables to pass these values to the server and client.
May change this so that we start the client and server via methods that take these values as parameters.

# Logging
Added printf statements that output to stdout. Will look at this again as there is a alot of output to stout now. Will need to get some logging levels and eventually log to file.

