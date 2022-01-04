/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinacio- <jinacio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 21:46:39 by jinacio-          #+#    #+#             */
/*   Updated: 2021/12/14 02:19:41 by jinacio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include "./../mlx/mlx.h"
# include "./../libf/libf.h"

typedef struct s_general
{
	void	*mlx;
	void	*floor;
	void	*wall;
	void	*link;
	void	*win;
	void	*castle;
	void	*colect;
	char	*test;
	char	**maps;
	char	*local;
	int		n1;
	int		countx;
	int		county;
	int		nl1;
	int		nl2;
	int		rupees;
	int		colection;
	int		castle_exit;
	int		character;
	int		moviment;
	int		i;
	int		j;
}t_general;

// Get_next_lin

char	*get_next_line(int fd);
size_t	ft_strlena(const char *c);
char	*ft_strjoina(char *s1, char *s2);
char	*ft_substra(char const *s, unsigned int start, size_t len);
void	ft_bzero(void *s, size_t n);
char	*ft_strchr(const char *s, int c);

// main function

int		key_insert(int key, t_general *itens);
void	walkright(t_general *itens, char c);
void	render(t_general *itens);
void	getmap(t_general *itens);

//iniatilize map

void	*openwindow(t_general *itens);
void	load_sprites(t_general *itens);
void	count_x(t_general *itens);

// colect

void	check_colect(t_general *itens);
void	colect_and_exit_s(t_general *itens, char c, int n1, int n2);
void	colect_and_exit_w(t_general *itens, char c, int n1, int n2);
void	colect_and_exit_a(t_general *itens, char c, int n1, int n2);
void	colect_and_exit_d(t_general *itens, char c, int n1, int n2);

// check map

void	check_map(t_general *itens);
void	check_rectangle(t_general *itens);
void	check_wall(t_general *itens);
void	check_elements(t_general *itens);
int		define(t_general *itens);

// validate

int		closee(t_general *itens);
int		clear_memory(t_general *itens);
void	free_matrix(t_general *itens);
int		val(t_general *itens, char c);
void	free_matrix(t_general *game);
void	check_name(t_general *itens);

// Moviment

void	walktoright(t_general *itens);
void	walktoleft(t_general *itens);
void	walktodown(t_general *itens);
void	walktoup(t_general *itens);

// Moviment direction

void	sweepd(t_general *itens);
void	sweepa(t_general *itens);
void	sweeps(t_general *itens);
void	sweepw(t_general *itens);

#endif
