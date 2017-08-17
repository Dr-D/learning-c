# Using a mutex for array writes

Simple example of mtuex.

Multiple threads writing to the same array can cause the array to have incorrect values. This is a slightly contived example as having to use thread sleep to get race condition.

Run the program with the pthread_mutext_lock & unlock commented out.

Then uncomment the lines so that the mutex is used, using the mutex when writing to the array avoids the array getting into an invalid state.

Improvements - Putting the array into a struct would allow a thread safe array to be create, so that the struct can only be updated by a method that uses a mutex. A read on the array could also return an array in an invalid state so the read/write code would need a mutal mutex to before either are called. 



