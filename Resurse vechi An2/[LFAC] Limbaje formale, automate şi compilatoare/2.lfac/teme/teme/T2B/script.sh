#!/bin/bash
yacc -d limbaj.y 2>/dev/null
lex limbaj.l
gcc y.tab.c lex.yy.c -ll
./a.out program_test.txt
