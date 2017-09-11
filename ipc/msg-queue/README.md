# message-queue

Simple example of message queue, message is a string value.

Create IPC key from pathname. Can use any pre-existing directory path or file path. May be better to create a file, make sure it exists then call ftok. 
```
man ftok
```
Create the message queue with msgget and then send the message.

```
man msgget
man msgsnd
```

In a bash shell use ipcs to get list of message queues
```
man ipcs
ipcs -q
```

Then use ipcrm to to remove the queue
```
man ipcrm
````





