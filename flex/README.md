# flex

Human readable code is converted into machine code by the c compiler. For this to occur 'lexical analysis' has to be performed on the code. Lexical = relating to the words or vocabulary of a language.

'flex' is a Linux/GNU lexer which was originally 'lex' a  UNIX lexer.

## Tokenise
A lexer basically converts the human readable code into tokens. For example the following expression:
```
int count = 0;
```
Could be tokenised into:
```
INTEGER, VAL(count), EQUALS, VAL(0), SEMICOLON
```

What the lexer has done is scan the input file splitting it in to parts and found:
 'int' - this is in the list of language specific words so knows it is an INTEGER.
 'count'- this is not a language specific word so is tokenised to a user defined value.
 '=' - is an operator 
 '0'- this is not a language specific word so is tokenised to a user defined value.
 ';' - signifies the end of the expression.

These tokens are then passed to a parser (yacc/bison) that checks/parses the tokens to make sure the code is has the correct syntax/ordering.

## Simple Syntax Examples 
**Extra int on second line**
```
int main(int argc, char *argv[]) {
  int int count = 0;
  return 0;
}
```
Producing tokens:
```
INTEGER, INTEGER, VAL(count), EQUALS, VAL(0), SEMICOLON
```

When we try to compile the above code we see  this error `two or more data types in declaration specifiers`. The parser will have a check to make there is only ever one data type for the expression.

**Two values together**
```
int count count = 0;
```
Producing tokens:
```
INTEGER, VAL(count), VAL(count), EQUALS, VAL(0), SEMICOLON
```
If we try to compile above code we see this error `expected ‘=’, ‘,’, ‘;’, ‘asm’ or ‘__attribute__’ before ‘count’`.

**No variable type**
```
count = 0;
```
Producing tokens:
```
VAL(count), EQUALS, VAL(0), SEMICOLON
```
Error: ‘count’ undeclared (first use in this function).
