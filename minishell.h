/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:06:40 by osyalcin          #+#    #+#             */
/*   Updated: 2022/09/07 15:35:43 by osyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/history.h>
# include <string.h>
# include <errno.h>
# include <sys/wait.h>

typedef struct s_errorcode
{
	int	illegalflag;
	int	nosuchfile;
}	t_errorcode;

typedef struct s_lexout
{
	char		*box1;
	int			box1index;
	char		*box2;
	int			box2index;
	int			box2runaway;
	int			box2space;
	int			box2lastisspace;
	char		*box3;
	int			box3index;
	char		*box4;
	int			box4index;
	int			box4space;
	t_errorcode	error;
}	t_lexout;

typedef struct s_node
{
	char			*command;
	char			*flags;
	char			*argument;
	char			*redirections;
	struct s_node	*next_node;
	struct s_node	*previous_node;
}	t_node;

typedef struct s_shell
{
	t_node	*head;
}	t_shell;

// main
void	fillboxes(t_lexout *tolex);
int		lexer(char *argv, t_lexout *tolex, t_shell *shell);

//box1
int		firstbox(char *argv, t_lexout *tolex);
int		inquote(char *argv, t_lexout *tolex);
int		box1indoublequote(char *argv, t_lexout *tolex);
int		box1insinglequote(char *argv, t_lexout *tolex);

//box2
int		secondbox(char *argv, t_lexout *tolex);
int		secondboxinquote(char *argv, t_lexout *tolex);
int		secondboxinsinglequote(char *argv, t_lexout *tolex);
int		isbeforeflag(t_lexout *tolex);

//box3
int		thirdbox(char *argv, t_lexout *tolex);
int		box3inquote(char *argv, t_lexout *tolex);
int		box3escapespace(char *argv, t_lexout *tolex);

//box4
void	fourthbox(char *argv, t_lexout *tolex);
int		box4inquote(char *argv, t_lexout *tolex);
int		box4insinglequote(char *argv, t_lexout *tolex);
int		box4greatgreat(char *argv, t_lexout *tolex);
int		box4great(char *argv, t_lexout *tolex);
int		box4lessless(char *argv, t_lexout *tolex);
int		box4less(char *argv, t_lexout *tolex);
int		box4wtf(char *argv, t_lexout *tolex);
int		box4inquote_mode2(char *argv, t_lexout *tolex);
int		box4insinglequote_mode2(char *argv, t_lexout *tolex);

//command_table.c
void	create_node(t_shell *shell, t_lexout table);

// utility
char	*lexer_ft_strjoin(char *s1, char *s2);
int		lexer_ft_strlen(char *s1);
int		lexer_escapespace(char *argv, t_lexout *tolex);

#endif