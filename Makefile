SRCS = main.c lexer/*c utility.c command_table.c finish.c execute.c list_utils.c set_nodes.c pipe.c builtins/*c

OBJS = $(SRCS:.c=.o)

CC = gcc

FLAGS =  -Wall -Wextra -Werror

RM = rm -rf

NAME = minishell

all :$(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(FLAGS) -lreadline -o $(NAME)
	make clean
	./$(NAME)

fclean : clean
	$(RM) $(NAME)

clean :
	$(RM) *.o
	$(RM) lexer/*.o

re : fclean all
