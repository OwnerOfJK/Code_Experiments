# Name of the target executable
NAME = shell

# Compiler
CC = cc

# Compiler flags
CFLAGS = -Wall -Werror -Wextra

# Library files
LIBS = ./libft/libft.a

# Source files
SRCS = $(wildcard *.c)

# Object files
OBJS = $(SRCS:.c=.o)

# Build the target executable
all: $(NAME)

$(NAME): $(OBJS)
	# Build libft targets
	make -C ./libft

	# Link the executable
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

# Clean intermediate files
clean:
	# Clean libft targets
	make clean -C ./libft

	# Remove object files
	rm -rf $(OBJS)

# Remove all generated files
fclean:
	# Fclean libft targets
	make fclean -C ./libft

	# Remove object files and the target executable
	rm -rf $(OBJS)
	rm -rf $(NAME)

# Rebuild the project
re: fclean all

# Specify the phony targets
.PHONY: all clean fclean re