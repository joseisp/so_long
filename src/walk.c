/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinacio- <jinacio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:45:24 by jinacio-          #+#    #+#             */
/*   Updated: 2021/12/13 05:55:24 by jinacio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sweepd(t_general *itens)
{
	int		i;
	int		j;
	char	aux;

	i = 0;
	j = 0;
	while (i < itens->county)
	{
		j = 0;
		while (j < itens->countx)
		{
			if (itens->maps[i][j] == 'P' && val(itens, itens->maps[i][j + 1]))
			{
				if (itens->maps[i][j + 1] == 'C' || itens->maps[i][j + 1] ==
				'E')
					colect_and_exit_d(itens, itens->maps[i][j + 1], i, j);
				aux = itens->maps[i][j + 1];
				itens->maps[i][j + 1] = itens->maps[i][j];
				itens->maps[i][j] = aux;
				j++;
			}
			j++;
		}
		i++;
	}
}

void	sweepa(t_general *itens)
{
	int		i;
	int		j;
	char	aux;

	i = 0;
	j = 0;
	while (i < itens->county)
	{
		j = 0;
		while (j < itens->countx)
		{
			if (itens->maps[i][j] == 'P' && val(itens, itens->maps[i][j - 1]))
			{
				if (itens->maps[i][j - 1] == 'C' || itens->maps[i][j - 1] ==
				'E')
					colect_and_exit_a(itens, itens->maps[i][j - 1], i, j);
				aux = itens->maps[i][j - 1];
				itens->maps[i][j - 1] = itens->maps[i][j];
				itens->maps[i][j] = aux;
				j++;
			}
			j++;
		}
		i++;
	}
}

void	sweeps(t_general *itens)
{
	int		i;
	int		j;
	char	aux;

	i = 0;
	j = 0;
	while (i < itens->county)
	{
		j = 0;
		while (j < itens->countx)
		{
			if (itens->maps[i][j] == 'P' && val(itens, itens->maps[i + 1][j]))
			{
				if (itens->maps[i + 1][j] == 'C' || itens->maps[i + 1][j] ==
				'E')
					colect_and_exit_s(itens, itens->maps[i + 1][j], i, j);
				aux = itens->maps[i + 1][j];
				itens->maps[i + 1][j] = itens->maps[i][j];
				itens->maps[i][j] = aux;
				i++;
			}
			j++;
		}
		i++;
	}
}

void	sweepw(t_general *itens)
{
	int		i;
	int		j;
	char	aux;

	i = 0;
	j = 0;
	while (i < itens->county)
	{
		j = 0;
		while (j < itens->countx)
		{
			if (itens->maps[i][j] == 'P' && val(itens, itens->maps[i - 1][j]))
			{
				if (itens->maps[i - 1][j] == 'C' || itens->maps[i - 1][j] ==
				'E')
					colect_and_exit_w(itens, itens->maps[i - 1][j], i, j);
				aux = itens->maps[i - 1][j];
				itens->maps[i - 1][j] = itens->maps[i][j];
				itens->maps[i][j] = aux;
				i++;
			}
			j++;
		}
		i++;
	}
}

void	walkright(t_general *itens, char c)
{
	if (c == 'd')
	{
		walktoright(itens);
	}
	else if (c == 'a')
	{
		walktoleft(itens);
	}
	else if (c == 's')
	{
		walktodown(itens);
	}
	else if (c == 'w')
	{
		walktoup(itens);
	}
}
