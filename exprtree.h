#define NODE_VAR 0
#define NODE_NUM 1

#define NODE_ASSIGN 2

#define NODE_WRITE 3
#define NODE_READ 4

#define NODE_PLUS 5
#define NODE_MINUS 6
#define NODE_MUL 7
#define NODE_DIV 8

#define NODE_CONN 10

#define NODE_IF 11
#define NODE_WHILE 12

#define NODE_LT 13
#define NODE_LE 14
#define NODE_GT 15
#define NODE_GE 16
#define NODE_EQ 17
#define NODE_NE 18

#define NODE_BREAK 19
#define NODE_CONTINUE 20

#define NODE_PTR 21
#define NODE_AUX 22


#define TYPE_INT 101
#define TYPE_BOOL 102
#define TYPE_NULL 103
#define TYPE_STR 104
#define TYPE_PTR 105

#define TRUE 1
#define FALSE 0

typedef struct tnode
{
	int val;
	int type;
	char *varname;
	int nodetype;
    struct tnode *index1, *index2;
    struct Gsymbol *gentry;
	struct tnode *ptr1,*ptr2, *ptr3;
}tnode;

typedef struct varList
{
    char *varName;
    int size, rows, ispointer;
    struct varList *next;
}varList;
int reg;
FILE *target_file, *fp;

typedef struct Gsymbol
{
    char *name;
    int type, size, binding, rows, ispointer;
    struct Gsymbol *next;
}Gsymbol;
struct Gsymbol *symbol_top = NULL;

int sp = 4096; 

reg_index codeGen(struct tnode *t);
reg_index getReg(void);
void freeReg(void);
void print(struct tnode *t);
struct tnode* createTree(int val, int nodetype, int type, char *c, struct tnode *ptr1, struct tnode *ptr2, struct tnode *ptr3, struct tnode *index1, struct tnode *index2);
void semanticCheck(struct tnode *t);
void yyerror(char const *s);
void declareVariables(int type, struct varList *l);
struct varList* appendVariable(struct varList *l, struct varList *node);
struct varList* makeVarList(struct tnode *t, int size, int rows, int ispointer);

void declCheck(struct tnode *t);


struct Gsymbol* lookup(char *s);
void install(char *name, int type, int size, int rows, int ispointer);

int alloc(int size);

void printSymbolTable(); 
