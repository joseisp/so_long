/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinacio- <jinacio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:35:42 by jinacio-          #+#    #+#             */
/*   Updated: 2021/12/13 06:33:32 by jinacio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	load_var_hook(t_general *itens)
{
	itens->nl1 = 0;
	itens->nl2 = 0;
}

int	key_insert(int key, t_general *itens)
{
	load_var_hook(itens);
	if (key == 0xff1b)
		closee(itens);
	if (key == 'd')
	{
		walkright(itens, 'd');
		render(itens);
	}
	if (key == 'a')
	{
		walkright(itens, 'a');
		render(itens);
	}
	if (key == 's')
	{
		walkright(itens, 's');
		render(itens);
	}
	if (key == 'w')
	{
		walkright(itens, 'w');
		render(itens);
	}
	printf("Moviments: %d\n", itens->moviment);
	return (1);
}
