#include "../minishell.h"

void    ft_just_export(char **env)
{
    int i;

    i = 0;
    while (env[i])
    {
        printf("declare -x %s\n", env[i]);
        i++;
    }
}

char    **ft_add_malloc_for_env(char **env)
{
    int i;
    char **new;

    i = 0;
    while(env[i])
        i++;
    new =  (char **)malloc(sizeof(char *) * (++i + 1));
    i = 0;
    while (env[i])
    {
        new[i] = env[i];
        i++;
    }
    new[i + 1] = 0;
    free(env);
    return (new);
}

char    **ft_export(char **env, char **arg)
{
    int i;
    int j;
    int k;

    if (!arg[1])
        ft_just_export(env);
    else
    {
        k = 0;
        while (arg[++k])
        {
            i = 0;
            j = 0;
            while (env[i])
                i++;
            while(arg[k][j])
                j++;
            env = ft_add_malloc_for_env(env);
            env[i] = (char *)malloc(sizeof(char) * (j + 1));
            ft_strncpy(env[i], arg[k], j);
        }
    }
    return (env);
}

void    ft_env(char **env)
{
    int j;

    j = 0;
    while(env[j])
        printf("%s\n", env[j++]);
}

//env işleminide burada cağırıyorum.
//export with no options!!Maybe arg!!
//return olarak cevirdiğimiz için mainde verilirken **env üzerinden verilicek.(export için!)
//env ise kopyalanan env üzerinden çekilicek.