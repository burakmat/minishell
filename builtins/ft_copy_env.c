#include "../minishell.h"

void ft_malloc_for_env(t_data *data, char **env)
{
    int i;
    int j;

    j = 0;
    while (env[j])
        j++;
    data->env_in = (char **)malloc(sizeof(char *) * (j + 1));
    j = 0;
    while(env[j])
    {
        i = 0;
        while (env[j][i])
            i++;
        data->env_in[j] = (char *)malloc(sizeof(char) * (i + 1));
        i = 0;
        j++;
    }
}

void    ft_copy_env(t_data *data, char **env)
{
    int i;
    int j;

    i = 0;
    j = 0;
    ft_malloc_for_env(data, env);
    while(env[j])
    {
        while(env[j][i])
        {
            data->env_in[j][i] = env[j][i];
            i++;
        }
        j++;
        i = 0;
    }
}

