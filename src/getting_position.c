/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getting_position.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinacio- <jinacio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 20:03:11 by jinacio-          #+#    #+#             */
/*   Updated: 2021/12/13 23:07:44 by jinacio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	error_function_map(t_general *itens, char tag)
{
	if (tag == 'F')
	{
		printf("Error\nPlease check the File Descriptor\n");
		mlx_destroy_display(itens->mlx);
		close(itens->n1);
		exit (1);
	}
	if (tag == 'G')
	{
		printf("Error\nPlease check the function Open (gnl)\n");
		mlx_destroy_display(itens->mlx);
		close(itens->n1);
		exit (1);
	}
}

void	*openwindow(t_general *itens)
{
	char	*gnl;

	itens->n1 = open(itens->local, O_RDONLY);
	if (itens->n1 < 0)
		error_function_map(itens, 'F');
	gnl = get_next_line(itens->n1);
	if (gnl == NULL)
		error_function_map(itens, 'G');
	while (gnl)
	{
		itens->county = itens->county + 1;
		free(gnl);
		gnl = get_next_line(itens->n1);
	}
	itens->win = mlx_new_window(itens->mlx, itens->countx * 50, itens->county
			* 50, "teste");
	free(gnl);
	close(itens->n1);
	return (0);
}

void	count_x(t_general *itens)
{
	char	*gnl;

	itens->n1 = open(itens->local, O_RDONLY);
	if (itens->n1 < 0)
		error_function_map(itens, 'F');
	gnl = get_next_line(itens->n1);
	if (gnl == NULL)
		error_function_map(itens, 'G');
	while (gnl)
	{
		itens->countx = ft_strlen(gnl);
		free(gnl);
		gnl = get_next_line(itens->n1);
	}
	close(itens->n1);
}
