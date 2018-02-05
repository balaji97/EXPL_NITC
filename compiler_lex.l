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
    
    #define TYPE_STR 104    
	int intval;
	char *strval;
	
%}

%%



[0-9]+ {
		intval=atoi(yytext);
		yylval=createTree(intval, NODE_NUM, TYPE_INT, NULL, NULL, NULL, NULL, NULL, NULL);
		return NUM;}
"begin"	{return START;}
"end"	{return END;}
"decl"  {return DECL;}
"enddecl" {return ENDDECL;}
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
"int"   {return INT;}
"string"    {return STR;}

[a-z]+ {
		strval=strdup(yytext);
		yylval=createTree(0, NODE_VAR, TYPE_INT, strval, NULL, NULL, NULL, NULL, NULL);
		return ID;}
["']([a-z0-9A-Z .,+\-*/=_:><?!@#$%^&\t\n]+)["'] {
                    strval = strdup(yytext);
                    yylval = createTree(0, NODE_NUM, TYPE_STR, strval, NULL, NULL, NULL, NULL, NULL);
                    return NUM;
}
    
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
[();,\[\]] 	{return *yytext;}
. 	{
		yyerror("unknown character\n");
		exit(1);
	}

%%

int yywrap(void){
	return 1;
}
