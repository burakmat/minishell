SRCS = main.c lexer/*c utility.c command_table.c finish.c execute.c list_utils.c \
	set_nodes.c pipe.c builtins/*c handle_redirect.c

OBJS = $(SRCS:.c=.o)

CC = gcc


RM = rm -rf

NAME = minishell

LIB = ./lib/.minishell

CFLAGS			= -Wall -Wextra -Werror -I./lib/readline/include
LDFLAGS			= -L./lib/readline/lib -lreadline

all : $(LIB) $(NAME)

$(LIB):
	make -C ./lib

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $(NAME)

fclean : clean
	$(RM) $(NAME)

clean :
	$(RM) *.o
	$(RM) lexer/*.o

re : fclean all
