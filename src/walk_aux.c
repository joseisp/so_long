/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinacio- <jinacio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 04:55:15 by jinacio-          #+#    #+#             */
/*   Updated: 2021/12/13 05:56:54 by jinacio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	walktoright(t_general *itens)
{
	mlx_destroy_image(itens->mlx, itens->link);
	itens->link = mlx_xpm_file_to_image(itens->mlx, "img/right.xpm",
			&itens->nl1, &itens->nl2);
	sweepd(itens);
}

void	walktoleft(t_general *itens)
{
	mlx_destroy_image(itens->mlx, itens->link);
	itens->link = mlx_xpm_file_to_image(itens->mlx, "img/left.xpm",
			&itens->nl1, &itens->nl2);
	sweepa(itens);
}

void	walktodown(t_general *itens)
{
	mlx_destroy_image(itens->mlx, itens->link);
	itens->link = mlx_xpm_file_to_image(itens->mlx, "img/down.xpm",
			&itens->nl1, &itens->nl2);
	sweeps(itens);
}

void	walktoup(t_general *itens)
{
	mlx_destroy_image(itens->mlx, itens->link);
	itens->link = mlx_xpm_file_to_image(itens->mlx, "img/up.xpm",
			&itens->nl1, &itens->nl2);
	sweepw(itens);
}
