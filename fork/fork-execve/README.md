# fork-execve

Simple program to show how to fork a process and then child executes a new process.

## execve
```
man execve
```
Basically overwites the current process being executed.
The child process in the fork will not finish unless the execve does not work.

## fix
Need better explanation of how the command args are used in execve. At moment is opens a shell and then runs a command in a second shell.
