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
	char	*last;
	int		mode;
	char	*box1;
	int		box1index;
	char	*box2;
	char	*box3;
	char	*box4;
} t_lexout;


int	lexer(char *argv, t_lexout *tolex);
int	isquoteempty(char *last1);
char	*ft_strjoin(char *s1, char *s2);
int	ft_strlen(char *s1);
int	doublequote(char *argv, t_lexout *tolex);
int	notquote(char *argv, t_lexout *tolex);
//box1
int	firstbox(char *argv, t_lexout *tolex);
int	inquote(char *argv, t_lexout *tolex);
int	box1indoublequote(char *argv, t_lexout *tolex);
int	box1insinglequote(char *argv, t_lexout *tolex);

//box2
int	secondbox(char *argv, t_lexout *tolex);

//box3
int	thirdbox(char *argv, t_lexout *tolex);

#endif