/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinacio- <jinacio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 02:48:11 by jinacio-          #+#    #+#             */
/*   Updated: 2021/12/14 01:38:03 by jinacio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_expose(t_general *itens)
{
	render(itens);
	return (1);
}

void	load_var(t_general *itens)
{
	itens->countx = 0;
	itens->county = 0;
	itens->moviment = 0;
	itens->local = "map.ber";
}

int	main(void)
{
	t_general		itens;

	load_var(&itens);
	itens.mlx = mlx_init();
	count_x(&itens);
	openwindow(&itens);
	getmap(&itens);
	check_colect(&itens);
	check_name(&itens);
	check_map(&itens);
	load_sprites(&itens);
	render(&itens);
	mlx_key_hook(itens.win, key_insert, &itens);
	mlx_hook(itens.win, 33, 1L << 5, closee, &itens);
	mlx_expose_hook(itens.win, ft_expose, &itens);
	mlx_loop(itens.mlx);
}
