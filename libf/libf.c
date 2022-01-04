/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   libs.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jinacio- <jinacio-@student.42sp.org.br>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/12/09 17:49:37 by jinacio-		  #+#	#+#			 */
/*   Updated: 2021/12/13 01:34:59 by jinacio-		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libf.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	int		size;

	size = ft_strlen(s1) + 1;
	cpy = (char *)malloc(size);
	if (cpy)
		ft_strlcpy (cpy, s1, size);
	return (cpy);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	strlen;

	if (!s)
		return (0);
	strlen = ft_strlen(s);
	if (start > strlen)
	{
		len = 0;
		start = strlen;
	}
	else if (start + len > strlen)
		len = strlen - start;
	ptr = (char *)malloc(len + 1 * sizeof(char));
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, s + start, len + 1);
	return (ptr);
}

size_t	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*conc;
	size_t	i;
	size_t	size_s1;
	size_t	size_s2;

	i = -1;
	size_s1 = 0;
	size_s2 = 0;
	while (s1[size_s1])
		size_s1++;
	while (s2[size_s2])
		size_s2++;
	conc = malloc((size_s2 + size_s1 + 1) * sizeof(char));
	while (++i < size_s1)
		conc[i] = s1[i];
	i = -1;
	while (++i < size_s2)
		conc[i + size_s1] = s2[i];
	conc[size_s2 + size_s1] = '\0';
	free(s1);
	return (conc);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t sizedest)
{
	size_t	nbytes;
	size_t	i;

	i = 0;
	nbytes = ft_strlen(src);
	if (!src || !dest)
		return (0);
	if (sizedest != 0)
	{
		while (src[i] != '\0' && i < (sizedest - 1))
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (nbytes);
}
