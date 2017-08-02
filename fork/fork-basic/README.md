# fork-basic

Simple program to show how to fork a process, with pipe so that the parent can write to to the child process.
All the code for pipe can be removed and the process will still fork.

## fork
```
man fork
```

The process id of the child is returned to the parent process. The child process will have a process id of 0. Note a process id of -1 indicates there was a problem forking the process.

## pipe

```
man pipe
```

The pipefd[] is a simple integer array with size of 2.
The write end of the pipe is the second value of the array.
The read end of the pipe is the first value in the array.


## fix
The read buffer is not zeroed so could affect what is actually output.
If the fork fails errerno is set so should be shown in the error output.
