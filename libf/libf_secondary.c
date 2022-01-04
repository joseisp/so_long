/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libf_secondary.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinacio- <jinacio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 05:37:04 by jinacio-          #+#    #+#             */
/*   Updated: 2021/12/13 21:38:20 by jinacio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libf.h"

static size_t	count_word(char const *a, char w)
{
	size_t	i;
	size_t	count;

	i = 1;
	count = 0;
	while (*a)
	{
		if (*a == w)
		{
			i = 1;
		}
		else if (i == 1)
		{
			count++;
			i = 0;
		}
		a++;
	}
	return (count);
}

static size_t	count_letter(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**str;
	size_t	j;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	count_word(s, c);
	str = (char **)ft_calloc(count_word(s, c) + 1, sizeof(char *));
	if (!str)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			str[j] = ft_substr(s, i, count_letter(s + i, c));
			i = i + count_letter(s + i, c) - 1;
			j++;
		}
		i++;
	}
	return (str);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	*pos;
	size_t	tot_size;
	int		fill_byte;

	tot_size = nmemb * size;
	fill_byte = 0;
	pos = malloc(tot_size);
	if (!pos || (tot_size > INT_MAX))
		return (NULL);
	ft_memset(pos, fill_byte, tot_size);
	return ((void *)pos);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = c;
		i++;
	}
	return (s);
}
