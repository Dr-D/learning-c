# rewind-seek

Opens a file for writing and writes `Hello World!` to the file.

Then opens the file for reading and reads the file, the file stream is now at the end of the file.

```bash
man 3 rewind
```

Then rewinds the file stream to the start of the file and can then read the text a second time.

```bash
man 3 fseek
```

The file stream is now at the end of the file again and fseek then sets the stream to position 6, SEEK_SET indicates this is from the beginning of the file.

The rest of the file stream is read from this point which prints `World!` to stdout.

## whence values
SEEK_SET - start of file

SEEK_CUR - current position

SEEK_END - end of file

