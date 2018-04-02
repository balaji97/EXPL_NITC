%{

	#include <stdio.h>
	#include "y.tab.h"
	#include <stdlib.h>
	#include <string.h>
	
	#define NODE_ID 0
	#define NODE_NUM 1
	#define NODE_STR 2

	#define inttype 100
	#define strtype 101
	#define booltype 102

	int yywrap(void);

	int intval;
	char *strval;
    
%}

%%

[0-9]+ 	{
		intval=atoi(yytext);
		yylval=createTree(intval, inttype, NULL, NODE_NUM, NULL, NULL, NULL);
		return NUM;
	}
"begin"	{return START;}
"end"	{return END;}
"decl"	{return DECL;}
"enddecl"	{return ENDDECL;}
"type"	{return TYPE;}
"endtype"	{return ENDTYPE;}
"main"	{return MAIN;}
"return"	{return RETURN;}
"int"	{return INT;}
"str"	{return STR;}
"read"	{return READ;}
"write"	{return WRITE;}
"if" 	{return IF;}
"then"	{return THEN;}
"else"	{return ELSE;}
"endif"	{return ENDIF;}
"while"	{return WHILE;}
"do"	{return DO;}
"break"	{return BREAK;}
"continue"	{return CONTINUE;}
"endwhile"	{return ENDWHILE;}
"repeat"	{return REPEAT;}
"until"	{return UNTIL;}
"breakpoint"	{return BRKP;}
"AND"	{return AND;}
"OR"	{return OR;}
"NOT"	{return NOT;}
"null"	{return NULLSTMT;}
[a-zA-Z]([a-zA-Z0-9]*)	{
		strval=strdup(yytext);
		yylval=createTree(0, inttype, strval, NODE_ID, NULL, NULL, NULL);
		return ID;
	}
\"(\\.|[^\\\"])*\" {
		strval=malloc((yyleng-2)*sizeof(char));
		strcpy(strval, yytext+1);
		strval[yyleng-2]='\0';
		yylval=createTree(0, strtype, strval, NODE_STR, NULL, NULL, NULL);
		return STRVAL;
	}
"="	{return ASSIGN;}
"+" 	{return PLUS;}
"-" 	{return MINUS;}
"*" 	{return MUL;}
"/"	{return DIV;}
"%"	{return MOD;}
"<"	{return LT;}
">"	{return GT;}
"<="	{return LE;}
">="	{return GE;}
"!="	{return NE;}
"=="	{return EQ;}
[\n \t] {}
"["	{return *yytext;}
"]"	{return *yytext;}
[{}()]	{return *yytext;}
[&,;\".] {return *yytext;}
. 	{
		yyerror(strcat(yytext, " : unknown charcter"));
		exit(1);
	}

%%

int yywrap(void){
	return 1;
}
