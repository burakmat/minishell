#include "minishell.h"
/*
int ft_control_env(char *env)
{
    int i;

    i = 0;
    while (env[i])
    {
        if (env[i] == '=')
            return (1);
        i++;
    }
    return (0);
}

void    ft_env_new(char **env)
{
    int i;
    int j;

    j = 0;
    while (env[j] && ft_control_env(env[j]))
        j++;
    just_env =  (char **)malloc(sizeof(char *) * (j + 1));
    j = -1;
    while (env[++j])
    {
        i = 0;
        if (ft_control_env(env[j]))
        {
            while (env[j][i])
                i++;
            just_env[j] = (char *)malloc(sizeof(char *) * (i + 1));
            i = -1;
            while (env[j][++i])
            {
                just_env[j][i] = env[j][i];
            }  
        }
    }
}*/
//just_env ayarlanmalı.