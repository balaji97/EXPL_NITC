
yacc -d compiler_yacc.y
lex compiler_lex.l
gcc y.tab.c lex.yy.c -o test.exe
./test.exe input.expl
lex compiler_label.l
gcc lex.yy.c
./a.out
./xsm -l library.lib -e a.xsm
./cleanup.sh
