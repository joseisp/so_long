/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinacio- <jinacio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:47:09 by jinacio-          #+#    #+#             */
/*   Updated: 2021/12/14 01:16:15 by jinacio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(t_general *itens)
{
	check_rectangle(itens);
	check_wall(itens);
	check_elements(itens);
}

int	define(t_general *itens)
{
	if (itens->character > 0 && itens->castle_exit > 0 && itens->colection > 0)
		return (1);
	else
	{
		printf("Error\nPlease check the elements in your map.ber\n");
		exit (1);
	}
}

void	check_elements(t_general *itens)
{
	int	i;
	int	j;

	i = 0;
	itens->castle_exit = 0;
	itens->colection = 0;
	itens->character = 0;
	while (itens->maps[i])
	{
		j = 0;
		while (itens->maps[i][j])
		{
			if (itens->maps[i][j] == 'E')
				itens->castle_exit++;
			else if (itens->maps[i][j] == 'C')
				itens->colection++;
			else if (itens->maps[i][j] == 'P')
				itens->character++;
			j++;
		}
		i++;
	}
	define(itens);
}

void	check_rectangle(t_general *itens)
{
	char	*i;
	int		n1;

	i = itens->maps[0];
	n1 = 0;
	while (itens->maps[n1])
	{
		if (ft_strlen(itens->maps[n1]) != ft_strlen(i))
		{
			printf("Error\n Maps not rectangular. Please, check the map.\n");
			exit (1);
		}
		n1++;
	}
}

void	check_wall(t_general *itens)
{
	int	i;

	i = 0;
	while (itens->maps[0][i] != '\0' && itens->maps[itens->county - 1][i] !=
	'\0')
	{
		if (itens->maps[0][i] != '1' || itens->maps[itens->county - 1][i] !=
		'1')
		{
			printf("ERROR\nYou need to check the walls in the map.\n");
			exit (1);
		}
		i++;
	}
	i = 0;
	while (i < itens->county)
	{
		if (itens->maps[i][0] != '1' || itens->maps[i][itens->countx - 1] !=
		'1')
		{
			printf("ERROR\nYou need to check the walls in the map.\n");
			exit (1);
		}
		i++;
	}
}
