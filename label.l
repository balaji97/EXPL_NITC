%{

	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <ctype.h>
	
	struct label{
		char *name;
		int addr;
		struct label *next;
	}*head=NULL, *tail=NULL;

	int fl, line, ln;
	char *lab;
	FILE *target_file;
	
	void insert(char *name, int addr);
	int getAddr(char *name);

%}

%%

([a-zA-Z0-9]+)[:] {
		if(fl)
			ln=1;
		else{
			lab=malloc((yyleng-1)*sizeof(char));
			yyless(yyleng-1);
			strcpy(lab, yytext);
			insert(lab, line);
			line-=2;
		}
	}

"JMP "([a-zA-Z0-9]+) {
		if(fl)
			fprintf(target_file, "JMP %d", getAddr(yytext+4));
	}

"JZ R"([0-9]+)", "([a-zA-Z0-9]+) {
		if(fl){
			if(isdigit(yytext[5]))
				fprintf(target_file, "JZ R%c%c, %d", yytext[4], yytext[5], getAddr(yytext+8));
			else
				fprintf(target_file, "JZ R%c, %d", yytext[4], getAddr(yytext+7));
		}
	}

"JNZ R"([0-9]+)", "([a-zA-Z0-9]+) {
		if(fl){
			if(isdigit(yytext[6]))
				fprintf(target_file, "JNZ R%c%c, %d", yytext[5], yytext[6], getAddr(yytext+9));
			else
				fprintf(target_file, "JNZ R%c, %d", yytext[5], getAddr(yytext+8));
		}
	}

"CALL 0" {
		if(fl)
			fprintf(target_file, "CALL 0");
	}

"CALL "([a-zA-Z0-9]+) {
		if(fl)
			fprintf(target_file, "CALL %d", getAddr(yytext+5));
	}

[\n] {
		if(fl){
			if(ln)
				ln=0;
			else
				fprintf(target_file, "\n");
		}
		else{
			if(line<2056)
				line++;
			else
				line+=2;
		}
	}

. {
		if(fl)
			fprintf(target_file, "%s", yytext);
	}

%%

int yywrap(void){
	if(fl){
		return 1;
	}
	else{
		yyin=fopen("exprtree.xsm", "r");
		fl=1;
		return 0;
	}
	return 1;
}

void insert(char *name, int addr){
	struct label *temp;
	temp=(struct label*)malloc(sizeof(struct label));
	temp->name=name;
	temp->addr=addr;
	temp->next=NULL;
	if(head==NULL)
		head=tail=temp;
	else{
		tail->next=temp;
		tail=temp;
	}
}

int getAddr(char *name){
	struct label *temp=head;
	while(temp!=NULL){
		if(!strcmp(temp->name, name)){
			return temp->addr;
		}
		temp=temp->next;
	}
	return 0;
}

int main(){
	fl=0;
	ln=0;
	line=2048;
	target_file=fopen("code.xsm", "w");
	yyin=fopen("exprtree.xsm", "r");
	yylex();
	return 0;
}
