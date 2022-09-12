#include "minishell.h"

void	set_input_for_redirections(t_shell *shell, t_node *node)
{
	int		i;
	int		j;
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
				if ()
				++j;
			}
			++i;
		}
		--i;
		while (node->redirections)
	}
}