%{
	#include<stdio.h>

	int l,w,c;
%}

%%

[a-zA-Z0-9]	{c++;}
[ \t]		{w++;}
[\n]		{l++; w++;}
(.)		{}

%%

int yywrap(){
	return 1;
}

int main(){
	l=w=c=0;
	yyin = fopen("input.l","r");
	yylex();
	printf("Lines:- %d\nWords:-  %d\nCharacters:- %d\n",l,w,c);
	return 1;
}
