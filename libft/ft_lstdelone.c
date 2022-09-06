/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:28:00 by osyalcin          #+#    #+#             */
/*   Updated: 2022/06/25 04:37:09 by osyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	del(lst ->content);
	free(lst);
}

/*
void	ft_del(void *lstdel)
{
	free(lstdel);
}


int main ()
{
	t_list *list;
	t_list *next;
	list = ft_lstnew(ft_strdup("hello"));
	ft_lstadd_back(&list, ft_lstnew(ft_strdup("world")));
	next = list->next;
	ft_lstdelone(list,ft_del);
	printf("%s",(char *)list->content);
	system("leaks a.out");
}*/