#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <readline/readline.h>
#include <stdlib.h>
#include <unistd.h>
#include <readline/history.h>
#include <string.h>
#include <errno.h>
#include <sys/wait.h>

typedef struct s_lexout
{
	char	*box1;
	char	*box2;
	char	*box3;
	char	*box4;
	int		box1index;
	int		box2index;
	int		box3index;
	int		box4index;
	int		box2runaway;
} t_lexout;

typedef struct s_node
{
	char *command;
	char *flags;
	char *argument;
	char *redirections;
	struct s_node *next_node;
	struct s_node *previous_node;
	char *cmd_path;
	int is_builtin;
}	t_node;

typedef struct s_shell
{
	int err_code;
	char **env;
	t_node *head;
}	t_shell;

// main
void	fillboxes(t_lexout *tolex);
int		lexer(char *argv, t_lexout *tolex);

//box1
int	firstbox(char *argv, t_lexout *tolex);
int	inquote(char *argv, t_lexout *tolex);
int	box1indoublequote(char *argv, t_lexout *tolex);
int	box1insinglequote(char *argv, t_lexout *tolex);

//command_table.c
void create_node(t_shell *shell, t_lexout table);

//finish.c
void	print_error(t_shell *shell);

// utility
int	ft_strlen(char *s1);
int	escapespace(char *argv);
int	ft_strncmp(const char *s1, const char *s2, size_t size);
int	ft_strncmp_exact(const char *s1, const char *s2, size_t size);
char	*ft_strjoin_path(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);

#endif