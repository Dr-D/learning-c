# flex

Human readable code is converted into machine code by the c compiler. For this to occur 'lexical analysis' has to be performed on the code. Lexical = relating to the words or vocabulary of a language.

'flex' is a Linux/GNU lexer which was originally 'lex' a  UNIX lexer.

## Tokenise
A lexer basically converts the human readable code into tokens. For example:
```
int count = 0;
```
Could be tokenised into:
```
INTEGER, ID(count), EQUALS, ID(0), SEMICOLON
```
