%{

	#include <stdio.h>
	#include <stdlib.h>
	#include <ctype.h>
	#include <string.h>
	FILE *output_file;
	struct labelAddress
	{
		char *label;
		int address, number;
		struct labelAddress *next;
	} *top = NULL;
	
	int getAddress(struct labelAddress *temp, char *s)
	{
		if(temp == NULL)
			return -1;
		else if(strcmp(temp->label, s) == 0)
			return (temp->address - 2*temp->number);
		else
			getAddress(temp->next, s);
	}
	
	struct address
	{
		int line;
	}a;			
	
int retAddress(int line)
		{
			if(line <= 8)
			{
				return (2048 + line);
			}
			else
			{
				return (2056 + 2*(line - 8));
			}
		}
	
		
	int flag = 0, ln = 0;
	
%}

%%

([a-z A-Z 0-9]+)[:] {
						if(flag == 0)
						{
							struct labelAddress *temp;
							yyless((int)(yyleng - 1));
							temp = (struct labelAddress*)malloc(sizeof(struct labelAddress));
							temp->label = strdup(yytext);
							temp->address = retAddress(a.line);
							if(top == NULL)
								temp->number = 0;
							else
								temp->number = top->number + 1;
							temp->next = top;
							top = temp;
						}
						else
							ln = 1;
					}		
    
[\n] {
						a.line++;
						if(flag == 1)
						{
							if(ln == 1)
								ln = 0;
							else
								fprintf(output_file, "\n");
						}
					}
"JMP "[a-zA-Z0-9]+ {
		if(flag)
			fprintf(output_file, "JMP %d", getAddress(top, yytext+4));
	}

"JZ R"([0-9]+)[,][ ][a-zA-Z0-9]+ {
		if(flag){
			if(isdigit(yytext[5]))
				fprintf(output_file, "JZ R%c%c, %d", yytext[4], yytext[5], getAddress(top, yytext+8));
			else
				fprintf(output_file, "JZ R%c, %d", yytext[4], getAddress(top, yytext+7));
		}
	}

"JNZ R"([0-9]+)[,][ ][a-zA-Z0-9]+ {
		if(flag){
			if(isdigit(yytext[6]))
				fprintf(output_file, "JZ R%c%c, %d", yytext[5], yytext[6], getAddress(top, yytext+9));
			else
				fprintf(output_file, "JZ R%c, %d", yytext[5], getAddress(top, yytext+8));
		}
	}
"CALL "[0-9]+ {
					if(flag)
						fprintf(output_file, "%s", yytext);
			  }
"CALL "[a-zA-Z0-9]+ {
		if(flag)
		{
			fprintf(output_file, "CALL %d", getAddress(top, yytext+5));
		}
	}


. {
	if(flag)
		fprintf(output_file, "%s", yytext);
  }
%%

int yywrap(void)
{
	if(flag == 0)
	{
		flag = 1;
		yyin = fopen("test.xsm", "r");
		a.line = 0;
		return 0;
	}
	return 1;
}

int main()
{
	flag = 0;
	output_file = fopen("a.xsm", "w");
	yyin = fopen("test.xsm", "r");
	a.line = 0;
	yylex();
	return 0;
}	

