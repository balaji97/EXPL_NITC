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

#define TYPE_INT 101
#define TYPE_BOOL 102
#define TYPE_NULL 103

typedef struct tnode
{
	int val;
	int type;
	char *varname;
	int nodetype;
	struct tnode *ptr1,*ptr2, *ptr3;
}tnode;

int reg;
FILE *target_file, *fp;

reg_index codeGen(struct tnode *t);
reg_index getReg(void);
void freeReg(void);
void print(struct tnode *t);
struct tnode* createTree(int val, int nodetype, int type, char *c, struct tnode *ptr1, struct tnode *ptr2, struct tnode *ptr3);
