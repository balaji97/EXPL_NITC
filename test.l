%{

	#include <stdio.h>
	#include "y.tab.h"
	#include <stdlib.h>
	#include <string.h>
	
    #define NODE_VAR 0
    #define NODE_NUM 1
    
    #define TYPE_INT 101
    #define TYPE_BOOL 102
    #define TYPE_NULL 103

	int intval;
	char *strval;
	
%}

%%



[0-9]+ {
		intval=atoi(yytext);
		yylval=createTree(intval, NODE_NUM, TYPE_INT, NULL, NULL, NULL, NULL);
		return NUM;}
"begin"	{return START;}
"end"	{return END;}
"read"	{return READ;}
"write"	{return WRITE;}
"if"    {return IF;}
"then"    {return THEN;}
"else"    {return ELSE;}
"endif"    {return ENDIF;}
"break"    {return BREAK;}
"continue"    {return CONTINUE;}
"while"    {return WHILE;}
"do"    {return DO;}
"endwhile"    {return ENDWHILE;}

[a-z] {
		strval=strdup(yytext);
		yylval=createTree(0, NODE_VAR, TYPE_INT, strval, NULL, NULL, NULL);
		return ID;}
    
"="	{return ASSIGN;}
"+" 	{return PLUS;}
"-" 	{return MINUS;}
"*" 	{return MUL;}
"/"	{return DIV;}

"<"  	{return LT;}
"<="	{return LE;}
">" 	{return GT;}
">="	{return GE;}
"=="	{return EQ;}
"!="	{return NE;}

[\n \t] {}
[();] 	{return *yytext;}
. 	{
		yyerror("unknown character\n");
		exit(1);
	}

%%

int yywrap(void){
	return 1;
}
