# dual pipes

Simple example of using two pipes to message between processes.

This uses fork to create a child process and pipe
```
man fork
man pipe
```

When you execute this application it will show the parent process has created the child process.
They will then message each other and quit. The pipes are unidirectional so when you look at the man page for pipe you will see that you can only write to one end of the pipe and read from the other which is why you need two pipes to be able to send messages both ways.

If there is more than two processes involved you will obvioulsy start have to have many more pipes as each process will need a 2 pipes to message each process. 



