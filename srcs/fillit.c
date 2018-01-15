/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 17:47:52 by sprodan-          #+#    #+#             */
/*   Updated: 2018/01/15 17:47:54 by sprodan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		fuck_the_normes_ftspot(t_etris *structura, int posini_x, int posini_y)
{
	if ((structura->lat - posini_x) < structura->lungime1)
		return (0);
	if ((structura->lat - posini_y) < structura->latime1)
		return (0);
	return (1);
}

int		fuck_the_normes_ftspot2(t_etris *structura,
		int posini_x, int posini_y, char **patrat)
{
	int ini;
	int	y;
	int	x;

	ini = posini_x;
	y = 0;
	while (y < structura->latime1)
	{
		x = 0;
		posini_x = ini;
		while (x < structura->lungime1)
		{
			if (patrat[posini_y][posini_x] == '.'
					|| structura->piesa[y][x] == '.')
			{
				x++;
				posini_x++;
			}
			else
				return (0);
		}
		y++;
		posini_y++;
	}
	return (1);
}

void	ft_scrie(char **patrat, int y, int x, t_etris *tetris)
{
	int loc_x;
	int loc_y;
	int ini;

	ini = x;
	loc_y = 0;
	while (loc_y < tetris->latime1)
	{
		x = ini;
		loc_x = 0;
		while (loc_x < tetris->lungime1)
		{
			if (!(tetris->piesa[loc_y][loc_x] == '.'))
				patrat[y][x] = tetris->piesa[loc_y][loc_x];
			x++;
			loc_x++;
		}
		loc_y++;
		y++;
	}
}

int		ft_verifica_spot(char **patrat, int posini_y,
		int posini_x, t_etris *structura)
{
	if (fuck_the_normes_ftspot(structura, posini_x, posini_y) == 0)
		return (0);
	if (fuck_the_normes_ftspot2(structura, posini_x,
		posini_y, patrat) == 0)
		return (0);
	return (1);
}

int		ft_backtrack(t_etris **matrice, char **patrat, int latura, int i)
{
	int	x;
	int	y;

	if (matrice[i] == NULL)
		return (1);
	matrice[i]->lat = latura;
	y = 0;
	while (y < latura)
	{
		x = 0;
		while (x < latura)
		{
			if (ft_verifica_spot(patrat, y, x, matrice[i]))
			{
				ft_scrie(patrat, y, x, matrice[i]);
				if (ft_backtrack(matrice, patrat, latura, i + 1))
					return (1);
				else
					remove_tetris(matrice[i]->nb + 65, patrat, latura);
			}
			x++;
		}
		y++;
	}
	return (0);
}
