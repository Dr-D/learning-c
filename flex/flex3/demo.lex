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
