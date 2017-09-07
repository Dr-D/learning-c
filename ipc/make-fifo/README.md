# make-fifo

Running make will create mkfifo and writer executable files.
Check the manual man 3 mkfifo
```
int mkfifo(const char *pathname, mode_t mode);
```
Retrurn 0 for success. mode-t mode is the permissions on the file created applies umask to the value.

Running mkfifo Creates a named pipe called test.

```
./mkfifo

ls -l

prw-rw-r-- 1 drd drd    0 Sep  7 04:19 test|
```

Run the writer it will block as the pipe requires a reader.

In a second shell and run:
```
cat test 
```

Remove the pipe as you would any other fie
```rm test```

You can open multiple terminals and start multiple writers and multiple readers.
Only one writer can write to the pipe at any time and only one reader will read from the pipe at at any time.

The equivalent can be done in bash.
```
mkfifo test
printf "TESTING BASH FIFO\n" > test
```

Then run cat test in a second shell.