# signal basics

Simple example of how to catch a signal.

Uses sigaction to add handler
```
man sigaction
```

Build and run the executable, enter some text but press ctrl-c to cause a SIGINT to be sent.

Alternatively run the executable find the process ID using ps and grep
'''
$ ps -aux | grep ./main

darren    1630  0.0  0.0   4356   644 pts/19   S+   05:48   0:00 ./main
darren    1644  0.0  0.0  14228  1092 pts/2    S+   05:48   0:00 grep --color=auto ./main
'''

The process 1630 is the running process
```
kill -l
```

Lists all the signals that can be used by kill, shows SIGINT has value 2. Use kill to send an SIGINT which is the equivalent of using ctrl-c.
```
kill -2 1630
```
