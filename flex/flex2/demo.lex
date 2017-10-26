/*Defintions*/
%{
int num = 0;
%}

DIGIT  [0-9]

%%
 /*rules*/
{DIGIT} { num++; printf("DIGIT: '%s', count: '%d'\n", yytext, num); }

%%
