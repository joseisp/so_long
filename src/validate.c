/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinacio- <jinacio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:45:36 by jinacio-          #+#    #+#             */
/*   Updated: 2021/12/13 23:45:19 by jinacio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	val(t_general *itens, char c)
{
	if (c == '1')
		return (0);
	else if (c == 'E')
	{
		if (itens->rupees == 0)
		{
			itens->moviment++;
			printf("Moviments: %d\n", itens->moviment);
			closee(itens);
		}
		else
			return (0);
	}
	else
	{
		itens->moviment = itens->moviment + 1;
		return (1);
	}
	return (0);
}
