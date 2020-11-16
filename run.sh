yacc -d exprtree.y
lex exprtree.l
gcc y.tab.c lex.yy.c -o exprtree.exe
./exprtree.exe input.expl
lex label.l
gcc lex.yy.c
./a.out
rm exprtree.xsm exprtree.exe a.out
./xsm -l library.lib -e code.xsm
