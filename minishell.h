/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 12:06:40 by osyalcin          #+#    #+#             */
/*   Updated: 2022/09/16 15:17:27 by osyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <signal.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_lexout
{
	char		*box1;
	int			box1index;
	int			boxwasin;
	char		*box2;
	int			box2index;
	int			box2runaway;
	int			box2space;
	int			box2lastisspace;
	char		*box3;
	int			box3index;
	int			box3null;//number of nulls in argument
	int			box3space;
	char		*box4;
	int			box4index;
	int			box4space;
	int			illegalflag;//if 1 going through, 0 split into spaces
	int			currentnode;//starts from 0
	int			totalnode;
	int			illegalcommand;
	
}	t_lexout;

typedef struct s_free
{
	char **my_path;
}	t_free;

typedef struct s_node
{
	char *command;
	char *flags;
	char *argument;
	char *redirections;
	struct s_node *next_node;
	struct s_node *previous_node;
	char *cmd_path;
	char **exec_args;
	char **my_path;
	int id;
	int is_builtin;
	int	null_num;
	int	illegalflag;
	int illegalcommand;
	int in;
	int out;
}	t_node;

typedef struct s_shell
{
	int **pipes;
	int	totalnode;
	int err_code;
	char **env;
	char	*temp_readline;
	int		readline_index;
	int		exit_status;
	int		exit_status_before;
	t_node *head;
	t_node *tail;
	t_free free_;
}	t_shell;

// main
void	fillboxes(t_lexout *tolex, t_shell *shell);
int		lexer(char *argv, t_lexout *tolex, t_shell *shell);
void	fillboxesstatic(t_lexout *tolex, t_shell *shell);

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
void	box4_check(t_shell *shell, t_lexout *tolex);
void	box4_go_to_check(t_shell *shell, char *argv);

//total node

void	totalnode(char *argv, t_lexout *tolex, t_shell *shell);
int		totalnodeinquote(char *argv, t_shell *shell);
int		totalnodeinsinglequote(char *argv, t_shell *shell);

//dollar_sign
char	*dollar_sign(char *argv, t_shell *shell);
int	dollarsign_check(char *argv, t_shell *shell);
int	dollarsign_inquote(char *argv, t_shell *shell);
int	dollarsign_insinglequote(char *argv, t_shell *shell);

//command_table.c
void	create_node(t_shell *shell, t_lexout *table);
char *search_in_path(t_shell *shell, t_node *node);
char **split_path(t_shell *shell, int ind);
void edit_first_path(char **all_path_copy);
int	is_there_path(t_shell *shell);
int		builtin_check(char *command);
void	free_all_path(char **path);

//list_utils.c
void	clear_all_nodes(t_node *head);
void	freeexec_args(t_node *node);
void	free_shell_pipes(t_shell *shell);

// utility
char	*lexer_ft_strjoin(char *s1, char *s2);
int		lexer_ft_strlen(char *s1);
int		lexer_escapespace(char *argv, t_lexout *tolex);
int		box4escapespace(char *argv, t_lexout *tolex);
int		ft_strlen(char *s1);
int		ft_strncmp(char *s1, char *s2, int size);
int		ft_strncmp_exact(char *s1, char *s2, int size);
char	*ft_strjoin_path(char *s1, char *s2);
char	**ft_split(char *s, char c);
void	*ft_calloc(size_t count, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *b, int c, size_t len);
int		ft_strlcpy(char *dst, char *src, int b);
char	*ft_strdup(const char *s1);
char	**duplicate_env(char **env);
void	free_2d_char(char **arr);

//temp
void	readbox3(char *argv);

//finish.c
void	print_error(t_shell *shell, t_node *node);

//execute
void	execute(t_shell *shell, t_node *node);
void	go_to_builtin(t_shell *shell, t_node *node, char *argv);
//set_nodes.c
void	set_node(t_shell *shell, t_node *node);

//pipe.c
void	create_pipes(t_shell *shell);
void close_unnecessary_fd(t_shell *shell, t_node *node);
void close_all_node_fd(t_shell *shell);

//builtin
char	*ft_strjoin_builtin(char *s1, char *s2);
void	builtin_echo(t_node *node);
void	free_oldenv(t_shell *shell);
void	re_malloc_env(t_shell *shell, t_node *node, int i);
void	add_env(t_shell *shell, t_node *node, int a);
void	builtin_export(t_shell *shell);
void	show_env(t_shell *shell);
int	env_dup_check(t_shell *shell, char *argv);
void	different_value(t_shell *shell, t_node *node);
int		is_env_valid(char *argv, int mode);
int		ft_strncmp_builtin(char *s1, char *s2, int a);
int 	is_last_equal(char *argv);
void	show_export(char **temp);
void	builtin_exit();
int	compare_ascii(char **temp);
//pwd & cd
void	builtin_pwd();
void	builtin_cd(t_shell *shell ,t_node *node);
void	find_env_path(t_shell *shell, t_node *node);
void	edit_envt_path(t_shell *shell);
char	*ft_strjoin_env(char *s1, char *s2);
char	*ft_strdup_env(char *s1);
void	extra_env_path(t_shell *shell, t_node *node);

//env
void	builtin_env(t_shell *shell);
void	show_env(t_shell *shell);
int		env_is_there_equal(char *argv);

//edit env
void	edit_unset(t_shell *shell, t_node *node);
int	builtin_exist(t_shell *shell, char *argv);
void	build_new_env(t_shell *shell);

//handle_redirect.c
int		check_input_redirections(t_shell *shell, t_node *node);
void	set_input_redirections(t_shell *shell, t_node *node, int input_num);
void	set_output_redirections(t_shell *shell, t_node *node);

#endif