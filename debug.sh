./cleanup.sh
yacc -d compiler_yacc.y
lex compiler_lex.l
gcc y.tab.c lex.yy.c -o test.exe
./test.exe input.expl