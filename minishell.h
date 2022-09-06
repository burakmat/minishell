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

typedef struct s_errorcode
{
	int	illegalflag;
	int nosuchfile;
} t_errorcode;

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
	t_errorcode *error;
} t_lexout;

// main
void	fillboxes(t_lexout *tolex);
int		lexer(char *argv, t_lexout *tolex);

//box1
int	firstbox(char *argv, t_lexout *tolex);
int	inquote(char *argv, t_lexout *tolex);
int	box1indoublequote(char *argv, t_lexout *tolex);
int	box1insinglequote(char *argv, t_lexout *tolex);

//box2
int	secondbox(char *argv, t_lexout *tolex);
int	secondboxinquote(char *argv, t_lexout *tolex);

// utility
char	*ft_strjoin(char *s1, char *s2);
int	ft_strlen(char *s1);
int	escapespace(char *argv);

#endif