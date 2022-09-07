#include "../minishell.h"


int	ft_strlen(char *s1)
{
	int a;

	a = 0;
	while (s1[a] != '\0')
		a++;
	return (a);
}

unsigned int	str_in_array(const char *s, char delimiter)
{
	unsigned int	qnt;

	qnt = 0;
	while (*s)
	{
		if (*s == delimiter)
			s++;
		else
		{
			while (*s != delimiter && *s)
				s++;
			qnt++;
		}
	}
	return (qnt);
}

char	**ft_split(char const *s, char c)
{
	char			**arr;
	unsigned int	j;
	unsigned int	a;

	if (!s)
		return (NULL);
	arr = (char **) ft_calloc(str_in_array(s, c) + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	a = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			j = 0;
			while (*s != c && *s && ++j)
				s++;
			arr[++a -1] = (char *) ft_calloc(j + 1, sizeof(char));
			ft_strlcpy(arr[a -1], s - j, j + 1);
		}
	}
	return (arr);
}

int	ft_strncmp(const char *s1, const char *s2, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_strncmp_exact(const char *s1, const char *s2, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t b)
{
	size_t	a;
	size_t	c;

	a = 0;
	c = ft_strlen(src);
	if (b > 0)
	{
		while (a < b - 1 && src[a])
		{
			dst[a] = src[a];
			a++;
		}
			dst[a] = '\0';
	}
	return (c);
}

char	*ft_strjoin_path(char const *s1, char const *s2)
{
	size_t	a;
	char	*last;
	size_t	b;

	a = 0;
	b = ft_strlen(s1);
	last = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!last || !s1)
		return (0);
	ft_strlcpy(last, s1, ft_strlen(s1) + 1);
	last[b] = '/';
	ft_strlcpy(&last[b + 1], s2, ft_strlen(s2) + 1);
	return (last);
}
