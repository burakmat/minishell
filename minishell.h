/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:06:40 by osyalcin          #+#    #+#             */
/*   Updated: 2022/09/08 10:37:58 by osyalcin         ###   ########.fr       */
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
	int			box3null;
	int			box3space;
	char		*box4;
	int			box4index;
	int			box4space;
	int			illegalflag;
}	t_lexout;

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
int		box3insinglequote(char *argv, t_lexout *tolex);

//box4
void	fourthbox(char *argv, t_lexout *tolex);
int		box4greatgreat(char *argv, t_lexout *tolex);
int		box4great(char *argv, t_lexout *tolex);
int		box4lessless(char *argv, t_lexout *tolex);
int		box4less(char *argv, t_lexout *tolex);
int		box4wtf(char *argv, t_lexout *tolex);
int		box4inquote_mode2(char *argv, t_lexout *tolex);
int		box4insinglequote_mode2(char *argv, t_lexout *tolex);
int		box4passquote(char *argv);
int		box4passsinglequote(char *argv);

//command_table.c
void	create_node(t_shell *shell, t_lexout *table);
char *search_in_path(t_shell *shell, t_node *node);
char **split_path(t_shell *shell, int ind);
void **edit_first_path(char **all_path_copy);
int	is_there_path(t_shell *shell);
void	free_table(t_node *node, t_lexout *table);
int		builtin_check(char *command);
void	stage_command(t_shell *shell, t_node *node);


// utility
char	*lexer_ft_strjoin(char *s1, char *s2);
int		lexer_ft_strlen(char *s1);
int		lexer_escapespace(char *argv, t_lexout *tolex);
int		box4escapespace(char *argv, t_lexout *tolex);
int	ft_strlen(char *s1);
int	ft_strncmp(char *s1, char *s2, int size);
int	ft_strncmp_exact(char *s1, char *s2, int size);
char	*ft_strjoin_path(char *s1, char *s2);
char	**ft_split(char *s, char c);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
int	ft_strlcpy(char *dst, char *src, int b);
//temp
void	readbox3(char *argv);
void create_node(t_shell *shell, t_lexout *table);

//finish.c
void	print_error(t_shell *shell);

#endif