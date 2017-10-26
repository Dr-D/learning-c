# flex2

## flex file
```
/*Defintions*/
%{
int num_count = 0;
%}

DIGIT  [0-9]

%%
 /*rules*/
{DIGIT}+ { num_count++; printf("DIGIT: '%s'\n", yytext); }

%%
 /*user code*/
int main() {
  printf("User code section.\n");
  yylex();
  printf("Number count: '%d'\n", num_count);
  return 0;
}
```

## defintions
Updated variable name as we are now going to count the numbers in the input not all the digits.

## rules
Rule has been updated to look for 1 or more digits together. So for an input of 123 346 it will now find two numbers '123' and '456'.

## user code
A main method is defined which gives the entry point to the lexer. Note in this section of code having no space in front of the comment causes no errors. Possibly the best policy is to just put a space in front of all the comments.

## lexer output explained

Build and run the lexer:
```
User code section.
abc 123
abc DIGIT: '123'

345 def
DIGIT: '345'
 def
Number count: '2'
```

The first out put is our printf showing this is the user code section being run.

The lexer than acutually starts and awaits input.

'abc 123' the abc has no digits so is returned. The 123 is printed as a single value.

This is the same for '345 def' the 345 is printed as a single value and the def is returned.

Ctrl+d is then entered to signify end of file.

The final value of varriable num_count is printed.

## yylex()
You will see in the main function a call to yylex(). This starts the actual lexer which was being invoked automatically in the previous examples. If this line is not present then the program essentially just prints out a zero number count and returns.