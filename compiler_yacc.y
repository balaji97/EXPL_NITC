%{

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	
	#define YYSTYPE tnode*
	#define reg_index int

	#include "exprtree.h"
	#include "exprtree.c"

	int yylex(void);
	extern FILE *yyin;
    void yyerror(char const *s);

%}

%token ID NUM START END READ WRITE ASSIGN PLUS MINUS MUL DIV IF THEN ELSE ENDIF WHILE DO ENDWHILE BREAK CONTINUE DECL ENDDECL INT STR 
%left PLUS MINUS
%left MUL DIV
%nonassoc LT LE GT GE NE EQ

%%

program: Declarations instructions | instructions;
instructions:   START Slist END	{print($2); exit(1);}
	       | START END		{print(NULL); exit(1);}    

Declarations :  DECL DeclList ENDDECL    {printSymbolTable();$$ = NULL;}
                | DECL ENDDECL          {$$ = NULL;}
                ;
DeclList    :   DeclList Decl            {$$ = NULL;}
                | Decl                  {$$ = NULL;}
                ;
Decl        :   Type VarList ';'        {printf("Declaring %d\n", $1);declareVariables($1, $2);$$ = NULL;}
                ;
Type        :   INT {$$ = TYPE_INT;}
                | STR {$$ = TYPE_STR;}
            ;
VarList     :   VarList ',' ID {$$ = appendVariable($1, $3);}
                | ID {$$ = makeVarList($1);}
                ;

	;
Slist :	Slist Stmt	{$$=createTree(0, NODE_CONN, TYPE_NULL, NULL, $1, $2, NULL);}
	| Stmt		{$$=$1;}
	;

Stmt :	InputStmt {$$=$1;}| OutputStmt {$$=$1;}| AsgStmt {$$=$1;}| IfStmt {$$=$1;}| WhileStmt	{$$=$1;} | ContinueStmt {$$ = $1;} | BreakStmt {$$ = $1;} 
	;

InputStmt : READ '(' ID ')' ';'	{$$=createTree(0, NODE_READ, TYPE_NULL, NULL, $3, NULL, NULL);}
	;

OutputStmt : WRITE '(' E ')' ';'{$$=createTree(0, NODE_WRITE, TYPE_NULL, NULL, $3, NULL, NULL);}
	;

AsgStmt : ID ASSIGN E ';'	{$$=createTree(0, NODE_ASSIGN, TYPE_INT, NULL, $1, $3, NULL);}
	;

IfStmt  : IF '(' E ')' THEN Slist ELSE Slist ENDIF ';' {$$ = createTree(0, NODE_IF, TYPE_NULL, NULL, $3, $6, $8);}
        | IF '(' E ')' THEN Slist ENDIF ';'            {$$ = createTree(0, NODE_IF, TYPE_NULL, NULL, $3, $6, NULL);}
        ;
WhileStmt : WHILE '(' E ')' DO Slist ENDWHILE ';'     {$$ = createTree(0, NODE_WHILE, TYPE_NULL, NULL, $3, $6, NULL);}
            ;
BreakStmt : BREAK ';'                               {$$ = createTree(0, NODE_BREAK, TYPE_NULL, NULL, NULL, NULL, NULL);}
            ;
ContinueStmt : CONTINUE ';'                         {$$ = createTree(0, NODE_CONTINUE, TYPE_NULL, NULL, NULL, NULL, NULL);}
            ;
E :   E PLUS E 	{$$=createTree(0, NODE_PLUS, TYPE_INT, NULL, $1, $3, NULL);}
	| E MINUS E {$$=createTree(0, NODE_MINUS, TYPE_INT, NULL, $1, $3, NULL);}
	| E MUL E 	{$$=createTree(0, NODE_MUL, TYPE_INT, NULL, $1, $3, NULL);}
	| E DIV E 	{$$=createTree(0, NODE_DIV, TYPE_INT, NULL, $1, $3, NULL);}
    | E LT E 	{$$=createTree(0, NODE_LT, TYPE_BOOL, NULL, $1, $3, NULL);}
    | E LE E 	{$$=createTree(0, NODE_LE, TYPE_BOOL, NULL, $1, $3, NULL);}
	| E GT E 	{$$=createTree(0, NODE_GT, TYPE_BOOL, NULL, $1, $3, NULL);}
    | E GE E 	{$$=createTree(0, NODE_GE, TYPE_BOOL, NULL, $1, $3, NULL);}
    | E NE E 	{$$=createTree(0, NODE_NE, TYPE_BOOL, NULL, $1, $3, NULL);}
    | E EQ E 	{$$=createTree(0, NODE_EQ, TYPE_BOOL, NULL, $1, $3, NULL);}
    | '(' E ')' {$$=$2;}
	| NUM | ID	{$$=$1;}
	;
%%

void yyerror(char const *s){
	printf("yyerror %s\n",s);
    exit(0);
}

int main(int argc, char* argv[]){
	reg=-1;
	if(argc>1){
		fp=fopen(argv[1], "r");
		if(fp)
			yyin=fp;
	}
	target_file=fopen("test.xsm","w");
	yyparse();
	return 0;
}
