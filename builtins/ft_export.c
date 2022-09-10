#include "../minishell.h"

void    ft_just_export(t_shell *shell)
{
    int i;

    i = 0;
    while (shell->data->env_in[i])
    {
        printf("declare -x %s\n", shell->data->env_in[i]);
        i++;
    }
}

char    **ft_add_malloc_for_env(t_shell *shell)
{
    int i;
    char **new;

    i = 0;
    while(shell->data->env_in[i])
        i++;
    new =  (char **)malloc(sizeof(char *) * (++i + 1));
    i = 0;
    while (shell->data->env_in[i])
    {
        new[i] = shell->data->env_in[i];
        i++;
    }
    new[i + 1] = 0;
    free(shell->data->env_in);
    return (new);
}

char    **ft_export(t_shell *shell)
{
    int i;
    int j;
    int k;

    if (shell->data->arg[1])
        ft_just_export(shell);
    else
    {
        k = 0;
        while (shell->data->arg[++k])
        {
            i = 0;
            j = 0;
            while (shell->data->env_in[i])
                i++;
            while(shell->data->arg[k][j])
                j++;
            shell->data->env_in = ft_add_malloc_for_env(shell);
            shell->data->env_in[i] = (char *)malloc(sizeof(char) * (j + 1));
            ft_strncpy(shell->data->env_in[i], shell->data->arg[k], j);
        }
    }
    return (shell->data->env_in);
}

void    ft_env(t_shell *shell)
{
    int j;

    j = 0;
    while(shell->data->env_in[j])
        printf("%s\n", shell->data->env_in[j++]);
}

//env işleminide burada cağırıyorum.
//export with no options!!Maybe arg!!
//return olarak cevirdiğimiz için mainde verilirken **env üzerinden verilicek.(export için!)
//env ise kopyalanan env üzerinden çekilicek.