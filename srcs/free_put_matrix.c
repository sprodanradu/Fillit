/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_put_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 17:46:57 by sprodan-          #+#    #+#             */
/*   Updated: 2018/01/15 17:48:33 by sprodan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_putmatrix(char **matrice, int latura)
{
	int y;
	int x;

	y = 0;
	while (y < latura)
	{
		x = 0;
		while (x < latura)
		{
			ft_putchar(matrice[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}

void	ft_freematrix(char **matrice, int latura)
{
	int y;

	y = 0;
	while (y < latura)
	{
		free(matrice[y]);
		y++;
	}
}
