//Register Allocation for code generation
reg_index getReg()
{
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
int alloc(int size)
{
    int ret = sp;
    sp += size;
    if(sp - 1 > 5118)
        yyerror("Stack overflow!\n");
    else
    {
        return ret;
    }
}
void dealloc(int size)
{
    sp -= size;
}

//Symbol table structure

//Finds entry with specified name in symbol table

void printLocalTable()
{
    struct Lsymbol *temp = local_symbol_top;
    printf("Name\tType\tBinding\n");
    while(temp)
    {
        printf("%s\t%d\t%d\n", temp->name, temp->type, temp->binding);
        temp = temp->next;
    }
        
}
void deallocateLocalTable()
{
    struct Lsymbol *temp;
    while(local_symbol_top)
    {
        temp = local_symbol_top;
        local_symbol_top = local_symbol_top->next;
        free(temp);
        dealloc(1);
    }
    local_symbol_top = NULL;
}
void deallocateParamList(struct paramList *plist)
{
    struct paramList *temp;
    while(plist)
    {
        temp = plist;
        plist = plist->next;
        free(temp);
        dealloc(1);
    }
    plist = NULL;
}
void deallocateVarList(struct varList *list)
{
    struct varList *temp;
    while(list)
    {
        temp = list;
        list = list->next;
        free(temp);
        dealloc(1);
    }
    list = NULL;
}


//Recursively traverses AST and generates corresponding XSM code
reg_index codeGen(struct tnode *t)
{
    int label_1, label_2, label_3;
	reg_index r1,r2,r3, r4, r5;
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
        case NODE_PTR:
			r1=getReg();
			r2=lookup(t->varname)->binding;
            if(t->index1 != NULL)
            {
                r3=codeGen(t->index1);
                r5 = lookup(t->varname)->rows;
                fprintf(target_file, "MUL R%d, %d\n", r3, r5);
                if(t->index2 != NULL)
                {
                    r4 = codeGen(t->index2);
                    fprintf(target_file, "ADD R%d, R%d\n", r3, r4);
                    freeReg();
                }
                fprintf(target_file, "ADD R%d, %d\n", r3, r2);
                fprintf(target_file, "MOV R%d, [R%d]\n", r1, r3);
                freeReg();
            }
            else
            {
                if(t->nodetype == NODE_PTR)
                {
                    r3 = getReg();
                    fprintf(target_file, "MOV R%d, [%d]\n", r3, r2);
                    fprintf(target_file, "MOV R%d, [R%d]\n", r1, r3);
                    freeReg();
                }
                else
                    fprintf(target_file, "MOV R%d, [%d]\n", r1, r2);
            }
            return r1;
		case NODE_PLUS:
			r1=codeGen(t->ptr1);
			r2=codeGen(t->ptr2);
			fprintf(target_file, "ADD R%d, R%d\n", r1, r2);
			freeReg();
			break;
		case NODE_MINUS:
//            fprintf(target_file, "Entering sub, reg = %d\n", reg);
            
			r1=codeGen(t->ptr1);
//            fprintf(target_file, "Mid sub, reg = %d\n", reg);
			r2=codeGen(t->ptr2);
			fprintf(target_file, "SUB R%d, R%d\n", r1, r2);

//			fprintf(target_file, "Exiting sub, reg = %d\n", reg);
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
            if(t->ptr1->index1 != NULL)
            {
            //    printf("Non array assignment\n");
                r3=codeGen(t->ptr1->index1);
                r5 = lookup(t->ptr1->varname)->rows;
                fprintf(target_file, "MUL R%d, %d\n", r3, r5);
                if(t->ptr1->index2 != NULL)
                {
                    r4 = codeGen(t->ptr1->index2);
                    fprintf(target_file, "ADD R%d, R%d\n", r3, r4);
                }
                fprintf(target_file, "ADD R%d, %d\n", r3, r2);
                fprintf(target_file, "MOV [R%d], R%d\n", r3, r1);
                freeReg();
                freeReg();
            }
            else
            {
                if(t->ptr1->nodetype == NODE_PTR)
                {
                    r3 = getReg();
                    fprintf(target_file, "MOV R%d, [%d]\n", r3, r2);    
                    fprintf(target_file, "MOV [R%d], R%d\n", r3, r1);
                    freeReg();
                }
                else
                    fprintf(target_file, "MOV [%d], R%d\n", r2, r1);
            }
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
			fprintf(target_file, "MOV R2, \"Read\"\n");
			fprintf(target_file, "PUSH R2\n");
			fprintf(target_file, "MOV R2, -1\n");
			fprintf(target_file, "PUSH R2\n");
			
            r1=lookup(t->ptr1->varname)->binding;
            if(t->ptr1->index1 != NULL)
            {
                r3=codeGen(t->ptr1->index1);
                r5 = lookup(t->ptr1->varname)->rows;
                fprintf(target_file, "MUL R%d, %d\n", r3, r5);
                if(t->ptr1->index2 != NULL)
                {
                    r4 = codeGen(t->ptr1->index2);
                    fprintf(target_file, "ADD R%d, R%d\n", r3, r4);
                    freeReg();
                }
                fprintf(target_file, "ADD R%d, %d\n", r3, r1);
                fprintf(target_file, "MOV R2, R%d\n", r3);
                freeReg();
                freeReg();
            }
            else
            {
                if(t->ptr1->nodetype == NODE_PTR)
                    fprintf(target_file, "MOV R2, [%d]\n",r1);
                else
                    fprintf(target_file, "MOV R2, %d\n",r1);
            }
			
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
            r1 = codeGen(t->ptr2);
            fprintf(target_file, "JMP L%d\n", label_2);
            fprintf(target_file, "L%d:\n", label_1);
            r1 = codeGen(t->ptr3);
            fprintf(target_file, "L%d:\n", label_2);
            freeReg();
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
            r1 = codeGen(t->ptr2);
            fprintf(target_file, "JMP L%d\n", label_1);
            fprintf(target_file, "L%d:\n", label_2);
            l = l->next;
            freeReg();
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

void printTree(struct tnode *t)
{
    if(t==NULL)
        return;
    printf("Value\tNodetype\tType\n");
    printNode(t);
    printf("First child:\n");
    printNode(t->ptr1);
    printf("Second child:\n");
    printNode(t->ptr2);
    printf("Third child:\n");
    printNode(t->ptr3);
    printTree(t->ptr1);
    printTree(t->ptr2);
    printTree(t->ptr3);
}
void printNode(struct tnode *t)
{
    if(t == NULL)
        return;
    printf("%d\t%d\t%d\n", t->val, t->nodetype, t->type);
    return;
}

void paramCheck(struct tnode *function, struct tnode *paramList)
{
    struct Gsymbol *gentry = lookup(function->varname);
    if(gentry == NULL)
        return;
    if(gentry->size != -1)
        return;
    struct paramList *plist = gentry->plist;
    struct tnode *cmp;
    while(plist != NULL && paramList != NULL)
    {
        
        if(paramList->nodetype == NODE_CONN)
            cmp = paramList->ptr2;
        else
            cmp = paramList;
        printf("Param Name:\t%s\nParam type:\t%d\nCall type:\t%d\n", plist->name, plist->type, cmp->type);
        if(plist->type != cmp->type)
            yyerror("Function call: parameter type mismatch\n");
        plist = plist->next;
        if(paramList->nodetype == NODE_CONN)
            paramList = paramList->ptr1;
        else
            paramList = NULL;
    }
    if(plist || paramList)
        yyerror("Function call: parameter list mismatch\n");
    return;
}

//Creates a new node for AST with given parameters
struct tnode* createTree(int val, int nodetype, int type, char *c, struct tnode *ptr1, struct tnode *ptr2,struct tnode *ptr3, struct tnode *index1, struct tnode *index2, struct tnode *paramList)
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
    temp->index1 = index1;
    temp->index2 = index2;
    
    if(temp->nodetype == NODE_FCALL)
        paramCheck(temp, paramList);
    
    temp->paramList = paramList;
    
    declCheck(ptr1);
    declCheck(ptr2);
    declCheck(ptr3);
    
     semanticCheck(temp);
    
/*    printf("Node created %d %d\n", temp->nodetype,  temp->type);
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
*/    
    return temp;
}



struct Gsymbol *lookup(char *name)
{
    if(name == NULL)
        return NULL;
    struct Gsymbol *temp = symbol_top;
    while(temp != NULL)
    {
        if(strcmp(name, temp->name) == 0)
            break;
        temp = temp->next;
    }
    return temp;
}
struct Lsymbol* lookup_local(char *name)
{
    struct Lsymbol *temp = local_symbol_top;
    while(temp != NULL)
    {
        if(strcmp(name, temp->name) == 0)
            break;
        temp = temp->next;
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
    struct Lsymbol *temp_local;
    temp_local = lookup_local(t->varname);
    struct Gsymbol *temp = NULL;
    if(temp_local == NULL)
        printSymbolTable();
    else
    {
        int something = temp_local->type;
        printf("%d\n", something);
        t->type = something;
        printf("%d\n", t->type);       //temp_local->type = 0;
    }
    //printf("Hello\n");
    if(temp_local == NULL && temp == NULL)
        yyerror("Error! Undeclared variable.\n");
    t->gentry = temp;
    t->lentry = temp_local;
    
}


void checkTree(struct tnode *t)
{
    if(t == NULL)
        return;
    semanticCheck(t);
    checkTree(t->ptr1);
    checkTree(t->ptr2);
    checkTree(t->ptr3);
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
                        {
                        //    printf("%s\t%d\t%d\n", t->ptr1->varname, t->ptr1->type, t->ptr2->type);
                            
                            yyerror("Error. Assign type mismatch.\n");
                        }
                        break;
        default:
                        break;
                        
    }
}

void printSymbolTable()
{
    struct Gsymbol *temp = symbol_top;
    printf("Name\tType\tSize\tRows\tPointer\tBinding\n");
    while(temp != NULL)
    {
        printf("%s\t%d\t%d\t%d\t%d\t%d\n", temp->name, temp->type, temp->size, temp->rows, temp->ispointer, temp->binding);
        temp = temp->next;
    }
}


//Declares variables of given type from the varlist
void declareVariables(int type, struct varList *l)
{
//    printf("Following variables of type %d declared:\n", type);
    while(l != NULL)
    {
        install(l->varName, type, l->size, l->rows, l->ispointer, l->plist);
     //   printParamList(l->plist);
        l = l->next;
    }    
}

//Appends a new entry to symbol table
void install(char *name, int type, int size, int rows, int ispointer, struct paramList *plist)
{
    if(lookup(name) != NULL)
        yyerror("Variable redeclared!\n");
    struct Gsymbol *temp;
    temp = (struct Gsymbol*)malloc(sizeof(struct Gsymbol));
    temp->name = name;
    temp->type = type;
    temp->size = size;
    temp->rows = rows;
    temp->ispointer = ispointer;
//    printf("Creating entry %s %d %d \n", temp->name, temp->type, temp->size);
    temp->binding = alloc(size);
    temp->plist = plist;
//    printParamList(temp->plist);
    if(size == -1)
        temp->flabel = getFunctionLabel();
    temp->next = symbol_top;
    symbol_top = temp;
}
void install_params(struct paramList *plist)
{
    while(plist != NULL)
    {
        install_local(plist->name, plist->type);
        plist = plist->next;
    }
}
void install_local(char *name, int type)
{
    if(lookup_local(name) != NULL)
        yyerror("Local variable redeclared!\n");
    struct Lsymbol *temp = (struct Lsymbol*)malloc(sizeof(struct Lsymbol));
    temp->name = name;
    temp->type = type;
    temp->binding = alloc(1);
    temp->next = local_symbol_top;
    local_symbol_top = temp;
}
void declareLocalVariables(int type, struct varList *l)
{
    while(l)
    {
        install_local(l->varName, type);
        l = l->next;
    }
}

//Appends a new variable name to varlist
struct varList* appendVariable(struct varList *l, struct varList *node)
{
    node->next = l;
    return node;
}


//initialises varlist
struct varList* makeVarList(struct tnode *t, int size, int rows, int ispointer, struct paramList *plist)
{
    struct varList *temp = (struct varList*)malloc(sizeof(struct varList));
    temp->varName = t->varname;
    temp->next = NULL;
    temp->size = size;
    temp->rows = rows;
    temp->ispointer = ispointer;
    temp->plist = plist;
    return temp;
}
void printVarList(struct varList *l)
{
    printf("Current varList:\n");
    while(l != NULL)
    {
        printf("%s\n", l->varName);
        l = l->next;
    }
}

struct paramList* makeParamList(char *name, int type)
{
    struct paramList *temp = (struct paramList*)malloc(sizeof(struct paramList));
    temp->name = strdup(name);
    temp->type = type;
    temp->next = NULL;
}

struct paramList* appendParam(struct paramList *list, struct paramList *node)
{
    node->next = list;
    return node;
}

void printParamList(struct paramList *plist)
{
    printf("Name\tType\n");
    while(plist)
    {
        printf("%s\t%d\n", plist->name, plist->type);
        plist = plist->next;
    }
}

void functionCheck(struct tnode *function, struct paramList *plist, int type)
{
    struct Gsymbol *temp = lookup(function->varname);
    
    if(temp)
    {
       // printParamList(temp->plist);
        struct paramList *list = temp->plist;
        while(list && plist)
        {
            if(list->type != plist->type)
            {
            //    printParamList(plist);
            //    printParamList(list);
                yyerror("Parameter list mismatch!\n");
            }
            list = list->next;
            plist = plist->next;
        }
        if(plist || list)
        {
            
        //    printParamList(plist);
        //    printParamList(list);
            yyerror("Parameter list mismatch!\n");
        }
        if(type != temp->type)
        {    
            yyerror("Return type mismatch!\n");
        }
    }
    else
    {
        yyerror("Undeclared function!\n");
    }
}