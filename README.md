## Project3 - Code Generation

Your assignment is to generate code (in **Java assembly language**) for the Ada− language. The generated
code will then be translated to Java bytecode by a Java assembler.

## Assignment

Your assignment will be divided into the following parts:
- initialization
- parsing declarations for constants and variables
- code generation for expressions and statements
- code generation for conditional statements and while loops
- code generation for procedure calls

## Language Restrictions

In order to keep the code generation assignment simple that we can implement most of the features of the
language, only a subset set of Ada−language will be considered in this assignment:

- No READ statements.
- No declaration or use of arrays.
- No floating-point numbers.
- No string variables.

## Modified in Project3: 

1. Fix Project2 expr & grammar bug.
2. Fix lex.l boolean token return error
3. Add CodeGenerator.hpp to generate Java ByteCode.
4. Rewrite procedure declaretion
5. Rewrite yacc.y to combine CodeGenerator.hpp
6. Add some .ada file to test this project

## Files tree
```
├── lex.l               // The Scanner
├── yacc.y              // The Parser & Code Generator
├── CodeGenerator.hpp   // Code Generator Class file
├── symbolTab.h         // Symbol & SymbolTable Class Header
├── symbolTab.cpp       // Symbol & SymbolTable Class c++
├── makefile            // MAKEFILE
├── javaa/              // Folder for generate Java assembly language 
└── *.ada/              // ada file for testing
```

## Command instruction

• Compile this project to generate ada_compiler
```
make
```
• Compile your ADA_FILE and execute it
```
make run file= test/$(YOUR_FILENAME)
```
NOTE: YOUR_FILENAME don't need file extension ".ada"
• clear the project repository
```
make clean
```

## Evaluation

- Assignment_1 Lexical analysis got 100/100
- Assignment_2 Syntax analysis got 100/100
- Assignment_3 Code generation got 93/100
