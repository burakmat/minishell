#include "minishell.h"


int	ft_strlen(char *s1)
{
	int a;

	if (!s1)
		return (NULL);
	a = 0;
	while (s1[a] != '\0')
		a++;
	return (a);
}

unsigned int	str_in_array(char *s, char delimiter)
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

char	**ft_split(char *s, char c)
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

int	ft_strncmp(char *s1, char *s2, int size)
{
	int	i;

	i = 0;
	while (i < size && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_strncmp_exact(char *s1, char *s2, int size)
{
	int	i;

	i = 0;
	while (i < size && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	ft_strlcpy(char *dst, char *src, int b)
{
	int	a;
	int	c;

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

char	*ft_strjoin_path(char *s1, char *s2)
{
	int	a;
	char	*last;
	int	b;

	if (s2 == NULL)
		return(ft_strdup(s1));	
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

void	*ft_calloc(size_t count, size_t size)
{
	void	*ps;

	ps = malloc(size * count);
	if (ps == 0)
		return (0);
	ft_bzero(ps, size * count);
	return (ps);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	a;

	a = 0;
	while (a < len)
	{
		((unsigned char *)b)[a] = (unsigned char)c;
		a++;
	}
	return (b);
}

char	*ft_strdup(const char *s1)
{
	char	*s;
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	s = (char *)malloc(sizeof(char) * len + 1);
	if (!s)
		return (0);
	while (s1[i] != '\0')
	{
		s[i] = s1[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}
