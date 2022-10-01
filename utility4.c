/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osyalcin <osyalcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 10:18:28 by osyalcin          #+#    #+#             */
/*   Updated: 2022/09/23 10:30:42 by osyalcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_line(char *str)
{
	char	*line;
	int		i;
	int		j;

	if (!(*str))
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i])
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = str[j];
		++j;
	}
	line[j] = '\0';
	return (line);
}

char	*reading_from_file(int fd, char *str)
{
	char	*buf;
	int		byte_num;

	byte_num = 1;
	buf = malloc(2);
	if (!buf)
		return (NULL);
	while (check_newline(str) && byte_num)
	{
		byte_num = read(fd, buf, 1);
		if (byte_num == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[byte_num] = '\0';
		str = append_string(str, buf);
	}
	free(buf);
	return (str);
}

char	*shift_to_endline(char *str)
{
	char	*shifted_str;
	int		i;
	int		j;

	i = 0;
	while (str[i] && str[i] != '\n')
		++i;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	++i;
	shifted_str = malloc(string_length(str) - i + 1);
	if (!shifted_str)
		return (NULL);
	j = 0;
	while (j < string_length(str) - i)
	{
		shifted_str[j] = str[j + i];
		j++;
	}
	shifted_str[j] = '\0';
	free(str);
	return (shifted_str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0)
		return (NULL);
	str = reading_from_file(fd, str);
	if (!str)
		return (NULL);
	line = get_line(str);
	str = shift_to_endline(str);
	return (line);
}
