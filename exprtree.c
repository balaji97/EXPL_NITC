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
struct loop
{
    int a, b;
    struct loop *next;
} *l = NULL;
int labelCount = 0;
int getLabel()
{
    return labelCount++;
}
int retLabel()
{
    return (labelCount - 1);
}

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
			fprintf(target_file, "MOV R%d, %d\n", r1, t->val);
			return r1;
		case NODE_VAR:
			r1=getReg();
			r2=(int)t->varname[0];
			fprintf(target_file, "MOV R%d, [%d]\n", r1, 4096+r2-'a');
			
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
			r2=(int)t->ptr1->varname[0];
			fprintf(target_file, "MOV [%d], R%d\n", 4096+r2-'a', r1);
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
			r1=(int)t->ptr1->varname[0];
			fprintf(target_file, "MOV R2, \"Read\"\n");
			fprintf(target_file, "PUSH R2\n");
			fprintf(target_file, "MOV R2, -1\n");
			fprintf(target_file, "PUSH R2\n");
			fprintf(target_file, "MOV R2, %d\n", 4096+r1-'a');
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

void print(struct tnode *t){
    int i;
	fprintf(target_file, "0\n2056\n0\n0\n0\n0\n0\n0\n");
	fprintf(target_file, "MOV SP, 4121\n");
	if(t!=NULL)
		reg=codeGen(t);
	fprintf(target_file, "INT 10\n");
}


void inorder(struct tnode *t)
{
    if(t == NULL)
        return;
    printf("Nodetype: %d\n", t->nodetype);
    inorder(t->ptr1);
    inorder(t->ptr2);
    inorder(t->ptr3);
}

struct tnode* createTree(int val, int nodetype, int type, char *c, struct tnode *ptr1, struct tnode *ptr2,struct tnode *ptr3)
{
	struct tnode *temp;
	temp=(struct tnode*)malloc(sizeof(struct tnode));
	temp->nodetype=nodetype;
    temp->type = type;
    temp->varname = NULL;
	if(nodetype == NODE_VAR)
    {
		temp->varname=malloc(sizeof(c));
        strcpy(temp->varname, c);
	}
    temp->val = val;
	temp->ptr1=ptr1;
	temp->ptr2=ptr2;
    temp->ptr3=ptr3;
    semanticCheck(temp);
    return temp;
}
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
                        if(t->type != t->ptr2->type || t->type != TYPE_INT)
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
                        break;
        default:
                        break;
                        
    }
}
