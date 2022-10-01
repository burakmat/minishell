SRCS = main.c builtins/builtin_utils.c builtins/cd_norm.c builtins/cd.c builtins/echo.c builtins/env_edit_v2.c \
	builtins/env_edit.c builtins/env.c builtins/exit.c builtins/export.c builtins/pwd.c \
	utility.c command_table.c finish.c execute.c list_utils.c \
	set_nodes.c pipe.c handle_redirect.c utility2.c utility3.c path_utils.c \
	set_flags.c set_input_source.c handle_heredoc.c utility4.c utility5.c \
	lexer/box1.c lexer/box2_fornorm.c lexer/box2.c lexer/box3_fornorm.c lexer/box3.c \
	lexer/box4_check.c lexer/box4_fornorm.c lexer/box4.c lexer/dollar_sign_fornorm.c \
	lexer/dollar_sign.c lexer/forbox4.c lexer/lexer_utility_2.c lexer/lexer_utility.c \
	lexer/lexer.c lexer/totalnode.c

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
	$(RM) builtins/*.o

ffclean: fclean
	$(RM) $(LIB) ./lib/readline

re : fclean all
