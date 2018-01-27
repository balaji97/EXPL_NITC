./cleanup.sh
yacc -d test.y
lex test.l
gcc y.tab.c lex.yy.c -o test.exe
./test.exe input.expl
lex label.l
gcc lex.yy.c
./a.out
./xsm -l library.lib -e a.xsm
