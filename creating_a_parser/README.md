# My first bison - flex parser

## Files
- `calculator.y` -> bison file that contains the grammar of calculations.
- `lexer.l` -> calculator scanner that tokenizes each input and adds a token.

## How to run?

### Bison
- generate `calculator.tab.c` and `calculator.tab.h` using the following command: `bison -d calculator.y`
 - `calculator.tab.c` contains the actual C code for your parser. It includes the logic for parsing the input language based on the grammar rules you defined. You will compile this file along with your lexer and main program.
 - `calculator.tab.h` This header file provides declarations needed to use the parser in your program. It includes information about token types, constants, and function prototypes. Your main program and lexer will typically include this file.

### Flex
- generate `lex.yy.c` using `flex lexer.l`

### Create Parser
- `gcc -o calculator calculator.tab.c lex.yy.c -lfl`

### Run executable
- `./calculator`

Now you can simply use the calculator.

