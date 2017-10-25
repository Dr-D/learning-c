# flex2

/*Defintions*/
%{
int num = 0;
%}

DIGIT  [0-9]

%%
 /*rules*/
{DIGIT} { num++; printf("DIGIT: '%s', count: '%d'\n", yytext, num); }

%%

## Defintions
Note how a c type variable is created using %{ and ending in %}, if you get a premature EOF error then check the ordering of these. Also check if there are spaces in front of these opening and closing values.

There is also a second way for creating a defintion <name> <definition>. The name of the defintion is DIGIT and the defintion is a regex that check for a single char if it is a digit.

## Rules
Here we are still just printing out values so we print out the digit we found and the c variable num is incremented by one each time we find a digit and is printed out.

## Lexer output
Compile and run the lexer:
```
flex demo.lex
gcc lex.yy.c -lfl -o lexer
./lexer
```

Some test input:
```
a1b2c3
aDIGIT: '1', count: '1'
bDIGIT: '2', count: '2'
cDIGIT: '3', count: '3'
```

The first character is 'a' it is not covered by the rules so is just output without being changed. The next character is '1' which is a digit. This increments num by 1 and prints out the digit value and number of digits found.
 