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

int getLabel(){
	return ++label;
}

reg_index codeGen(struct tnode *t){
	reg_index r1, r2, r3;
	int l1, l2;
	struct Lsymbol *Ltemp;
	struct Gsymbol *Gtemp;
	struct Paramstruct *Ptemp;
	struct tnode *temp;

	if(t==NULL)
		return r1;

	switch(t->nodetype){
		case NODE_NUM:
			r1=getReg();
			fprintf(target_file, "MOV R%d, %d\n", r1, t->val);
			break;
		case NODE_STR:
			r1=getReg();
			fprintf(target_file, "MOV R%d, \"%s\"\n", r1, t->varname);
			break;
		case NODE_ID:
			r1=getReg();
			Ltemp=LLookup(t->varname);
			Gtemp=GLookup(t->varname);
			Ptemp=PLookup(t->varname);
			if(Ltemp!=NULL){
				fprintf(target_file, "MOV R%d, BP\n", r1);
				fprintf(target_file, "ADD R%d, %d\n", r1, Ltemp->binding);
				fprintf(target_file, "MOV R%d, [R%d]\n", r1, r1);
			}
			else if(Ptemp!=NULL){
				Ptemp=Phead;
				r2=3;
				while(strcmp(Ptemp->name, t->varname)){
					r2++;
					Ptemp=Ptemp->next;
				}
				fprintf(target_file, "MOV R%d, BP\n", r1);
				fprintf(target_file, "SUB R%d, %d\n", r1, r2);
				fprintf(target_file, "MOV R%d, [R%d]\n", r1, r1);
			}
			else if(Gtemp!=NULL)
				fprintf(target_file, "MOV R%d, [%d]\n", r1, Gtemp->binding);
			else{
				printf("Unknown variable: %s\n", t->varname);
				exit(1);
			}
			break;
		case NODE_ARRAY:
			Gtemp=GLookup(t->ptr1->varname);
			if(Gtemp==NULL){
				printf("Unknown variable: %s\n", t->ptr1->varname);
				exit(1);
			}
			r1=codeGen(t->ptr2);
			fprintf(target_file, "ADD R%d, %d\n", r1, Gtemp->binding);
			fprintf(target_file, "MOV R%d, [R%d]\n", r1, r1);
			break;
		case NODE_MATRIX:
			Gtemp=GLookup(t->ptr1->varname);
			if(Gtemp==NULL){
				printf("Unknown variable: %s\n", t->ptr1->varname);
				exit(1);
			}
			r1=codeGen(t->ptr2);
			fprintf(target_file, "MUL R%d, %d\n", r1, Gtemp->size1);
			r2=codeGen(t->ptr3);
			fprintf(target_file, "ADD R%d, R%d\n", r1, r2);
			fprintf(target_file, "ADD R%d, %d\n", r1, Gtemp->binding);
			fprintf(target_file, "MOV R%d, [R%d]\n", r1, r1);
			freeReg();
			break;
		case NODE_PTR:
			r1=getReg();
			Ltemp=LLookup(t->ptr1->varname);
			Gtemp=GLookup(t->ptr1->varname);
			Ptemp=PLookup(t->ptr1->varname);
			if(Ltemp!=NULL){
				fprintf(target_file, "MOV R%d, BP\n", r1);
				fprintf(target_file, "ADD R%d, %d\n", r1, Ltemp->binding);
				fprintf(target_file, "MOV R%d, [R%d]\n", r1, r1);
				fprintf(target_file, "MOV R%d, [R%d]\n", r1, r1);
			}
			else if(Ptemp!=NULL){
				Ptemp=Phead;
				r3=3;
				while(strcmp(Ptemp->name, t->ptr1->varname)){
					r3++;
					Ptemp=Ptemp->next;
				}
				fprintf(target_file, "MOV R%d, BP\n", r1);
				fprintf(target_file, "SUB R%d, %d\n", r1, r3);
				fprintf(target_file, "MOV R%d, [R%d]\n", r1, r1);
				fprintf(target_file, "MOV R%d, [R%d]\n", r1, r1);
			}
			else if(Gtemp!=NULL){
				fprintf(target_file, "MOV R%d, [%d]\n", r1, Gtemp->binding);
				fprintf(target_file, "MOV R%d, [R%d]\n", r1, r1);
			}
			else{
				printf("Unknown variable: %s\n", t->ptr1->varname);
				exit(1);
			}
			break;
		case NODE_FUNC:
			Gtemp=GLookup(t->ptr1->varname);
			if(Gtemp==NULL){
				printf("Unknown function: %s\n", t->ptr1->varname);
				exit(1);
			}

			r1=0;
			Ptemp=Gtemp->paramlist;
			while(Ptemp!=NULL){
				r1++;
				Ptemp=Ptemp->next;
			}

			r2=0;
			temp=t->ptr2;
			while(temp!=NULL){
				r2++;
				temp=temp->ptr2;
			}

			if(r1!=r2){
				printf("Incorrect no. of arguments: %s\n", t->ptr1->varname);
				exit(1);
			}

			r1=0;
			r2--;
			Ptemp=Gtemp->paramlist;
			while(Ptemp!=NULL){
				r3=0;
				temp=t->ptr2;
				while(r3<r2){
					r3++;
					temp=temp->ptr2;
				}
				if(Ptemp->type!=temp->ptr1->type){
					printf("Incorrect paramter: %s\n", Ptemp->name);
					exit(1);
				}
				r2--;
				Ptemp=Ptemp->next;
			}

			for(r2=0;r2<=reg;r2++)
				fprintf(target_file, "PUSH R%d\n", r2);
			reg=-1;
			r1=codeGen(t->ptr2);
			r1=getReg();
			fprintf(target_file, "PUSH R%d\n", r1);
			fprintf(target_file, "CALL F%d\n", Gtemp->flabel);
			fprintf(target_file, "POP R%d\n", r1);
			freeReg();
			r3=0;
			r1=getReg();
			Ptemp=Gtemp->paramlist;
			while(Ptemp!=NULL){
				fprintf(target_file, "POP R%d\n", r1);
				r3++;
				Ptemp=Ptemp->next;
			}
			reg=r2;
			freeReg();
			for(r2--;r2>=0;r2--){
				fprintf(target_file, "POP R%d\n", r2);
				r3++;
			}
			r1=getReg();
			fprintf(target_file, "MOV R%d, SP\n", r1);
			fprintf(target_file, "ADD R%d, %d\n", r1, r3+1);
			fprintf(target_file, "MOV R%d, [R%d]\n", r1, r1);
			break;
		case NODE_ARG:
			r1=codeGen(t->ptr1);
			fprintf(target_file, "PUSH R%d\n", r1);
			freeReg();
			if(t->ptr2!=NULL)
				r1=codeGen(t->ptr2);
			break;
		case NODE_RET:
			r1=codeGen(t->ptr1);
			r2=getReg();
			fprintf(target_file, "MOV R%d, BP\n", r2);
			fprintf(target_file, "SUB R%d, 2\n", r2);
			fprintf(target_file, "MOV [R%d], R%d\n", r2, r1);
			freeReg();
			freeReg();
			break;
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
		case NODE_MOD:
			r1=codeGen(t->ptr1);
			r2=codeGen(t->ptr2);
			fprintf(target_file, "MOD R%d, R%d\n", r1, r2);
			freeReg();
			break;
		case NODE_LT:
			r1=codeGen(t->ptr1);
			r2=codeGen(t->ptr2);
			fprintf(target_file, "LT R%d, R%d\n", r1, r2);
			freeReg();
			break;
		case NODE_GT:
			r1=codeGen(t->ptr1);
			r2=codeGen(t->ptr2);
			fprintf(target_file, "GT R%d, R%d\n", r1, r2);
			freeReg();
			break;
		case NODE_LE:
			r1=codeGen(t->ptr1);
			r2=codeGen(t->ptr2);
			fprintf(target_file, "LE R%d, R%d\n", r1, r2);
			freeReg();
			break;
		case NODE_GE:
			r1=codeGen(t->ptr1);
			r2=codeGen(t->ptr2);
			fprintf(target_file, "GE R%d, R%d\n", r1, r2);
			freeReg();
			break;
		case NODE_NE:
			r1=codeGen(t->ptr1);
			r2=codeGen(t->ptr2);
			fprintf(target_file, "NE R%d, R%d\n", r1, r2);
			freeReg();
			break;
		case NODE_EQ:
			r1=codeGen(t->ptr1);
			r2=codeGen(t->ptr2);
			fprintf(target_file, "EQ R%d, R%d\n", r1, r2);
			freeReg();
			break;
		case NODE_AND:
			l1=getLabel();
			r1=codeGen(t->ptr1);
			fprintf(target_file, "JZ R%d, L%d\n", r1, l1);
			r2=codeGen(t->ptr2);
			fprintf(target_file, "MOV R%d, R%d\n", r1, r2);
			fprintf(target_file, "L%d:\n", l1);
			freeReg();
			break;
		case NODE_OR:
			l1=getLabel();
			r1=codeGen(t->ptr1);
			fprintf(target_file, "JNZ R%d, L%d\n", r1, l1);
			r2=codeGen(t->ptr2);
			fprintf(target_file, "MOV R%d, R%d\n", r1, r2);
			fprintf(target_file, "L%d:\n", l1);
			freeReg();
			break;
		case NODE_NOT:
			l1=getLabel();
			l2=getLabel();
			r1=codeGen(t->ptr1);
			fprintf(target_file, "JZ R%d, L%d\n", r1, l1);
			fprintf(target_file, "MOV R%d, 0\n", r1);
			fprintf(target_file, "JMP L%d\n", l2);
			fprintf(target_file, "L%d:\n", l1);
			fprintf(target_file, "MOV R%d, 1\n", r1);
			fprintf(target_file, "L%d:\n", l2);
			freeReg();
			break;
		case NODE_NEG:
			r1=codeGen(t->ptr1);
			fprintf(target_file, "MUL R%d, -1\n", r1);
			break;
		case NODE_ASSIGN:
			r1=codeGen(t->ptr2);
			r2=getReg();
			Ltemp=LLookup(t->ptr1->varname);
			Gtemp=GLookup(t->ptr1->varname);
			Ptemp=PLookup(t->ptr1->varname);
			if(Ltemp!=NULL){
				fprintf(target_file, "MOV R%d, BP\n", r2);
				fprintf(target_file, "ADD R%d, %d\n", r2, Ltemp->binding);
				fprintf(target_file, "MOV [R%d], R%d\n", r2, r1);
			}
			else if(Ptemp!=NULL){
				Ptemp=Phead;
				r3=3;
				while(strcmp(Ptemp->name, t->ptr1->varname)){
					r3++;
					Ptemp=Ptemp->next;
				}
				fprintf(target_file, "MOV R%d, BP\n", r2);
				fprintf(target_file, "SUB R%d, %d\n", r2, r3);
				fprintf(target_file, "MOV [R%d], R%d\n", r2, r1);
			}
			else if(Gtemp!=NULL)
				fprintf(target_file, "MOV [%d], R%d\n", Gtemp->binding, r1);
			else{
				printf("Unknown variable: %s\n", t->varname);
				exit(1);
			}
			freeReg();
			freeReg();
			break;
		case NODE_ASSIGN_ARRAY:
			Gtemp=GLookup(t->ptr1->varname);
			if(Gtemp==NULL){
				printf("Unknown variable: %s\n", t->ptr1->varname);
				exit(1);
			}
			r1=codeGen(t->ptr2);
			fprintf(target_file, "ADD R%d, %d\n", r1, Gtemp->binding);
			r2=codeGen(t->ptr3);
			fprintf(target_file, "MOV [R%d], R%d\n", r1, r2);
			freeReg();
			freeReg();
			break;
		case NODE_ASSIGN_MATRIX:
			Gtemp=GLookup(t->ptr1->varname);
			if(Gtemp==NULL){
				printf("Unknown variable: %s\n", t->ptr1->varname);
				exit(1);
			}
			r1=codeGen(t->ptr2->ptr1);
			fprintf(target_file, "MUL R%d, %d\n", r1, Gtemp->size1);
			r2=codeGen(t->ptr2->ptr2);
			fprintf(target_file, "ADD R%d, R%d\n", r1, r2);
			freeReg();
			fprintf(target_file, "ADD R%d, %d\n", r1, Gtemp->binding);
			r2=codeGen(t->ptr3);
			fprintf(target_file, "MOV [R%d], R%d\n", r1, r2);
			freeReg();
			freeReg();
			break;
		case NODE_ASSIGN_PTR:
			r1=codeGen(t->ptr2);
			r2=getReg();
			Ltemp=LLookup(t->ptr1->varname);
			Gtemp=GLookup(t->ptr1->varname);
			Ptemp=PLookup(t->ptr1->varname);
			if(Ltemp!=NULL){
				fprintf(target_file, "MOV R%d, BP\n", r2);
				fprintf(target_file, "ADD R%d, %d\n", r2, Ltemp->binding);
				fprintf(target_file, "MOV R%d, [R%d]\n", r2, r2);
				fprintf(target_file, "MOV [R%d], R%d\n", r2, r1);
			}
			else if(Ptemp!=NULL){
				Ptemp=Phead;
				r3=3;
				while(strcmp(Ptemp->name, t->ptr1->varname)){
					r3++;
					Ptemp=Ptemp->next;
				}
				fprintf(target_file, "MOV R%d, BP\n", r2);
				fprintf(target_file, "SUB R%d, %d\n", r2, r3);
				fprintf(target_file, "MOV R%d, [R%d]\n", r2, r2);
				fprintf(target_file, "MOV [R%d], R%d\n", r2, r1);
			}
			else if(Gtemp!=NULL){
				fprintf(target_file, "MOV R%d, [%d]\n", r2, Gtemp->binding);
				fprintf(target_file, "MOV [R%d], R%d\n", r2, r1);
			}
			else{
				printf("Unknown variable: %s\n", t->varname);
				exit(1);
			}
			freeReg();
			freeReg();
			break;
		case NODE_REF:
			r1=getReg();
			Ltemp=LLookup(t->ptr1->varname);
			Gtemp=GLookup(t->ptr1->varname);
			Ptemp=PLookup(t->ptr1->varname);
			if(Ltemp!=NULL){
				fprintf(target_file, "MOV R%d, BP\n", r1);
				fprintf(target_file, "ADD R%d, %d\n", r1, Ltemp->binding);
			}
			else if(Ptemp!=NULL){
				Ptemp=Phead;
				r3=3;
				while(strcmp(Ptemp->name, t->ptr1->varname)){
					r3++;
					Ptemp=Ptemp->next;
				}
				fprintf(target_file, "MOV R%d, BP\n", r1);
				fprintf(target_file, "SUB R%d, %d\n", r1, r3);
			}
			else if(Gtemp!=NULL)
				fprintf(target_file, "MOV R%d, %d\n", r1, Gtemp->binding);
			else{
				printf("Unknown variable: %s\n", t->varname);
				exit(1);
			}
			break;
		case NODE_REF_ARRAY:
			Gtemp=GLookup(t->ptr1->varname);
			if(Gtemp==NULL){
				printf("Unknown variable: %s\n", t->ptr1->varname);
				exit(1);
			}
			r1=codeGen(t->ptr2);
			if(Gtemp->nodetype==NODE_MATRIX)
				fprintf(target_file, "MUL R%d, %d\n", r1, Gtemp->size1);
			fprintf(target_file, "ADD R%d, %d\n", r1, Gtemp->binding);
			break;
		case NODE_REF_MATRIX:
			Gtemp=GLookup(t->ptr1->varname);
			if(Gtemp==NULL){
				printf("Unknown variable: %s\n", t->ptr1->varname);
				exit(1);
			}
			r1=codeGen(t->ptr2);
			fprintf(target_file, "MUL R%d, %d\n", r1, Gtemp->size1);
			r2=codeGen(t->ptr3);
			fprintf(target_file, "ADD R%d, R%d\n", r1, r2);
			freeReg();
			fprintf(target_file, "ADD R%d, %d\n", r1, Gtemp->binding);
		case NODE_IF:
			l1=getLabel();
			r1=codeGen(t->ptr1);
			fprintf(target_file, "JZ R%d, L%d\n", r1, l1);
			freeReg();
			r2=codeGen(t->ptr2);
			fprintf(target_file, "L%d:\n", l1);
			break;
		case NODE_ELIF:
			l1=getLabel();
			l2=getLabel();
			r1=codeGen(t->ptr1);
			fprintf(target_file, "JZ R%d, L%d\n", r1, l1);
			freeReg();
			r2=codeGen(t->ptr2);
			fprintf(target_file, "JMP L%d\n", l2);
			fprintf(target_file, "L%d:\n", l1);
			r2=codeGen(t->ptr3);
			fprintf(target_file, "L%d:\n", l2);
			break;
		case NODE_WHILE:
			l1=getLabel();
			l2=getLabel();
			insLoop(l2, l1);
			fprintf(target_file, "L%d:\n", l1);
			r1=codeGen(t->ptr1);
			fprintf(target_file, "JZ R%d, L%d\n", r1, l2);
			freeReg();
			r2=codeGen(t->ptr2);
			fprintf(target_file, "JMP L%d\n", l1);
			fprintf(target_file, "L%d:\n", l2);
			delLoop();
			break;
		case NODE_DO_WHILE:
			l1=getLabel();
			l2=getLabel();
			insLoop(l2, l1);
			fprintf(target_file, "L%d:\n", l1);
			r1=codeGen(t->ptr1);
			r2=codeGen(t->ptr2);
			fprintf(target_file, "JNZ R%d, L%d\n", r2, l1);
			freeReg();
			fprintf(target_file, "L%d:\n", l2);
			delLoop();
			break;
		case NODE_REPEAT:
			l1=getLabel();
			l2=getLabel();
			insLoop(l2, l1);
			fprintf(target_file, "L%d:\n", l1);
			r1=codeGen(t->ptr1);
			r2=codeGen(t->ptr2);
			fprintf(target_file, "JZ R%d, L%d\n", r2, l1);
			freeReg();
			fprintf(target_file, "L%d:\n", l2);
			delLoop();
			break;
		case NODE_BREAK:
			if(lHead!=NULL)
				fprintf(target_file, "JMP L%d\n", lHead->br);
			break;
		case NODE_CONTINUE:
			if(lHead!=NULL)
				fprintf(target_file, "JMP L%d\n", lHead->cn);
			break;
		case NODE_BRKP:
			fprintf(target_file, "BRKP\n");
			break;
		case NODE_WRITE:
			r1=codeGen(t->ptr1);
			r2=getReg();
			fprintf(target_file, "MOV R%d, \"Write\"\n", r2);
			fprintf(target_file, "PUSH R%d\n", r2);
			fprintf(target_file, "MOV R%d, -2\n", r2);
			fprintf(target_file, "PUSH R%d\n", r2);
			fprintf(target_file, "PUSH R%d\n", r1);
			fprintf(target_file, "PUSH R%d\n", r2);
			fprintf(target_file, "PUSH R%d\n", r2);
			fprintf(target_file, "CALL 0\n");
			fprintf(target_file, "POP R%d\n", r2);
			fprintf(target_file, "POP R%d\n", r2);
			fprintf(target_file, "POP R%d\n", r2);
			fprintf(target_file, "POP R%d\n", r2);
			fprintf(target_file, "POP R%d\n", r2);
			freeReg();
			freeReg();
			break;
		case NODE_READ:
			r1=getReg();
			r2=getReg();
			Ltemp=LLookup(t->ptr1->varname);
			Gtemp=GLookup(t->ptr1->varname);
			Ptemp=PLookup(t->ptr1->varname);
			if(Ltemp!=NULL){
				fprintf(target_file, "MOV R%d, BP\n", r1);
				fprintf(target_file, "ADD R%d, %d\n", r1, Ltemp->binding);
			}
			else if(Ptemp!=NULL){
				Ptemp=Phead;
				r3=3;
				while(strcmp(Ptemp->name, t->ptr1->varname)){
					r3++;
					Ptemp=Ptemp->next;
				}
				fprintf(target_file, "MOV R%d, BP\n", r1);
				fprintf(target_file, "SUB R%d, %d\n", r1, r3);
			}
			else if(Gtemp!=NULL)
				fprintf(target_file, "MOV R%d, %d\n", r1, Gtemp->binding);
			else{
				printf("Unknown variable: %s\n", t->ptr1->varname);
				exit(1);
			}
			fprintf(target_file, "MOV R%d, \"Read\"\n", r2);
			fprintf(target_file, "PUSH R%d\n", r2);
			fprintf(target_file, "MOV R%d, -1\n", r2);
			fprintf(target_file, "PUSH R%d\n", r2);
			fprintf(target_file, "MOV R%d, R%d\n", r2, r1);
			fprintf(target_file, "PUSH R%d\n", r2);
			fprintf(target_file, "PUSH R%d\n", r2);
			fprintf(target_file, "PUSH R%d\n", r2);
			fprintf(target_file, "CALL 0\n");
			fprintf(target_file, "POP R%d\n", r2);
			fprintf(target_file, "POP R%d\n", r2);
			fprintf(target_file, "POP R%d\n", r2);
			fprintf(target_file, "POP R%d\n", r2);
			fprintf(target_file, "POP R%d\n", r2);
			freeReg();
			break;
		case NODE_READ_ARRAY:
			Gtemp=GLookup(t->ptr1->varname);
			if(Gtemp==NULL){
				printf("Unknown variable: %s\n", t->ptr1->varname);
				exit(1);
			}
			r1=codeGen(t->ptr2);
			fprintf(target_file, "ADD R%d, %d\n", r1, Gtemp->binding);
			r2=getReg();
			fprintf(target_file, "MOV R%d, \"Read\"\n", r2);
			fprintf(target_file, "PUSH R%d\n", r2);
			fprintf(target_file, "MOV R%d, -1\n", r2);
			fprintf(target_file, "PUSH R%d\n", r2);
			fprintf(target_file, "MOV R%d, R%d\n", r2, r1);
			fprintf(target_file, "PUSH R%d\n", r2);
			fprintf(target_file, "PUSH R%d\n", r2);
			fprintf(target_file, "PUSH R%d\n", r2);
			fprintf(target_file, "CALL 0\n");
			fprintf(target_file, "POP R%d\n", r2);
			fprintf(target_file, "POP R%d\n", r2);
			fprintf(target_file, "POP R%d\n", r2);
			fprintf(target_file, "POP R%d\n", r2);
			fprintf(target_file, "POP R%d\n", r2);
			freeReg();
			freeReg();
			break;
		case NODE_READ_MATRIX:
			Gtemp=GLookup(t->ptr1->varname);
			if(Gtemp==NULL){
				printf("Unknown variable: %s\n", t->ptr1->varname);
				exit(1);
			}
			r1=codeGen(t->ptr2);
			fprintf(target_file, "MUL R%d, %d\n", r1, Gtemp->size1);
			r2=codeGen(t->ptr3);
			fprintf(target_file, "ADD R%d, R%d\n", r1, r2);
			fprintf(target_file, "ADD R%d, %d\n", r1, Gtemp->binding);
			fprintf(target_file, "MOV R%d, \"Read\"\n", r2);
			fprintf(target_file, "PUSH R%d\n", r2);
			fprintf(target_file, "MOV R%d, -1\n", r2);
			fprintf(target_file, "PUSH R%d\n", r2);
			fprintf(target_file, "MOV R%d, R%d\n", r2, r1);
			fprintf(target_file, "PUSH R%d\n", r2);
			fprintf(target_file, "PUSH R%d\n", r2);
			fprintf(target_file, "PUSH R%d\n", r2);
			fprintf(target_file, "CALL 0\n");
			fprintf(target_file, "POP R%d\n", r2);
			fprintf(target_file, "POP R%d\n", r2);
			fprintf(target_file, "POP R%d\n", r2);
			fprintf(target_file, "POP R%d\n", r2);
			fprintf(target_file, "POP R%d\n", r2);
			freeReg();
			freeReg();
			break;
		case NODE_READ_PTR:
			r1=getReg();
			r2=getReg();
			Ltemp=LLookup(t->ptr1->varname);
			Gtemp=GLookup(t->ptr1->varname);
			Ptemp=PLookup(t->ptr1->varname);
			if(Ltemp!=NULL){
				fprintf(target_file, "MOV R%d, BP\n", r1);
				fprintf(target_file, "ADD R%d, %d\n", r1, Ltemp->binding);
				fprintf(target_file, "MOV R%d, [R%d]\n", r1, r1);
			}
			else if(Ptemp!=NULL){
				Ptemp=Phead;
				r3=3;
				while(strcmp(Ptemp->name, t->ptr1->varname)){
					r3++;
					Ptemp=Ptemp->next;
				}
				fprintf(target_file, "MOV R%d, BP\n", r1);
				fprintf(target_file, "SUB R%d, %d\n", r1, r3);
				fprintf(target_file, "MOV R%d, [R%d]\n", r1, r1);
			}
			else if(Gtemp!=NULL)
				fprintf(target_file, "MOV R%d, [%d]\n", r1, Gtemp->binding);
			else{
				printf("Unknown variable: %s\n", t->ptr1->varname);
				exit(1);
			}
			fprintf(target_file, "MOV R%d, \"Read\"\n", r2);
			fprintf(target_file, "PUSH R%d\n", r2);
			fprintf(target_file, "MOV R%d, -1\n", r2);
			fprintf(target_file, "PUSH R%d\n", r2);
			fprintf(target_file, "MOV R%d, R%d\n", r2, r1);
			fprintf(target_file, "PUSH R%d\n", r2);
			fprintf(target_file, "PUSH R%d\n", r2);
			fprintf(target_file, "PUSH R%d\n", r2);
			fprintf(target_file, "CALL 0\n");
			fprintf(target_file, "POP R%d\n", r2);
			fprintf(target_file, "POP R%d\n", r2);
			fprintf(target_file, "POP R%d\n", r2);
			fprintf(target_file, "POP R%d\n", r2);
			fprintf(target_file, "POP R%d\n", r2);
			freeReg();
			freeReg();
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

void typeCheck(struct Typetable *type1, struct Typetable *type2, int nodetype){
	switch(nodetype){
		case NODE_ASSIGN:
			if(type1!=type2 && (type2 != TLookup(nulltype))){
				printf("Assignment Type Mismatch %s %s\n", type1->name, type2->name);
				exit(1);
			}
			break;
		case NODE_PLUS:
		case NODE_MINUS:
		case NODE_MUL:
		case NODE_DIV:
		case NODE_MOD:
			if((type1!=TLookup(inttype))||(type2!=TLookup(inttype))){
				printf("Arithmetic Operator Type Mismatch\n");
				exit(1);
			}
			break;
		case NODE_LT:
		case NODE_GT:
		case NODE_LE:
		case NODE_GE:
            if(type2 == TLookup(nulltype))
            {
                printf("Can only check equality with null type \n");
                exit(1);
            }
		case NODE_NE:
        case NODE_EQ:
            if(type1 == TLookup(nulltype))
            {
                printf("Attempting to compare a null type\n");
                exit(1);
            }
            if(type2 == TLookup(nulltype))
                break;
            if(((type1!=type2)||((type1!=TLookup(inttype))&&(type1!=TLookup(strtype)))||((type2!=TLookup(inttype))&&(type2!=TLookup(strtype))))){
				printf("Relational Operator Type Mismatch %s %s\n", type1->name, type2->name);
				exit(1);
			}
            break;
		case NODE_AND:
		case NODE_OR:
            if(type1 != TLookup(booltype) || type2 != TLookup(booltype))
            {
                printf("%s or %s not of type bool\n", type1->name, type2->name);
                exit(1);
            }
            break;
		case NODE_NOT:
			if(type1 != TLookup(booltype))
            {
                printf("%s not of type bool\n", type1->name);
                exit(1);
            }
			break;
		case NODE_ARRAY:
			if(type1!=TLookup(inttype)){
				printf("Array Type Mismatch\n");
				exit(1);
			}
			break;
		case NODE_MATRIX:
			if((type1!=TLookup(inttype))||(type2!=TLookup(inttype))){
				printf("Matrix Type Mismatch\n");
				exit(1);
			}
			break;
	}
}

void idCheck(struct tnode *t, int nodetype){
	int inodetype;
	struct Lsymbol *Ltemp=LLookup(t->varname);
	struct Gsymbol *Gtemp=GLookup(t->varname);
	struct Paramstruct *Ptemp=PLookup(t->varname);
	
	if(Ltemp!=NULL)
		inodetype=Ltemp->nodetype;
	else if(Ptemp!=NULL)
		inodetype=Ptemp->nodetype;
	else if(Gtemp!=NULL)
		inodetype=Gtemp->nodetype;
	else{
		printf("Unknown variable %s\n", t->varname);
		exit(1);
	}

	if(nodetype==NODE_REF_ARRAY){
		if((inodetype!=NODE_ARRAY)&&(inodetype!=NODE_MATRIX)){
			printf("Incorrect identifier\n");
			exit(1);
		}
	}
	else if(nodetype==NODE_REF_MATRIX){
		if(inodetype!=NODE_MATRIX){
			printf("Incorrect identifier\n");
			exit(1);
		}
	}
	else if(nodetype==NODE_ID){
		if((inodetype!=NODE_ID)&&(inodetype!=NODE_PTR)){
			printf("Incorrect identifier\n");
			exit(1);
		}
	}
	else if(inodetype!=nodetype){
		printf("Incorrect identifier\n");
		exit(1);
	}
}

void evaluate(){
	fprintf(target_file, "0\n2056\n0\n0\n0\n0\n0\n0\n");
	fprintf(target_file, "MOV SP, %d\n", binding-1);
	fprintf(target_file, "MOV BP, %d\n", binding);
	fprintf(target_file, "PUSH R0\n");
	fprintf(target_file, "CALL MAIN\n");
	fprintf(target_file, "INT 10\n");
}

struct tnode* createTree(int val, struct Typetable *type, char *varname, int nodetype, struct tnode *ptr1, struct tnode *ptr2, struct tnode *ptr3){
	struct tnode *temp;
	struct Lsymbol *Ltemp;
	struct Gsymbol *Gtemp;
	struct Paramstruct *Ptemp;
	temp=(struct tnode*)malloc(sizeof(struct tnode));
	temp->val=val;
	temp->type=type;
	temp->nodetype=nodetype;
	switch(nodetype){
		case NODE_NUM:
			temp->type=TLookup(inttype);
			break;
		case NODE_STR:
			temp->type=TLookup(strtype);
			temp->varname=malloc(sizeof(varname));
			strcpy(temp->varname, varname);
			break;
		case NODE_ID:
			temp->varname=malloc(sizeof(varname));
			strcpy(temp->varname, varname);
			Ltemp=LLookup(temp->varname);
			Gtemp=GLookup(temp->varname);
			Ptemp=PLookup(temp->varname);
			if(Ltemp!=NULL){
				temp->type=Ltemp->type;
				if(Ltemp->nodetype==NODE_PTR)
					temp->type=TLookup(inttype);
			}
			else if(Ptemp!=NULL){
				temp->type=Ptemp->type;
				if(Ptemp->nodetype==NODE_PTR)
					temp->type=TLookup(inttype);
			}
			else if(Gtemp!=NULL){
				temp->type=Gtemp->type;
				if(Gtemp->nodetype==NODE_PTR)
					temp->type=TLookup(inttype);
			}
			temp->Lentry=Ltemp;
			temp->Gentry=Gtemp;
			break;
		case NODE_ARRAY:
		case NODE_MATRIX:
		case NODE_PTR:
			
			Ltemp=LLookup(ptr1->varname);
			Gtemp=GLookup(ptr1->varname);
			Ptemp=PLookup(ptr1->varname);
			if(Ltemp!=NULL)
				temp->type=Ltemp->type;
			else if(Ptemp!=NULL)
				temp->type=Ptemp->type;
			else if(Gtemp!=NULL)
				temp->type=Gtemp->type;
			else{
				printf("Unknown identifier: %s\n", ptr1->varname);
				exit(1);
			}
			temp->Lentry=Ltemp;
			temp->Gentry=Gtemp;
			break;
	}
	temp->ptr1=ptr1;
	temp->ptr2=ptr2;
	temp->ptr3=ptr3;
	return temp;
}

void insLoop(int br, int cn){
	struct loop *temp;
	temp=(struct loop*)malloc(sizeof(struct loop));
	temp->br=br;
	temp->cn=cn;
	temp->next=lHead;
	lHead=temp;
}

void delLoop(){
	struct loop *temp;
	if(lHead==NULL)
		return;
	temp=lHead;
	lHead=lHead->next;
	free(temp);
}

struct Gsymbol* GLookup(char *name){
	struct Gsymbol *temp=Ghead;
	while(temp!=NULL){
		if(!strcmp(temp->name, name))
			return temp;
		temp=temp->next;
	}
	return NULL;
}

void GInstall(char *name, struct Typetable *type, int size1, int size2, int nodetype, struct Paramstruct *paramlist){
	struct Gsymbol *temp;
	temp=GLookup(name);
	if(temp!=NULL){
		printf("Multiple declaration : %s\n", name);
		exit(1);
	}

	temp=(struct Gsymbol*)malloc(sizeof(struct Gsymbol));
	temp->name=malloc(sizeof(name));
	strcpy(temp->name, name);
	temp->type=type;
	temp->size1=size1;
	temp->size2=size2;
	temp->nodetype=nodetype;
	temp->paramlist=paramlist;

	if(nodetype=NODE_FUNC)
		temp->flabel=flabel++;

	if((binding+(temp->size1*temp->size2))>=5120){
		printf("Static Area Overflow\n");
		exit(1);
	}
	temp->binding=binding;
	binding+=temp->size1*temp->size2;

	if(Ghead==NULL)
		Ghead=Gtail=temp;
	else{
		Gtail->next=temp;
		Gtail=temp;
	}
}

struct Lsymbol* LLookup(char *name){
	struct Lsymbol *temp=Lhead;
	while(temp!=NULL){
		if(!strcmp(temp->name, name))
			return temp;
		temp=temp->next;
	}
	return NULL;
}

void LInstall(char *name, struct Typetable *type, int nodetype){
	struct Lsymbol *temp;
	temp=LLookup(name);
	if(temp!=NULL){
		printf("Multiple declaration : %s\n", name);
		exit(1);
	}

	temp=(struct Lsymbol*)malloc(sizeof(struct Lsymbol));
	temp->name=malloc(sizeof(name));
	strcpy(temp->name, name);
	temp->type=type;
	temp->nodetype=nodetype;
	temp->binding=binding++;

	if(Lhead==NULL)
		Lhead=Ltail=temp;
	else{
		Ltail->next=temp;
		Ltail=temp;
	}
}

struct Paramstruct* PLookup(char *name){
	struct Paramstruct *temp=Phead;
	while(temp!=NULL){
		if(!strcmp(temp->name, name))
			return temp;
		temp=temp->next;
	}
	return NULL;
}

void PInstall(char *name, struct Typetable *type, int nodetype){
	struct Paramstruct *temp;
	temp=PLookup(name);
	if(temp!=NULL){
		printf("Multiple declaration : %s\n", name);
		exit(1);
	}

	temp=(struct Paramstruct*)malloc(sizeof(struct Paramstruct));
	temp->name=malloc(sizeof(name));
	strcpy(temp->name, name);
	temp->type=type;
	temp->nodetype=nodetype;

	if(Phead==NULL)
		Phead=Ptail=temp;
	else{
		Ptail->next=temp;
		Ptail=temp;
	}
}

struct Typetable *TLookup(char *name)
{
//    printf("Finding for type %s in\n", name);
 //   printTypeTable();
    struct Typetable *temp = Thead;
    while(temp)
    {
        if(strcmp(temp->name, name) == 0)
        {
            break;
        }
        temp = temp->next;
    }
    return temp;
}

void TInstall(char *name, int size, struct Fieldlist *fields)
{
    if(TLookup(name) != NULL)
    {
        printf("Multiple type declaration: %s\n", name);
        exit(1);
    }
    struct Typetable *temp = (struct Typetable*)malloc(sizeof(struct Typetable));
    temp->name = strdup(name);
    temp->size = size;
    struct Fieldlist *templist = fields;
    while(templist)
    {
        if(templist->type == TLookup(temptype))
            templist->type = temp;
        templist = templist->next;
    }
    temp->fields = fields;
    temp->next = NULL;
    temp->next = Thead;
    Thead = temp;
}

struct Fieldlist *FLookup(char *name)
{
    struct Fieldlist *temp = Fhead;
    while(temp)
    {
        if(strcmp(temp->name, name) == 0)
            break;
        temp = temp->next;
    }
    return temp;
}

struct Fieldlist *FCreate(char *name, struct Typetable *type)
{
    struct Fieldlist *temp = (struct Fieldlist*)malloc(sizeof(struct Fieldlist));
    temp->name = strdup(name);
    temp->type = type;
    temp->next = NULL;
    temp->fieldIndex = 1;
    return temp;
}

struct Fieldlist *FAppend(struct Fieldlist *entry, struct Fieldlist *list)
{
    entry->next = list;
    entry->fieldIndex = list->fieldIndex + 1;
    if(entry->fieldIndex > 8)
    {
        printf("Maximum 8 fields per datatype\n");
        exit(1);
    }
    return entry;
}

int GetSize(struct Typetable *type)
{
    return type->size;
}

void TypeTableCreate()
{
    Thead = NULL;
    TInstall(inttype, 1, NULL);
    TInstall(strtype, 1, NULL);
    TInstall(booltype, 1, NULL);
    TInstall(nulltype, 0, NULL);
    TInstall(temptype, 1, NULL);
    declType=TLookup(inttype); PdeclType=TLookup(inttype); functype=TLookup(inttype);
}

void printTypeTable()
{
    struct Typetable *temp = Thead;
    printf("NAME\tSIZE\n");
    while(temp)
    {
        printf("%s\t%d\n", temp->name, temp->size);
        if(temp->fields)
        {
            printf("Fields: ");
            struct Fieldlist *templist = temp->fields;
            while(templist)
            {
                printf("%s %s ", templist->type->name, templist->name);
                templist = templist->next;
            }
            printf("\n");
        }
        temp = temp->next;
    }
}

struct Fieldlist *getField(struct Typetable *temp, char *name)
{
    if(temp == NULL)
    {
        printf("Attempt to get a field from non-existent type\n");
        exit(1);
    }
    struct Fieldlist *templist = temp->fields;
    while(templist)
    {
        if(strcmp(templist->name, name) == 0)
            break;
        templist = templist->next;
    }
    if(templist == NULL)
    {
        printf("Cannot find reference to member %s in type %s\n", name, temp->name);
        exit(1);
    }
    return templist;
}