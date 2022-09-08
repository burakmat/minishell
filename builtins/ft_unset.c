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

void    ft_unset(char **env, char **arg)
{
    int     i;
    int     j;
    int     k;
    char    **tmp;

    j = 0;
    while (arg[++j])
    {
        k = ft_strlen(arg[j]);
        i = 0;
        while (env[i])
        {
            if (ft_strncmp(env[i], arg[j], k) == 0)
            {
                tmp = env;
                ft_delete(env ,tmp);
            }
            else
                i++;
        }
    }
}