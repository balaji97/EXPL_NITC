%{
	#include<stdio.h>
%}

%%

[A][a-zA-Z][a-zA-Z][\n \t]	{printf("%s\n",yytext);}
[\n \t]				{}
(.)				{}

%%

int yywrap(){
	return 1;
}

int main(){
	yyin = fopen("input.l","r");
	yylex();
	return 1;
}
