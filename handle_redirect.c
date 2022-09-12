#include "minishell.h"

void	check_input_redirections(t_shell *shell, t_node *node)
{
	int		i;
	int		j;
	int		fd;
	char	**re;

	if (node->redirections != NULL)
	{
		re = ft_split(node->redirections, ' ');
		i = 0;
		while (re[i] != NULL)
		{
			j = 0;
			while (re[i][j])
			{
				if (re[i][j] == '<' && re[i][j + 1] != '<')
				{
					fd = open(&re[i][j + 1], O_RDONLY, 0777);
					if (fd < 0)
					{
						write(2, &re[i][j + 1], ft_strlen(&re[i][j + 1]));
						write(1, ": No such file or directory\n", 28);
						exit(1);
					}
				}
				++j;
			}
			++i;
		}
		free_2d_char(re);
	}
}

void	set_input_redirections(t_shell *shell, t_node *node)
{
	
}