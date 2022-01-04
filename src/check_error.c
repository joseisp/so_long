/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinacio- <jinacio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 22:34:27 by jinacio-          #+#    #+#             */
/*   Updated: 2021/12/13 23:06:48 by jinacio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_matrix(t_general *itens)
{
	int	i;

	i = 0;
	while (itens->maps[i])
	{
		free(itens->maps[i]);
		i++;
	}
	free(itens->maps);
}

int	closee(t_general *itens)
{
	mlx_destroy_image(itens->mlx, itens->floor);
	mlx_destroy_image(itens->mlx, itens->wall);
	mlx_destroy_image(itens->mlx, itens->link);
	mlx_destroy_image(itens->mlx, itens->castle);
	mlx_destroy_image(itens->mlx, itens->colect);
	mlx_destroy_window(itens->mlx, itens->win);
	mlx_destroy_display(itens->mlx);
	free_matrix(itens);
	free(itens->mlx);
	exit (1);
}

void	check_name(t_general *itens)
{
	char	*error_name;
	int		i;

	i = 0;
	i = ft_strlen(itens->local);
	error_name = ft_strnstr(itens->local, ".ber", i);
	if (error_name == NULL)
	{
		printf("Error\nPlease check the name .ber!\n");
		closee(itens);
	}
}
