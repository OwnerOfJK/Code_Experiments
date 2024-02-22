%token WORD_TOKEN
%token PIPE_TOKEN
%token REDIRECTION_INPUT_TOKEN
%token REDIRECTION_OUTPUT_TOKEN
%token REDIRECTION_HEREDOC_TOKEN
%token REDIRECTION_APPEND_TOKEN
%token END_TOKEN

%start  pipe_sequence
%%
pipe_sequence    : command
                 | pipe_sequence PIPE_TOKEN command
                 ;
simple_command   : cmd_prefix cmd_word cmd_suffix
                 | cmd_prefix cmd_word
                 | cmd_prefix
                 | cmd_name cmd_suffix
                 | cmd_name
                 ;
cmd_name         : WORD_TOKEN                 
                 ;
cmd_word         : WORD_TOKEN                  
                 ;
cmd_prefix       :            io_redirect
                 | cmd_prefix io_redirect
                 ;
cmd_suffix       :            io_redirect
                 | cmd_suffix io_redirect
                 | WORD_TOKEN
                 | cmd_suffix WORD_TOKEN
                 ;
redirect_list    :               io_redirect
                 | redirect_list io_redirect
                 ;
io_redirect      :           io_file
                 |           io_here
                 ;
io_file     : REDIRECTION_INPUT_TOKEN     filename
                 | REDIRECTION_OUTPUT_TOKEN       filename
                 | REDIRECTION_APPEND_TOKEN    filename
                 ;
filename         : WORD                      
                 ;
io_here          : REDIRECTION_HEREDOC_TOKEN     here_end
                 ;
here_end         : END_TOKEN                      
