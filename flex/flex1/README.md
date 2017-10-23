# flex1

Format of flex file

definitions
%%
rules
%%
user code

The demo.lex file basically has a single rule that checks input for value 'test' and returns value 'ok'.

## Creating the lexer
In a shell enter:

```bash
flex demo.lex
```

This will create a file lex.yy.c. Then compile this file with the flex library:
```bash
gcc lex.yy.c -lfl -o lexer
```
You can open teh lex.yy.c file as it is a basically a c source code file that is compiled to create and executable.

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
