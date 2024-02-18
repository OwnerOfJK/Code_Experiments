# How to get here

1. Write the rules that apply to your project, found in: `minishell_grammar.y`
2. Compile with bison using `bison -v -o minishell_grammar.c minishell_grammar.y`
    - This generates `minishell_grammar.c` and `minishell_grammar.output`
        - `minishell_grammar.c is the` c source file of your grammar (will not be used in a schoo project)
        - `minishell_grammar.output` is the textual automaton (this we will use to deduce our parsing table)

# Next step

1. deduce parsing table from automaton
2. read parsing table into linked list structure