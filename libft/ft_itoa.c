/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 12:20:00 by osyalcin          #+#    #+#             */
/*   Updated: 2022/06/25 04:51:30 by osyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	itoacount(int n)
{
	int	l;

	l = 0;
	if (n <= 0)
	{
		l++;
	}
	while (n)
	{
		n /= 10;
		l++;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	int		k;
	char	*last;

	k = itoacount(n);
	last = (char *) ft_calloc(k + 1, sizeof(char));
	if (!last)
		return (0);
	if (n == 0)
		*last = '0';
	else if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_strlcpy(last, "-2147483648", k + 1);
			return (last);
		}
		last[0] = '-';
		n *= -1;
	}
	while (n)
	{
		*(last + --k) = (n % 10) + 48;
		n /= 10;
	}
	return (last);
}

