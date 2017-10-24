# flex1
This first use of flex is present to start to show how a flex file is formatted and how to build the lexer which it turns out is an executable based on a c code file.

## Format of flex file

definitions
%%
rules
%%
user code

## Creating the lexer
The directory contains a demo.lex file that basically has a single rule that checks input for value 'test' and returns value 'ok'.

```
 /*Demo flex file*/
%%
test printf("ok");
%%
```
When setting up an actual lexer you the lexer checks the input and creates a Token, our demo just prints out a value at the moment. Note that comments can be added to the file, the above has a normal c style comment in the definitions section.

In a shell enter:

```bash
flex demo.lex
```

This will create a file lex.yy.c. Then compile this file with the flex library:
```bash
gcc lex.yy.c -lfl -o lexer
```
You can open the lex.yy.c file as it is basically a c source code file that is compiled with the fl(flex) library to create an executable.

Run the executable:
```bash
./lexer
```

You can now enter text onto the command line and press enter.
```bash
abc
abc
def
def
test
ok
```
As indicated above there is a single rule that outputs 'ok' whenever 'test' is entered.
