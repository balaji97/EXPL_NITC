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
    struct varList *list = NULL, *node = NULL;
    struct paramList *plist = NULL, *pnode = NULL;

%}
%token START
%token END
%token DECL
%token ENDDECL
%token IF
%token THEN
%token ELSE
%token ENDIF
%token WHILE
%token DO
%token ENDWHILE
%token BREAK CONTINUE
%token ID NUM INT STR 
%token READ WRITE ASSIGN 
%left PLUS MINUS
%left MUL DIV
%nonassoc LT LE GT GE NE EQ

%%

program: GDeclBlock FDefBlock MainBlock
        |GDeclBlock MainBlock
        |MainBlock
        ;

FDefBlock:  FDefBlock Fdef
            | Fdef 
            ;
MainBlock: instructions{exit(1);}
            ;
Fdef:       Type ID '(' ParamList ')' '{' instructions '}'   {functionCheck($2, plist, $1->type);printLocalTable();plist = NULL;deallocateLocalTable();}
            ;

GDeclBlock:  
             DECL GDeclList ENDDECL  {printSymbolTable();}
            |DECL ENDDECL           {}
            ;
GDeclList:  GDeclList GDecl 
            | GDecl
            ;
GDecl:      Type GidList ';'        {declareVariables($1->type, list);node=list=NULL;}
            ;
            
GidList:    GidList ',' Gid         {if(node)list = appendVariable(list, node);}
            | Gid                   {if(node)list = node;}
            ;

instructions:   START LDeclBlock Slist END	{printf("Ping\n");}
            | START LDeclBlock END	{print(NULL);}
            | START Slist END      {print($2);} 
	       | START END		{print(NULL );}    
           ;
           
LDeclBlock: DECL LDeclList ENDDECL  {}
            |DECL ENDDECL           {}
            ;
LDeclList:  LDeclList LDecl
            | LDecl
            ;
            
LDecl:      Type LidList ';'        {declareLocalVariables($1->type, list);node=list=NULL;}

LidList:    LidList ',' Gid         {if(node)list = appendVariable(list, node);}
            | Gid                   {if(node)list = node;}
            ;
Gid:        
             ID '[' NUM ']' '[' NUM ']'    {int size = $3->val;size *= $6->val;if(size <= 0)yyerror("Invalid array declaration\n"); node = makeVarList($1, size, $3->val, 0, NULL);}
            | ID '[' NUM ']'        {if($3->val <= 0)yyerror("Invalid array declaration\n");node = makeVarList($1, $3->val, 1, 0, NULL);}
            | ID '(' ParamList ')'  {node = makeVarList($1, -1, 1, 0, plist);}
            | MUL ID                {node = makeVarList($1, 1, 1, 1, NULL);}
            | ID                      {node = makeVarList($1, 1, 1, 0, NULL);}
            ;
Type:       INT                     {$$ = createTree(0, NODE_AUX, TYPE_INT, NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
            |STR                    {$$ = createTree(0, NODE_AUX, TYPE_STR, NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
            ;

ParamList:  ParamList ',' Param     {plist = appendParam(plist, pnode);}
            |Param                  {plist = pnode;}
            |
            ;
Param:      Type ID                 {pnode = makeParamList($2->varname, $1->type);}
            ;

Slist :	Slist Stmt	{$$=createTree(0, NODE_CONN, TYPE_NULL, NULL, $1, $2, NULL, NULL, NULL, NULL);printf("Ping\n");}
	| Stmt		{$$=$1;}
	;
    

Stmt :	InputStmt {$$=$1;}| OutputStmt {$$=$1;}| AsgStmt {$$=$1;}| IfStmt {$$=$1;}| WhileStmt	{$$=$1;} | ContinueStmt {$$ = $1;} | BreakStmt {$$ = $1;} | CallStmt {$$ = $1;}
	;
    

InputStmt : READ '(' AsgE ')' ';'	{$$=createTree(0, NODE_READ, TYPE_NULL, NULL, $3, NULL, NULL, NULL, NULL, NULL);}
	;
    

OutputStmt : WRITE '(' E ')' ';'{$$=createTree(0, NODE_WRITE, TYPE_NULL, NULL, $3, NULL, NULL, NULL, NULL, NULL);}
	;
    

AsgStmt : AsgE ASSIGN E ';'	{$$=createTree(0, NODE_ASSIGN, TYPE_AUX, NULL, $1, $3, NULL, NULL, NULL, NULL);}
	;
    

IfStmt  : IF '(' E ')' THEN Slist ELSE Slist ENDIF ';' {$$ = createTree(0, NODE_IF, TYPE_NULL, NULL, $3, $6, $8, NULL, NULL, NULL);}
        | IF '(' E ')' THEN Slist ENDIF ';'            {$$ = createTree(0, NODE_IF, TYPE_NULL, NULL, $3, $6, NULL, NULL, NULL, NULL);}
        ;
        
        
WhileStmt : WHILE '(' E ')' DO Slist ENDWHILE ';'     {$$ = createTree(0, NODE_WHILE, TYPE_NULL, NULL, $3, $6, NULL, NULL, NULL, NULL);}
            ;
            
            
BreakStmt : BREAK ';'                               {$$ = createTree(0, NODE_BREAK, TYPE_NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
            ;
            
            
ContinueStmt : CONTINUE ';'                         {$$ = createTree(0, NODE_CONTINUE, TYPE_NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
            ;
                   
E : CallStmt    {$$ = $1;}
    | E PLUS E 	{$$=createTree(0, NODE_PLUS, TYPE_INT, NULL, $1, $3, NULL, NULL, NULL, NULL);}
	| E MINUS E {$$=createTree(0, NODE_MINUS, TYPE_INT, NULL, $1, $3, NULL, NULL, NULL, NULL);}
	| E MUL E 	{$$=createTree(0, NODE_MUL, TYPE_INT, NULL, $1, $3, NULL, NULL, NULL, NULL);}
	| E DIV E 	{$$=createTree(0, NODE_DIV, TYPE_INT, NULL, $1, $3, NULL, NULL, NULL, NULL);}
    | E LT E 	{$$=createTree(0, NODE_LT, TYPE_BOOL, NULL, $1, $3, NULL, NULL, NULL, NULL);}
    | E LE E 	{$$=createTree(0, NODE_LE, TYPE_BOOL, NULL, $1, $3, NULL, NULL, NULL, NULL);}
	| E GT E 	{$$=createTree(0, NODE_GT, TYPE_BOOL, NULL, $1, $3, NULL, NULL, NULL, NULL);}
    | E GE E 	{$$=createTree(0, NODE_GE, TYPE_BOOL, NULL, $1, $3, NULL, NULL, NULL, NULL);}
    | E NE E 	{$$=createTree(0, NODE_NE, TYPE_BOOL, NULL, $1, $3, NULL, NULL, NULL, NULL);}
    | E EQ E 	{$$=createTree(0, NODE_EQ, TYPE_BOOL, NULL, $1, $3, NULL, NULL, NULL, NULL);}
    | '(' E ')' {$$=$2;}
	| NUM       {$$ = $1;}
    | '&' ID    {$$ = createTree(lookup($2->varname)->binding, NODE_NUM, TYPE_INT, NULL, NULL, NULL, NULL, NULL, NULL, NULL);}
    | AsgE      {$$ = $1;}
	;
    
CallStmt : ID '(' ExprList ')' ';'  {struct Gsymbol *temp = lookup($1->varname);$$ = createTree(0, NODE_FCALL, temp->type, temp->name, NULL, NULL, NULL, NULL, NULL, $3); list = NULL;}
    ;
ExprList : ExprList ',' E   {$$ = createTree(0, NODE_CONN, TYPE_NULL, NULL, $1, $2, NULL, NULL, NULL, NULL);}
            | E    {$$ = $1;}
    
AsgE:   | ID	    {$$=$1;}
        | ID '[' E ']'  
        {
            if($3->type != TYPE_INT)
                yyerror("Invalid array index\n");
            $$ = $1;
            $$->index1 = $3;
            $$->index2 = NULL;
        }
        | ID '[' E ']' '[' E ']' 
        {
            if($3->type != TYPE_INT || $6->type != TYPE_INT)
                yyerror("Invalid array index\n");
            $$ = $1; 
            $$->index1 = $3; 
            $$->index2 = $6;
        }
        | MUL ID
        {
            $$ = $2;
            $$->nodetype = NODE_PTR;
        }
    ;
    
    
%%

void yyerror(char const *s)
{
	printf("yyerror %s\n",s);
    exit(0);
}

int main(int argc, char* argv[])
{
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
