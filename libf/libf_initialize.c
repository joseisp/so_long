/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libf_initialize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinacio- <jinacio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:06:33 by jinacio-          #+#    #+#             */
/*   Updated: 2021/12/13 21:38:23 by jinacio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libf.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*one;
	unsigned char	*two;

	i = 0;
	one = (unsigned char *)s1;
	two = (unsigned char *)s2;
	while ((one[i] || two[i]) && i < n)
	{
		if (one[i] != two[i])
			return (one[i] - two[i]);
		i++;
	}
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_size;
	size_t	i;

	i = 0;
	little_size = ft_strlen(little);
	if (!(*little))
		return ((char *)big);
	while (*big && (i < len))
	{
		if ((ft_strncmp(big, little, little_size) == 0)
			&& (i + little_size <= len))
			return ((char *)big);
		big++;
		i++;
	}
	return (NULL);
}
