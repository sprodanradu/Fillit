/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_vect_of_struct.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 19:50:11 by sprodan-          #+#    #+#             */
/*   Updated: 2018/01/15 17:21:49 by sprodan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		fuck_the_normes(t_etris *tetris, int piece_nb, int y)
{
	int x;

	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (tetris->piesa[y][x] == '#')
				tetris->piesa[y][x] = 65 + piece_nb;
			x++;
		}
		y++;
	}
	ft_dimens(tetris);
	tetris->nb = piece_nb;
}

t_etris		*ft_create_struct(int piece_nb, char *str, int j)
{
	int		x;
	int		y;
	t_etris	*tetris;

	y = 0;
	x = 0;
	tetris = (t_etris*)malloc(sizeof(t_etris));
	while (y < 4)
	{
		if (str[j] == '#' || str[j] == '.')
		{
			tetris->piesa[y][x] = str[j];
			x++;
			j++;
		}
		if ((x == 4) || y > 2)
		{
			x = 0;
			y++;
			j++;
		}
	}
	fuck_the_normes(tetris, piece_nb, 0);
	free(str);
	return (tetris);
}

t_etris		*take_20(char *str, int x, int piece_nb)
{
	int		i;
	char	*arr;

	arr = (char *)malloc(sizeof(char) * 20);
	i = 0;
	while (i < 20)
	{
		arr[i] = str[i + x];
		i++;
	}
	ft_movepiece(arr);
	return (ft_create_struct(piece_nb, arr, 0));
}

t_etris		**ft_vector_struct(int nr_piese, char *str)
{
	int		piece_nb;
	t_etris	**vector;
	char	*string;
	int		x;

	x = 0;
	piece_nb = 0;
	string = str;
	vector = (t_etris**)malloc(sizeof(t_etris) * (nr_piese + 1));
	while (piece_nb < nr_piese)
	{
		vector[piece_nb] = take_20(string, x, piece_nb);
		piece_nb++;
		x += 21;
	}
	vector[piece_nb] = NULL;
	return (vector);
}
