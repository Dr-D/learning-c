# Thread In Thread

Simple example of creating a posix thread that creates other threads.

## In main()

We start as in our basic example of creating a thread which we name thread1.

The name of the thread is passed as the 'void *arg' paramter of pthread_create so that we can print it in the thread method which is 'void * run'.

## In run()
The 'void * run' method is where thread1 starts. We can see it is doing exactly the same this as in main creating a thread with the name of the thread passed as the 'void * arg' parameter. This thread is named thread1_1 and has 'void * run2' as the thread method.

A second thread is then created named thread1_2 in exactlay the same way.

## In run2()
The child threads(thread1_1, thread1_2) just print that the thread has started with their name, sleep for a second and then print they are exiting.

Control then passes back to 'void *run()' method where thread1 exits.
Finally control returns to main() where the main thread exits.

#Things to try
Using the same code you can have thread1_1 or thread_1_2 create child threads of their own, but having too many threads makes things obviously much more complicated.

You may want a program to always have two thread running in the background providing some sort of resource or service.
You can have thread1 running an infinite loop.
Thread1 can create its child threads on the heap using malloc.
Thread1 checks if its two child threads are running and if one of them has failed it can 'free' the memory in use by that thread and then start a new thread.
