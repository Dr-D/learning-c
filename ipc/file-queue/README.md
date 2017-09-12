# file-queue

Simple example of message queue where the message is a file.

Look at doing a buffered read of the file so exact number of bytes can be found.

Check the manual to see maximum size of message that can be sent. 
```
man msgsnd
```

## MSGMAX
Maximum size for a message text: 8192 bytes (on Linux, this limit can be read and modified via /proc/sys/kernel/msgmax).

## MSGMNB

Default maximum size in bytes of a message queue: 16384 bytes (on Linux, this limit can be read and modified via /proc/sys/kernel/msgmnb). The superuser can increase the size of a message queue beyond MSGMNB by a msgctl(2)