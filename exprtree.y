%{

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	
	#define YYSTYPE tnode*

	#include "exprtree.h"
	#include "exprtree.c"

	int yylex(void);
	void yyerror(char const *s);
	extern FILE *yyin;
	
%}

%token ID NUM STRVAL START END READ WRITE ASSIGN
%token DECL ENDDECL INT STR BRKP MAIN RETURN TYPE ENDTYPE
%token IF THEN ELSE ENDIF WHILE DO ENDWHILE BREAK CONTINUE REPEAT UNTIL
%token PLUS MINUS MUL DIV MOD LT GT LE GE NE EQ AND OR NOT NULLSTMT
%left OR
%left AND
%left PLUS MINUS
%left MUL DIV MOD
%right NOT
%nonassoc LT GT LE GE NE EQ

%%

program :  TypeDefBlock GDeclBlock FDefBlock MainBlock
	| GDeclBlock FDefBlock MainBlock
	| TypeDefBlock FDefBlock MainBlock
	| TypeDefBlock GDeclBlock MainBlock
	| GDeclBlock MainBlock
	| TypeDefBlock MainBlock
	| FDefBlock MainBlock
    | MainBlock
	;
    
TypeDefBlock : TYPE TypeDefList ENDTYPE {printTypeTable();}
                ;
                
TypeDefList : TypeDefList TypeDef
            | TypeDef
            ;

TypeDef     : ID '{' FieldDeclList '}'  {TInstall($1->varname, Fhead->fieldIndex, Fhead);}
            ;
        
FieldDeclList : FieldDeclList FieldDecl {Fhead = FAppend(Fentry, Fhead);}
                | FieldDecl             {Fhead = Fentry;}
                ;

FieldDecl       : TypeName ID ';'       {Fentry = FCreate($2->varname, declType);}
                ;
                

GDeclBlock : DECL GDeclList ENDDECL	{
			evaluate();
			binding=1;
		}
	| DECL ENDDECL			{
			evaluate();
			binding=1;
		}
	;

GDeclList : GDeclList GDecl
	| GDecl
	;

GDecl : Type GidList ';'
	;
    

TypeName : INT 	{declType=TLookup(inttype);}
	| STR	{declType=TLookup(strtype);}
	| ID	
    { 
        if(TLookup($1->varname) == NULL)
        {
            declType = TLookup(temptype);
        }
        else
            declType=TLookup($1->varname);
    }
	;
    
Type : INT 	{declType=TLookup(inttype);}
	| STR	{declType=TLookup(strtype);}
	| ID	
    { 
        if(TLookup($1->varname) == NULL)
        {
            printf("Undeclared type %s\n", $1->varname);
            exit(1);
        }
        declType=TLookup($1->varname);
    }
	;
    

GidList : GidList ',' Gid
	| Gid
	;

Gid : ID				{GInstall($1->varname, declType, 1, 1, NODE_ID, NULL);}
	| ID '[' NUM ']'		{GInstall($1->varname, declType, $3->val, 1, NODE_ARRAY, NULL);}
	| ID '[' NUM ']' '[' NUM ']'	{GInstall($1->varname, declType, $3->val, $6->val, NODE_MATRIX, NULL);}
	| MUL ID			{GInstall($2->varname, declType, 1, 1, NODE_PTR, NULL);}
	| ID '(' ParamList ')'		{
						GInstall($1->varname, declType, 0, 0, NODE_FUNC, Phead);
						Phead=Ptail=NULL;
					}
	| MUL ID '(' ParamList ')'	{
						GInstall($2->varname, declType, 0, 0, NODE_FUNC, Phead);	
						Phead=Ptail=NULL;
					}
	| ID '(' ')'			{GInstall($1->varname, declType, 0, 0, NODE_FUNC, NULL);}
	| MUL ID '(' ')'		{GInstall($2->varname, declType, 0, 0, NODE_FUNC, NULL);}
	;

FDefBlock : FDefBlock FDef
	| FDef
	;

FDef : Type ID '(' ParamList ')' '{' LDeclBlock Body '}'	{
			struct Lsymbol *Ltemp;
			struct Gsymbol *Gtemp;
			struct Paramstruct *Ptemp1, *Ptemp2;
			functype=declType;
			binding=1;

			Gtemp=GLookup($2->varname);
			if(Gtemp==NULL || Gtemp->nodetype!=NODE_FUNC){
				printf("Function not declared: %s\n", $2->varname);
				exit(1);
			}
			if(Gtemp->size1!=0){
				printf("Multiple Function Declaration: %s\n", $2->varname);
				exit(1);
			}
			Gtemp->size1--;
			$2->Lentry=Lhead;

			Ptemp1=Phead;
			Ptemp2=Gtemp->paramlist;

			while(Ptemp1!=NULL && Ptemp2!=NULL){
				if(Ptemp1->type!=Ptemp2->type || strcmp(Ptemp1->name, Ptemp2->name) || Ptemp1->nodetype!=Ptemp2->nodetype){
					printf("Incorrect Parameter List\n");
					exit(1);
				}
				Ptemp1=Ptemp1->next;
				Ptemp2=Ptemp2->next;
			}

			if(Ptemp1!=NULL || Ptemp2!=NULL){
				printf("Incorrect Parameter List\n");
				exit(1);
			}

			fprintf(target_file, "F%d:\n", Gtemp->flabel);
			fprintf(target_file, "PUSH BP\n");
			fprintf(target_file, "MOV BP, SP\n");

			lcount=0;
			Ltemp=Lhead;
			while(Ltemp!=NULL){
				lcount++;
				Ltemp=Ltemp->next;
			}
			fprintf(target_file, "ADD SP, %d\n", lcount);

			codeGen($8);

			fprintf(target_file, "SUB SP, %d\n", lcount);
			fprintf(target_file, "MOV BP, [SP]\n");
			fprintf(target_file, "POP R0\n");
			fprintf(target_file, "RET\n");

			Lhead=Ltail=NULL;
			Phead=Ptail=NULL;
		}
	| Type ID '(' ')' '{' LDeclBlock Body '}'	{
			struct Lsymbol *Ltemp;
			struct Gsymbol *Gtemp;
			functype=declType;
			binding=1;

			Gtemp=GLookup($2->varname);
			if(Gtemp==NULL || Gtemp->nodetype!=NODE_FUNC){
				printf("Function not declared: %s\n", $2->varname);
				exit(1);
			}
			if(Gtemp->size1!=0){
				printf("Multiple Function Declaration: %s\n", $2->varname);
				exit(1);
			}
			Gtemp->size1--;
			$2->Lentry=Lhead;

			if(Gtemp->paramlist!=NULL){
				printf("Parameter List is not NULLs\n");
				exit(1);
			}

			fprintf(target_file, "F%d:\n", Gtemp->flabel);
			fprintf(target_file, "PUSH BP\n");
			fprintf(target_file, "MOV BP, SP\n");

			lcount=0;
			Ltemp=Lhead;
			while(Ltemp!=NULL){
				lcount++;
				Ltemp=Ltemp->next;
			}
			fprintf(target_file, "ADD SP, %d\n", lcount);

			codeGen($7);

			fprintf(target_file, "SUB SP, %d\n", lcount);
			fprintf(target_file, "MOV BP, [SP]\n");
			fprintf(target_file, "POP R0\n");
			fprintf(target_file, "RET\n");

			Lhead=Ltail=NULL;
			Phead=Ptail=NULL;
		}
	| Type MUL ID '(' ParamList ')' '{' LDeclBlock Body '}'	{
			struct Lsymbol *Ltemp;
			struct Gsymbol *Gtemp;
			struct Paramstruct *Ptemp1, *Ptemp2;
			functype=declType;
			binding=1;

			Gtemp=GLookup($3->varname);
			if(Gtemp==NULL || Gtemp->nodetype!=NODE_FUNC){
				printf("Function not declared: %s\n", $3->varname);
				exit(1);
			}
			if(Gtemp->size1!=0){
				printf("Multiple Function Declaration: %s\n", $3->varname);
				exit(1);
			}
			Gtemp->size1--;
			$3->Lentry=Lhead;

			Ptemp1=Phead;
			Ptemp2=Gtemp->paramlist;

			while(Ptemp1!=NULL && Ptemp2!=NULL){
				if(Ptemp1->type!=Ptemp2->type || strcmp(Ptemp1->name, Ptemp2->name) || Ptemp1->nodetype!=Ptemp2->nodetype){
					printf("Incorrect Parameter List\n");
					exit(1);
				}
				Ptemp1=Ptemp1->next;
				Ptemp2=Ptemp2->next;
			}

			if(Ptemp1!=NULL || Ptemp2!=NULL){
				printf("Incorrect Parameter List\n");
				exit(1);
			}

			fprintf(target_file, "F%d:\n", Gtemp->flabel);
			fprintf(target_file, "PUSH BP\n");
			fprintf(target_file, "MOV BP, SP\n");

			lcount=0;
			Ltemp=Lhead;
			while(Ltemp!=NULL){
				lcount++;
				Ltemp=Ltemp->next;
			}
			fprintf(target_file, "ADD SP, %d\n", lcount);

			codeGen($9);

			fprintf(target_file, "SUB SP, %d\n", lcount);
			fprintf(target_file, "MOV BP, [SP]\n");
			fprintf(target_file, "POP R0\n");
			fprintf(target_file, "RET\n");

			Lhead=Ltail=NULL;
			Phead=Ptail=NULL;
		}
	| Type MUL ID '(' ')' '{' LDeclBlock Body '}'	{
			struct Lsymbol *Ltemp;
			struct Gsymbol *Gtemp;
			functype=declType;
			binding=1;

			Gtemp=GLookup($3->varname);
			if(Gtemp==NULL || Gtemp->nodetype!=NODE_FUNC){
				printf("Function not declared: %s\n", $3->varname);
				exit(1);
			}
			if(Gtemp->size1!=0){
				printf("Multiple Function Declaration: %s\n", $3->varname);
				exit(1);
			}
			Gtemp->size1--;
			$3->Lentry=Lhead;

			if(Gtemp->paramlist!=NULL){
				printf("Parameter List is not NULLs\n");
				exit(1);
			}

			fprintf(target_file, "F%d:\n", Gtemp->flabel);
			fprintf(target_file, "PUSH BP\n");
			fprintf(target_file, "MOV BP, SP\n");

			lcount=0;
			Ltemp=Lhead;
			while(Ltemp!=NULL){
				lcount++;
				Ltemp=Ltemp->next;
			}
			fprintf(target_file, "ADD SP, %d\n", lcount);

			codeGen($8);

			fprintf(target_file, "SUB SP, %d\n", lcount);
			fprintf(target_file, "MOV BP, [SP]\n");
			fprintf(target_file, "POP R0\n");
			fprintf(target_file, "RET\n");

			Lhead=Ltail=NULL;
			Phead=Ptail=NULL;
		}
	;
ParamList : ParamList ',' Param
	| Param
	;

Param : PType ID	{
			struct Paramstruct *Ptemp;
			Ptemp=PLookup($2->varname);
			if(Ptemp!=NULL){
				printf("Multiple variable declaration: %s\n", $2->varname);
				exit(1);
			}
			PInstall($2->varname, PdeclType, NODE_ID);
		}
	| PType MUL ID	{
			struct Paramstruct *Ptemp;
			Ptemp=PLookup($3->varname);
			if(Ptemp!=NULL){
				printf("Multiple variable declaration: %s\n", $3->varname);
				exit(1);
			}
			PInstall($3->varname, PdeclType, NODE_PTR);
		}
	;

PType : INT 	{PdeclType=TLookup(inttype);}
	| STR	{PdeclType=TLookup(strtype);}
	;

LDeclBlock : DECL LDeclList ENDDECL
	| DECL ENDDECL
	;

LDeclList : LDeclList LDecl
	| LDecl
	;

LDecl : Type IdList ';'
	;

IdList : IdList ',' ID		{LInstall($3->varname, declType, NODE_ID);}
	| IdList ',' MUL ID	{LInstall($4->varname, declType, NODE_PTR);}
	| ID			{LInstall($1->varname, declType, NODE_ID);}
	| MUL ID		{LInstall($2->varname, declType, NODE_PTR);}
	;

MainBlock : INT MAIN '(' ')' '{' LDeclBlock Body '}'	{
			struct Lsymbol *Ltemp;
			struct Gsymbol *Gtemp;
			functype=TLookup(inttype);
			binding=1;

			Gtemp=Ghead;
			while(Gtemp!=NULL){
				if(Gtemp->size1==0){
					printf("Function not declared: %s\n", Gtemp->name);
					exit(1);
				}
				Gtemp=Gtemp->next;
			}

			fprintf(target_file, "MAIN:\n");
			fprintf(target_file, "PUSH BP\n");
			fprintf(target_file, "MOV BP, SP\n");

			lcount=0;
			Ltemp=Lhead;
			while(Ltemp!=NULL){
				lcount++;
				Ltemp=Ltemp->next;
			}
			fprintf(target_file, "ADD SP, %d\n", lcount);

			codeGen($7);

			fprintf(target_file, "SUB SP, %d\n", lcount);
			fprintf(target_file, "MOV BP, [SP]\n");
			fprintf(target_file, "POP R0\n");
			fprintf(target_file, "RET\n");

			Lhead=Ltail=NULL;
			Phead=Ptail=NULL;
		}
	;

Body : START Slist RetStmt END	{$$=createTree(0, TLookup(nulltype), NULL, NODE_CONN, $2, $3, NULL);}
	| START RetStmt END	{$$=createTree(0, TLookup(nulltype), NULL, NODE_CONN, $2, NULL, NULL);}
	;

Slist :	Slist Stmt	{$$=createTree(0, TLookup(nulltype), NULL, NODE_CONN, $1, $2, NULL);}
	| Stmt		{$$=$1;}
	;

Stmt :	InputStmt | OutputStmt | AsgStmt | IfStmt | WhileStmt	{$$=$1;}
	| BREAK ';'	{$$=createTree(0, TLookup(nulltype), NULL, NODE_BREAK, NULL, NULL, NULL);}
	| CONTINUE ';'	{$$=createTree(0, TLookup(nulltype), NULL, NODE_CONTINUE, NULL, NULL, NULL);}
	| BRKP ';'	{$$=createTree(0, TLookup(nulltype), NULL, NODE_BRKP, NULL, NULL, NULL);}
	;

InputStmt : READ '(' ID ')' ';'		{
				idCheck($3, NODE_ID);
				$$=createTree(0, TLookup(nulltype), NULL, NODE_READ, $3, NULL, NULL);
			}
	| READ '(' ID '[' Expr ']' ')' ';'	{
				idCheck($3, NODE_ARRAY);
				typeCheck($5->type, NULL, NODE_ARRAY);
				$$=createTree(0, TLookup(nulltype), NULL, NODE_READ_ARRAY, $3, $5, NULL);
			}
	| READ '(' ID '[' Expr ']' '[' Expr ']' ')' ';'	{
				idCheck($3, NODE_MATRIX);
				typeCheck($5->type, $8->type, NODE_MATRIX);
				$$=createTree(0, TLookup(nulltype), NULL, NODE_READ_MATRIX, $3, $5, $8);
			}
	| READ '(' MUL ID ')' ';'		{
				idCheck($4, NODE_PTR);
				$$=createTree(0, TLookup(nulltype), NULL, NODE_READ_PTR, $4, NULL, NULL);
			}
    | READ '(' Field ')' ';'
    {
        $$ = createTree(0, TLookup(nulltype), NULL, NODE_READ_FIELD, $3, NULL, NULL);
    }
	;

OutputStmt : WRITE '(' Expr ')' ';'	{$$=createTree(0, TLookup(nulltype), NULL,  NODE_WRITE, $3, NULL, NULL);}
	;

AsgStmt : ID ASSIGN Expr ';' {
				idCheck($1, NODE_ID);
				typeCheck($1->type, $3->type, NODE_ASSIGN);
				$$=createTree(0, TLookup(nulltype), NULL, NODE_ASSIGN, $1, $3, NULL); 
			}
	| ID '[' Expr ']' ASSIGN Expr ';'	{
				idCheck($1, NODE_ARRAY);
				typeCheck($3->type, NULL, NODE_ARRAY);
				typeCheck($1->type, $6->type, NODE_ASSIGN);
				$$=createTree(0, TLookup(nulltype), NULL, NODE_ASSIGN_ARRAY, $1, $3, $6);
			}
	| ID '[' Expr ']' '[' Expr ']' ASSIGN Expr ';'	{
				idCheck($1, NODE_MATRIX);
				typeCheck($3->type, $6->type, NODE_MATRIX);
				typeCheck($1->type, $9->type, NODE_ASSIGN);
				$$=createTree(0, TLookup(nulltype), NULL, NODE_ASSIGN_MATRIX, $1, createTree(0, 0, NULL, NODE_CONN, $3, $6, NULL),$9);
			}
	| MUL ID ASSIGN Expr ';'	{
				idCheck($2, NODE_PTR);
				typeCheck($2->type, $4->type, NODE_ASSIGN);
				$$=createTree(0, TLookup(nulltype), NULL, NODE_ASSIGN_PTR, $2, $4, NULL);
			}
    | Field ASSIGN Expr ';'
    {
        typeCheck($1->type, $3->type, NODE_ASSIGN);
        $$ = createTree(0, TLookup(nulltype), NULL, NODE_ASSIGN_FIELD, $1, $3, NULL);
    }
	;

IfStmt : IF '(' Expr ')' THEN Slist ELSE Slist ENDIF ';'	{$$=createTree(0, 0, NULL, NODE_ELIF, $3, $6, $8);}
	| IF '(' Expr ')' THEN Slist ENDIF ';'		{$$=createTree(0, 0, NULL, NODE_IF, $3, $6, NULL);}
	;

WhileStmt : WHILE '(' Expr ')' DO Slist ENDWHILE ';'	{$$=createTree(0, 0, NULL, NODE_WHILE, $3, $6, NULL);}
	| DO Slist WHILE '(' Expr ')' ';'		{$$=createTree(0, 0, NULL, NODE_DO_WHILE, $2, $5, NULL);}
	| REPEAT Slist UNTIL '(' Expr ')' ';'		{$$=createTree(0, 0, NULL, NODE_REPEAT, $2, $5, NULL);}
	;

Expr : 	Expr PLUS Expr 	{
				typeCheck($1->type, $3->type, NODE_PLUS);
				$$=createTree(0, TLookup(inttype), NULL, NODE_PLUS, $1, $3, NULL);
			}
	| Expr MINUS Expr 	{
				typeCheck($1->type, $3->type, NODE_MINUS);
				$$=createTree(0, TLookup(inttype), NULL, NODE_MINUS, $1, $3, NULL);
			}
	| Expr MUL Expr 	{
				typeCheck($1->type, $3->type, NODE_MUL);
				$$=createTree(0, TLookup(inttype), NULL, NODE_MUL, $1, $3, NULL);
			}
	| Expr DIV Expr 	{
				typeCheck($1->type, $3->type, NODE_DIV);
				$$=createTree(0, TLookup(inttype), NULL, NODE_DIV, $1, $3, NULL);
			}
	| Expr MOD Expr	{
				typeCheck($1->type, $3->type, NODE_MOD);
				$$=createTree(0, TLookup(inttype), NULL, NODE_MOD, $1, $3, NULL);
			}
	| Expr LT Expr	{
				typeCheck($1->type, $3->type, NODE_LT);
				$$=createTree(0, TLookup(booltype), NULL, NODE_LT, $1, $3, NULL);
			}
	| Expr GT Expr	{
				typeCheck($1->type, $3->type, NODE_GT);
				$$=createTree(0, TLookup(booltype), NULL, NODE_GT, $1, $3, NULL);
			}
	| Expr LE Expr	{
				typeCheck($1->type, $3->type, NODE_LE);
				$$=createTree(0, TLookup(booltype), NULL, NODE_LE, $1, $3, NULL);
			}
	| Expr GE Expr	{
				typeCheck($1->type, $3->type, NODE_GE);
				$$=createTree(0, TLookup(booltype), NULL, NODE_GE, $1, $3, NULL);
			}
	| Expr NE Expr	{
				typeCheck($1->type, $3->type, NODE_NE);
				$$=createTree(0, TLookup(booltype), NULL, NODE_NE, $1, $3, NULL);
			}
	| Expr EQ Expr	{
				typeCheck($1->type, $3->type, NODE_EQ);
				$$=createTree(0, TLookup(booltype), NULL, NODE_EQ, $1, $3, NULL);
			}
	| Expr AND Expr	{
				typeCheck($1->type, $3->type, NODE_AND);
				$$=createTree(0, TLookup(booltype), NULL, NODE_AND, $1, $3, NULL);
			}
	| Expr OR Expr	{
				typeCheck($1->type, $3->type, NODE_OR);
				$$=createTree(0, TLookup(booltype), NULL, NODE_OR, $1, $3, NULL);
			}
	| NOT Expr	{
				typeCheck($2->type, TLookup(inttype), NODE_NOT);
				$$=createTree(0, TLookup(booltype), NULL, NODE_NOT, $2, NULL, NULL);
			}
	| MINUS Expr	{
				typeCheck(TLookup(inttype), $2->type, NODE_MINUS);
				$$=createTree(0, TLookup(inttype), NULL, NODE_NEG, $2, NULL, NULL);
			}
	| '(' Expr ')' 	{$$=$2;}
    | Field     {$$ = $1;}
    | NULLSTMT      {$$ = createTree(0, TLookup(nulltype), NULL, NODE_NULL, NULL, NULL, NULL);}
	| NUM		{$$=$1;}
	| STRVAL	{$$=$1;}
	| ID		{
				idCheck($1, NODE_ID);
				$$=$1;
			}
	| ID '[' Expr ']'	{
				idCheck($1, NODE_ARRAY);
				typeCheck($3->type, NULL, NODE_ARRAY);
				$$=createTree(0, $1->type, NULL, NODE_ARRAY, $1, $3, NULL);
			}
	| ID '[' Expr ']' '[' Expr ']'	{
				idCheck($1, NODE_MATRIX);
				typeCheck($3->type, $6->type, NODE_MATRIX);
				$$=createTree(0, $1->type, NULL, NODE_MATRIX, $1, $3, $6);
			}
	| MUL ID	{
				idCheck($2, NODE_PTR);
				$$=createTree(0, $2->type, NULL, NODE_PTR, $2, NULL, NULL);
			}
	| '&' ID	{$$=createTree(0, TLookup(inttype), NULL, NODE_REF, $2, NULL, NULL);}
	| '&' ID '[' Expr ']'	{
				idCheck($2, NODE_REF_ARRAY);
				typeCheck($4->type, NULL, NODE_ARRAY);
				$$=createTree(0, TLookup(inttype), NULL, NODE_REF_ARRAY, $2, $4, NULL);
			}
	| '&' ID '[' Expr ']' '[' Expr ']'	{
				idCheck($2, NODE_REF_MATRIX);
				typeCheck($4->type, $7->type, NODE_MATRIX);
				$$=createTree(0, TLookup(inttype), NULL, NODE_REF_MATRIX, $2, $4, $7);
			}
	| ID '(' ArgList ')'	{
				struct Gsymbol *Gtemp;
				idCheck($1, NODE_FUNC);
				Gtemp=GLookup($1->varname);
				$$=createTree(0, $1->type, NULL, NODE_FUNC, $1, $3, NULL);
				$$->arglist=$3;
			}
	| ID '(' ')'	{
				struct Gsymbol *Gtemp;
				idCheck($1, NODE_FUNC);
				Gtemp=GLookup($1->varname);
				if(Gtemp->paramlist!=NULL){
					printf("Parameter List is not NULL: %s\n", $1->varname);
					exit(1);
				}
				$$=createTree(0, $1->type, NULL, NODE_FUNC, $1, NULL, NULL);
				$$->arglist=NULL;
			}
	;

Field   : Field '.' ID  
        {
            struct Fieldlist *tempfield = getField(Fieldtail->type, $3->varname);
            Fieldtail->ptr1 = createTree(0, tempfield->type, $3->varname, NODE_FIELD, NULL, NULL, NULL);
            Fieldtail = Fieldtail->ptr1;
            $$ = $1;
            $$->type = Fieldtail->type;
        }
        | ID '.' ID     
        {
            struct Gsymbol *Gtemp = GLookup($1->varname);
            struct Lsymbol *Ltemp = LLookup($1->varname);
            struct Paramstruct *Ptemp = PLookup($1->varname);
            
            struct Typetable *type = NULL;
            if(Ltemp != NULL)
                type = Ltemp->type;
            else if(Ptemp != NULL)
                type = Ptemp->type;
            else if(Gtemp != NULL)
                type = Gtemp->type;
            else
            {
                printf("Undeclared object %s\n", $1->varname);
                exit(1);
            }
            struct Fieldlist *tempfield = getField(type, $3->varname);
            Fieldtail = createTree(0, tempfield->type, $3->varname, NODE_FIELD, NULL, NULL, NULL);
            $$ = createTree(0, Fieldtail->type, $1->varname, NODE_FIELD, Fieldtail, NULL, NULL);
            
        }
        ;

ArgList : ArgList ',' Expr	{$$=createTree(0, 0, NULL, NODE_ARG, $3, $1, NULL);}
	| Expr			{$$=createTree(0, 0, NULL, NODE_ARG, $1, NULL, NULL);}
	;

RetStmt : RETURN Expr ';'	{
				typeCheck($2->type, functype, NODE_ASSIGN);
				$$=createTree(0, 0, NULL, NODE_RET, $2, NULL, NULL);
			}
	;

%%

void yyerror(char const *s){
	printf("yyerror %s\n",s);
}

int main(int argc, char* argv[]){
	if(argc>1){
		fp=fopen(argv[1], "r");
		if(fp)
			yyin=fp;
	}
	target_file=fopen("exprtree.xsm","w");
    TypeTableCreate();
	yyparse();
	return 0;
}
