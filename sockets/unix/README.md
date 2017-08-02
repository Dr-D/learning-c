#unix-socket

Simple example of creating a unix socket.
Creates the socket in the current directory

Use curl to connect e.g.
```
curl --unix-socket /home/dr-d/learning-c/sockets/unix/socket http:/
```

Remove socket with unlink
```
man unlink
unlink /home/dr-d/learning-c/sockets/unix/socket
```