/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   colect.c										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jinacio- <jinacio-@student.42sp.org.br>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/12/10 00:35:55 by jinacio-		  #+#	#+#			 */
/*   Updated: 2021/12/10 01:39:53 by jinacio-		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "so_long.h"

void	check_colect(t_general *itens)
{
	int		fd;
	char	*box;
	int		i;

	itens->rupees = 0;
	fd = open (itens->local, O_RDONLY);
	box = get_next_line(fd);
	while (box)
	{
		i = 0;
		while (box[i] != '\0')
		{
			if (box[i] == 'C')
				itens->rupees = itens->rupees + 1;
			i++;
		}
		free (box);
		box = get_next_line(fd);
	}
	close (fd);
}

void	colect_and_exit_w(t_general *itens, char c, int n1, int n2)
{
	if (c == 'C')
	{
		itens->maps[n1 - 1][n2] = '0';
		itens->rupees = itens->rupees - 1;
	}
}

void	colect_and_exit_s(t_general *itens, char c, int n1, int n2)
{
	if (c == 'C')
	{
		itens->maps[n1 + 1][n2] = '0';
		itens->rupees = itens->rupees - 1;
	}
}

void	colect_and_exit_a(t_general *itens, char c, int n1, int n2)
{
	if (c == 'C')
	{
		itens->maps[n1][n2 - 1] = '0';
		itens->rupees = itens->rupees - 1;
	}
}

void	colect_and_exit_d(t_general *itens, char c, int n1, int n2)
{
	if (c == 'C')
	{
		itens->maps[n1][n2 + 1] = '0';
		itens->rupees = itens->rupees - 1;
	}
}
