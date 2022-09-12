#include "../minishell.h"

void	builtin_export(t_shell *shell)
{
	show_export(shell);
}
void	show_export(t_shell *shell)
{
	int		i;
	int		a;
	char	t;

	i = 0;
	while (shell->env[i])
	{
		a = 0;
		t = 0;
		write(1, "declare -x ", 12);
		while (shell->env[i][a] != '=' && shell->env[i][a] != '\0')
		{
			write(1, &shell->env[i][a], 1);
			a++;
		}
		if (shell->env[i][a] == '=')
		{
			write(1, "=\"", 2);
			t = 1;
		}
		while (shell->env[i][a] != '\0')
		{
			a += 1;
			write(1, &shell->env[i][a], 1);
		}
		if (t == 1)
			write(1, "\"", 1);
		printf("\n");
		i++;
	}
}