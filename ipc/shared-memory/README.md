# shared memory

Simple example of using shared memory.

Allocate memory segment
```
man shmget
```

Shared memory attach returns a void* which can be pointer to any value
```
man shmat
```

Then need to detach the memory and remove/de-allocate the shared memory.

NB can use ipcs to list ipc resources in use and ipcrm to remove the resource.

Things to try create the shared memory and use second client to read the memory.
