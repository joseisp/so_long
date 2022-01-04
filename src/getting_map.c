/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getting_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinacio- <jinacio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:46:13 by jinacio-          #+#    #+#             */
/*   Updated: 2021/12/13 21:04:28 by jinacio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_sprites(t_general *itens)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	itens->floor = mlx_xpm_file_to_image(itens->mlx, "img/ground.xpm", &x, &y);
	itens->wall = mlx_xpm_file_to_image(itens->mlx, "img/wall.xpm", &x, &y);
	itens->link = mlx_xpm_file_to_image(itens->mlx, "img/down.xpm", &x, &y);
	itens->castle = mlx_xpm_file_to_image(itens->mlx, "img/castle.xpm", &x, &y);
	itens->colect = mlx_xpm_file_to_image(itens->mlx, "img/rupees.xpm", &x, &y);
}

static void	aux_insert_image(t_general *itens, char c)
{
	if (c == '1')
		mlx_put_image_to_window(itens->mlx, itens->win, itens->wall,
			(50 * itens->j), (50 * itens->i));
	else if (c == 'P')
		mlx_put_image_to_window(itens->mlx, itens->win, itens->link,
			(50 * itens->j), (50 * itens->i));
	else if (c == 'E')
		mlx_put_image_to_window(itens->mlx, itens->win, itens->castle,
			(50 * itens->j), (50 * itens->i));
	else if (c == 'C')
		mlx_put_image_to_window(itens->mlx, itens->win, itens->colect,
			(50 * itens->j), (50 * itens->i));
	else if (c == '0')
		mlx_put_image_to_window(itens->mlx, itens->win, itens->floor,
			(50 * itens->j), (50 * itens->i));
	else if (c == 'F')
	{
		printf("Error\nVerify the elements in the map.\n");
		exit(1);
	}
}

void	render(t_general *itens)
{
	itens->i = 0;
	mlx_clear_window(itens->mlx, itens->win);
	while (itens->i < itens->county)
	{
		itens->j = 0;
		while (itens->j < itens->countx)
		{
			if (itens->maps[itens->i][itens->j] == '1')
				aux_insert_image(itens, '1');
			else if (itens->maps[itens->i][itens->j] == 'P')
				aux_insert_image(itens, 'P');
			else if (itens->maps[itens->i][itens->j] == 'E')
				aux_insert_image(itens, 'E');
			else if (itens->maps[itens->i][itens->j] == 'C')
				aux_insert_image(itens, 'C');
			else if (itens->maps[itens->i][itens->j] == '0')
				aux_insert_image(itens, '0');
			else
				aux_insert_image(itens, 'F');
			itens->j++;
		}
		itens->i = itens->i + 1;
	}
}

void	getmap(t_general *itens)
{
	int		fd;
	char	*box;
	char	*insert;

	fd = open(itens->local, O_RDONLY);
	insert = ft_strdup("");
	box = get_next_line(fd);
	while (box)
	{
		insert = ft_strjoin(insert, box);
		free(box);
		box = get_next_line(fd);
	}
	itens->maps = ft_split(insert, '\n');
	free(insert);
	close(fd);
}
