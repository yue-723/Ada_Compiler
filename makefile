# Project_1 lex
# all: scanner

# scanner: lex.yy.cpp
# 	g++ -o scanner -O lex.yy.cpp -ll

# lex.yy.cpp: lex.l
# 	flex -o lex.yy.cpp lex.l 

# clean:
# 	rm scanner lex.yy.cpp

# Project_2 yacc
# all: parser

# parser: lex.yy.cpp y.tab.cpp symbolTab.h symbolTab.cpp 
# 	g++ y.tab.cpp symbolTab.cpp -o parser -ll -ly -std=c++11

# lex.yy.cpp: lex.l
# 	flex -o lex.yy.cpp lex.l

# y.tab.cpp: yacc.y
# 	yacc -d yacc.y -o y.tab.cpp

# clean:
# 	rm parser lex.yy.* y.tab.*

# Project_3 JavaByteCode Generator

all: compiler

compiler: lex.yy.cpp y.tab.cpp symbolTab.h symbolTab.cpp CodeGenerator.hpp
	g++ y.tab.cpp symbolTab.cpp CodeGenerator.hpp -o compiler -ll -ly -std=c++11

lex.yy.cpp: lex.l
	flex -o lex.yy.cpp lex.l

y.tab.cpp: yacc.y
	yacc -d yacc.y -o y.tab.cpp

.PHONY: clean
clean:
	rm compiler lex.yy.* y.tab.* *.jasm *.class
	
run: compiler
	./compiler $(file).ada
	./javaa/javaa $(file).jasm
	java $(file)