#include "minishell.h"

int	check_input_redirections(t_shell *shell, t_node *node)
{
	int		i;
	int		j;
	int		fd;
	int		in;
	char	**re;

	if (node->redirections != NULL)
	{
		in = 0;
		re = ft_split(node->redirections, ' ');
		i = 0;
		while (re[i] != NULL)
		{
			j = 0;
			if (re[i][j] == '<' && re[i][j + 1] != '<')
			{
				fd = open(&re[i][j + 1], O_RDONLY, 0777);
				if (fd < 0)
				{
					write(2, &re[i][j + 1], ft_strlen(&re[i][j + 1]));
					write(1, ": No such file or directory\n", 28);
					exit(1);
				}
				close(fd);
				++in;
			}
			else if (re[i][j] == '<' && re[i][j + 1] == '<')
				++in;
			++i;
		}
		free_2d_char(re);
		return (in);
	}
	return (0);
}

void	set_input_redirections(t_shell *shell, t_node *node)//not done
{
	char	**re;
	int		i;
	int		j;
	int		fd;
	char	*buffer;
	int		pipes[2];
	int		last;

	if (node->redirections != NULL)
	{
		last = -1;
		re = ft_split(node->redirections, ' ');
		i = 0;
		while (i)
		{
			j = 0;	
			if (re[i][j] == '<' && re[i][j + 1] != '<')
			{
				fd = open(&re[i][j + 1], O_RDONLY, 0777);
				//hasn't been closed yet
				dup2(fd, 0);
				close(fd);
				node->in = 1;
				free_2d_char(re);
				return ;
			}
			else if (re[i][j] == '<' && re[i][j + 1] == '<')
			{
				printf("wtf2\n");
				buffer = NULL;
				pipe(pipes);
				while (1)
				{
					buffer = readline("> ");
					if (ft_strncmp_exact(buffer, &re[i][j + 2], ft_strlen(&re[i][j + 2])))
					{
						free(buffer);
						close(pipes[1]);
						break ;
					}
					else
					{
						write(pipes[1], buffer, ft_strlen(buffer));//write
						free(buffer);
					}
					
				}
			}
			++i;
		}
		free_2d_char(re);
	}
}

void	set_output_redirections(t_shell *shell, t_node *node)
{
	char	**re;
	int		i;
	int		j;
	int		fd;

	if (node->redirections != NULL)
	{
		re = ft_split(node->redirections, ' ');
		i = 0;
		while (re[i] != NULL)
			++i;
		--i;
		while (i + 1)
		{
			j = 0;
			if (re[i][j] == '>' && re[i][j + 1] != '>' && node->out == 0)
			{
				fd = open(&re[i][j + 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
				dup2(fd, 1);
				close(fd);
				node->out = 1;
			}
			else if (re[i][j] == '>' && re[i][j + 1] != '>')
			{
				fd = open(&re[i][j + 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
				close(fd);
			}
			else if (re[i][j] == '>' && re[i][j + 1] == '>' && node->out == 0)
			{
				fd = open(&re[i][j + 2], O_WRONLY | O_CREAT | O_APPEND, 0777);
				dup2(fd, 1);
				close(fd);
				node->out = 1;
			}
			else if (re[i][j] == '>' && re[i][j + 1] == '>')
			{
				fd = open(&re[i][j + 2], O_WRONLY | O_CREAT | O_APPEND, 0777);
				close(fd);
			}
			--i;
		}
		free_2d_char(re);
	}
}
