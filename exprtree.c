//Register Allocation for code generation
reg_index getReg(){
	if(reg>=20){
		printf("Out of registers\n");
		exit(1);
	}
	return ++reg;
}

void freeReg(){
	if(reg>=0)
		reg--;
}


//Loop structure for using break and continue
struct loop
{
    int a, b;
    struct loop *next;
} *l = NULL;


//Assigning labels for JMP statements in code generation
int labelCount = 0;

int getLabel()
{
    return labelCount++;
}

int retLabel()
{
    return (labelCount - 1);
}


//Allocates mamory for local variables
int alloc()
{
    if(sp > 5118)
        yyerror("Stack overflow!\n");
    else
        return sp++;
}


//Symbol table structure

//Finds entry with specified name in symbol table
struct Gsymbol *lookup(char *name)
{
    struct Gsymbol *temp = symbol_top;
    while(temp != NULL)
    {
        if(strcmp(name, temp->name) == 0)
            break;
        temp = temp->next;
    }
    return temp;
}
//Appends a new entry to symbol table
void install(char *name, int type, int size)
{
    if(lookup(name) != NULL)
        yyerror("Variable redeclared!\n");
    struct Gsymbol *temp;
    temp = (struct Gsymbol*)malloc(sizeof(struct Gsymbol));
    
    temp->name = name;
    temp->type = type;
    temp->size = size;
    printf("Creating entry %s %d %d \n", temp->name, temp->type, temp->size);
    temp->binding = alloc();
    temp->next = symbol_top;
    symbol_top = temp;
}


//Recursively traverses AST and generates corresponding XSM code
reg_index codeGen(struct tnode *t)
{
    int label_1, label_2, label_3;
	reg_index r1,r2;
    if(t == NULL)
        return r1;
	switch(t->nodetype)
    {
		case NODE_NUM:
			r1=getReg();
            if(t->type == TYPE_INT)
                fprintf(target_file, "MOV R%d, %d\n", r1, t->val);
            else
            {
                fprintf(target_file, "MOV R%d, %s\n", r1, t->varname);
               
            }
            return r1;
            break;
		case NODE_VAR:
			r1=getReg();
			r2=lookup(t->varname)->binding;
            
			fprintf(target_file, "MOV R%d, [%d]\n", r1, r2);
			
			return r1;
		case NODE_PLUS:
			r1=codeGen(t->ptr1);
			r2=codeGen(t->ptr2);
			fprintf(target_file, "ADD R%d, R%d\n", r1, r2);
			freeReg();
			break;
		case NODE_MINUS:
			r1=codeGen(t->ptr1);
			r2=codeGen(t->ptr2);
			fprintf(target_file, "SUB R%d, R%d\n", r1, r2);
			freeReg();
			break;
		case NODE_MUL:
			r1=codeGen(t->ptr1);
			r2=codeGen(t->ptr2);
			fprintf(target_file, "MUL R%d, R%d\n", r1, r2);
			freeReg();
			break;
		case NODE_DIV:
			r1=codeGen(t->ptr1);
			r2=codeGen(t->ptr2);
			fprintf(target_file, "DIV R%d, R%d\n", r1, r2);
			freeReg();
			break;
		case NODE_ASSIGN:
			r1=codeGen(t->ptr2);
			r2=lookup(t->ptr1->varname)->binding;
			fprintf(target_file, "MOV [%d], R%d\n", r2, r1);
			freeReg();
			break;
		case NODE_WRITE:
			r1=codeGen(t->ptr1);
			fprintf(target_file, "MOV R2, \"Write\"\n");
			fprintf(target_file, "PUSH R2\n");
			fprintf(target_file, "MOV R2, -2\n");
			fprintf(target_file, "PUSH R2\n");
			fprintf(target_file, "PUSH R%d\n", r1);
			fprintf(target_file, "PUSH R2\n");
			fprintf(target_file, "PUSH R2\n");
			fprintf(target_file, "CALL 0\n");
			fprintf(target_file, "POP R0\n");
			fprintf(target_file, "POP R1\n");
			fprintf(target_file, "POP R1\n");
			fprintf(target_file, "POP R1\n");
			fprintf(target_file, "POP R1\n");
			freeReg();
			break;
		case NODE_READ:
			r1=lookup(t->ptr1->varname)->binding;
			fprintf(target_file, "MOV R2, \"Read\"\n");
			fprintf(target_file, "PUSH R2\n");
			fprintf(target_file, "MOV R2, -1\n");
			fprintf(target_file, "PUSH R2\n");
			fprintf(target_file, "MOV R2, %d\n",r1);
			fprintf(target_file, "PUSH R2\n");
			fprintf(target_file, "PUSH R2\n");
			fprintf(target_file, "PUSH R2\n");
			fprintf(target_file, "CALL 0\n");
			fprintf(target_file, "POP R0\n");
			fprintf(target_file, "POP R1\n");
			fprintf(target_file, "POP R1\n");
			fprintf(target_file, "POP R1\n");
			fprintf(target_file, "POP R1\n");
			break;
        case NODE_IF:
            label_1 = getLabel();
            label_2 = getLabel();
            r1 = codeGen(t->ptr1);
            fprintf(target_file, "JZ R%d, L%d\n", r1, label_1);
            freeReg();
            r1 = codeGen(t->ptr2);
            fprintf(target_file, "JMP L%d\n", label_2);
            fprintf(target_file, "L%d:\n", label_1);
            r1 = codeGen(t->ptr3);
            fprintf(target_file, "L%d:\n", label_2);
            break;
        case NODE_WHILE:
            label_1 = getLabel();
            label_2 = getLabel();
            struct loop *temp = (struct loop*)malloc(sizeof(struct loop));
            temp->a = label_1;
            temp->b = label_2;
            temp->next = l;
            l = temp;
            fprintf(target_file, "L%d:\n", label_1);
            r1 = codeGen(t->ptr1);
            fprintf(target_file, "JZ R%d, L%d\n", r1, label_2);
            freeReg();
            r1 = codeGen(t->ptr2);
            fprintf(target_file, "JMP L%d\n", label_1);
            fprintf(target_file, "L%d:\n", label_2);
            l = l->next;
            break; 
        case NODE_LT:
            r1 = codeGen(t->ptr1);
            r2 = codeGen(t->ptr2);
            fprintf(target_file, "LT R%d, R%d\n", r1, r2);
            freeReg();
            freeReg();
            break;
        case NODE_LE:
            r1 = codeGen(t->ptr1);
            r2 = codeGen(t->ptr2);
            fprintf(target_file, "LE R%d, R%d\n", r1, r2);
            freeReg();
            freeReg();
            break;
        case NODE_GT:
            r1 = codeGen(t->ptr1);
            r2 = codeGen(t->ptr2);
            fprintf(target_file, "GT R%d, R%d\n", r1, r2);
            freeReg();
            freeReg();
            break;
        case NODE_GE:
            r1 = codeGen(t->ptr1);
            r2 = codeGen(t->ptr2);
            fprintf(target_file, "GE R%d, R%d\n", r1, r2);
            freeReg();
            freeReg();
            break;
        case NODE_NE:
            r1 = codeGen(t->ptr1);
            r2 = codeGen(t->ptr2);
            fprintf(target_file, "NE R%d, R%d\n", r1, r2);
            freeReg();
            freeReg();
            break;    
        case NODE_EQ:
            r1 = codeGen(t->ptr1);
            r2 = codeGen(t->ptr2);
            fprintf(target_file, "EQ R%d, R%d\n", r1, r2);
            freeReg();
            freeReg();
            break;    
        case NODE_BREAK:
            if(l != NULL)
                fprintf(target_file, "JMP L%d\n", l->b);
            break;
        case NODE_CONTINUE:
            if(l != NULL)
                fprintf(target_file, "JMP L%d\n", l->a);
		    break;
        case NODE_CONN:
			r1=codeGen(t->ptr1);
			r2=codeGen(t->ptr2);
			break;
        
		default:
			printf("Error\n");
			exit(1);
	}
	freeReg();
	return r1;
}


//Prints first few lines of XEXE file, and calls codeGen()
void print(struct tnode *t){
    int i;
	fprintf(target_file, "0\n2056\n0\n0\n0\n0\n0\n0\n");
	fprintf(target_file, "MOV SP, %d\n", sp);
	if(t!=NULL)
		reg=codeGen(t);
	fprintf(target_file, "INT 10\n");
}


//Prints AST nodes inorder
void inorder(struct tnode *t)
{
    if(t == NULL)
        return;
    printf("Nodetype: %d\n", t->nodetype);
    inorder(t->ptr1);
    inorder(t->ptr2);
    inorder(t->ptr3);
}


//Creates a new node for AST with given parameters
struct tnode* createTree(int val, int nodetype, int type, char *c, struct tnode *ptr1, struct tnode *ptr2,struct tnode *ptr3)
{
	struct tnode *temp;
	temp=(struct tnode*)malloc(sizeof(struct tnode));
	temp->nodetype=nodetype;
    temp->type = type;
    temp->varname = NULL;
	if(c != NULL)
    {
		temp->varname=malloc(sizeof(c));
        strcpy(temp->varname, c);
	}
    temp->val = val;
	temp->ptr1=ptr1;
	temp->ptr2=ptr2;
    temp->ptr3=ptr3;
   
    
    declCheck(ptr1);
    declCheck(ptr2);
    declCheck(ptr3);
    
     semanticCheck(temp);
    
    printf("Node created %d %d\n", temp->nodetype,  temp->type);
    if(temp->varname != NULL)
        printf("%s\n", temp->varname);
    if(temp->ptr1 != NULL)
    {
        printf("First child %d %d\n", temp->ptr1->nodetype, temp->ptr1->type);
        if(temp->ptr1->varname != NULL)
            printf("%s\n", temp->ptr1->varname);
    }
    if(temp->ptr2 != NULL)
    {
        printf("Second child %d %d\n", temp->ptr2->nodetype, temp->ptr2->type);
        if(temp->ptr2->varname != NULL)
            printf("%s\n", temp->ptr2->varname);
    }
    if(temp->ptr3 != NULL)
    {
        printf("Third child %d %d\n", temp->ptr3->nodetype, temp->ptr3->type);
        if(temp->ptr3->varname != NULL)
            printf("%s\n", temp->ptr3->varname);
    }
    
    return temp;
}

//Checks if the node variable has been declared
void declCheck(struct tnode *t)
{
    if(t == NULL)
        return;
    if(t->nodetype != NODE_VAR)
        return;
    struct Gsymbol *temp = lookup(t->varname);
    if(temp == NULL)
        yyerror("Error! Undeclared variable.\n");
    t->type = temp->type;
    t->gentry = temp;
}
//Checks for type mismatch and other semantic errors
void semanticCheck(struct tnode *t)
{
    switch(t->nodetype)
    {
        case NODE_IF    :
        case NODE_WHILE :
                        if(t->ptr1->type != TYPE_BOOL)
                        {
                            yyerror("Error. Conditional type not bool.\n");
                        }
                        break;
        case NODE_PLUS  :
        case NODE_MINUS :
        case NODE_MUL   :
        case NODE_DIV   :
                        t->type = t->ptr1->type;
                        if(t->type != t->ptr2->type || t->type != TYPE_INT || t->ptr2->type != TYPE_INT)
                        {
                            yyerror("Error. Operator type mismatch!\n");
                        }
                        break;
        case NODE_LT    :
        case NODE_LE    :
        case NODE_GT    :
        case NODE_GE    :
        case NODE_NE    :
        case NODE_EQ    :
                        if(t->ptr1->type != t->ptr2->type)
                            yyerror("Error. Comparision type mismatch.\n");
        case NODE_ASSIGN:  
                        if(t->ptr1->type != t->ptr2->type)
                            yyerror("Error. Assign type mismatch.\n");
                        break;
        default:
                        break;
                        
    }
}

void printSymbolTable()
{
    struct Gsymbol *temp = symbol_top;
    while(temp != NULL)
    {
        printf("Name:%s\nType:%d\nSize:%d\nBinding:%d\n", temp->name, temp->type, temp->size, temp->binding);
        temp = temp->next;
    }
}


//Declares variables of given type from the varlist
void declareVariables(int type, struct varList *l)
{
//    printf("Following variables of type %d declared:\n", type);
    while(l != NULL)
    {
        install(l->varName, type, 1);
        l = l->next;
    }    
}


//Appends a new variable name to varlist
struct varList* appendVariable(struct varList *l, struct tnode *t)
{
    struct varList *temp = makeVarList(t);
    temp->next = l;
    return temp;
}


//initialises varlist
struct varList* makeVarList(struct tnode *t)
{
    struct varList *temp = (struct varList*)malloc(sizeof(struct varList));
    temp->varName = t->varname;
    temp->next = NULL;
    return temp;
}

