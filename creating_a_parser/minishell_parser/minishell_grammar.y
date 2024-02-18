%token WORD_TOKEN
%token PIPE_TOKEN
%token REDIRECTION_INPUT_TOKEN
%token REDIRECTION_OUTPUT_TOKEN
%token REDIRECTION_HEREDOC_TOKEN
%token REDIRECTION_APPEND_TOKEN
%token END_TOKEN

%%

program:                command_list END_TOKEN;

command_list:           command
                        | redirection_commands
                        | pipe_command;

pipe_command:           simple_command PIPE_TOKEN simple_command
                        | redirection_commands PIPE_TOKEN simple_command
                        | simple_command PIPE_TOKEN redirection_commands;

redirection_commands:   command REDIRECTION_INPUT_TOKEN command
                        | command REDIRECTION_OUTPUT_TOKEN command
                        | command REDIRECTION_HEREDOC_TOKEN command
                        | command REDIRECTION_APPEND_TOKEN command;

command:                simple_command;

simple_command:         WORD_TOKEN
                        | WORD_TOKEN simple_command;

%%
