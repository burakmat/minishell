#include "minishell.h"

// Bu fonksiyonda mallocla ilgili hata var onlara bakmamız lazım bi!!
//10-15dk'lık işi var unsetin.

void    ft_delete(char **env, char **tmp)
{
    int i;
    (void)env;

    i = 0;
    while(tmp[i])
        i++;
    i--;
    free(tmp[i]);
}

void    ft_unset(t_shell *shell)
{
    int     i;
    int     j;
    int     k;
    char    **tmp;

    j = 0;
    while (shell->data->arg[++j])
    {
        k = ft_strlen(shell->data->arg[j]);
        i = 0;
        while (shell->data->env_in[i])
        {
            if (ft_strncmp(shell->data->env_in[i], shell->data->arg[j], k) == 0)
            {
                tmp = shell->data->env_in;
                ft_delete(shell->data->env_in ,shell->data->temp);
            }
            else
                i++;
        }
    }
}