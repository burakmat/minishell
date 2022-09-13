#include "../minishell.h"

void	builtin_pwd()
{
	char cwd[PATH_MAX];

	getcwd(cwd, sizeof(cwd));
	printf("%s\n", cwd);
}
