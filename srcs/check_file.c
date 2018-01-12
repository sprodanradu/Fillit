/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 19:44:53 by sprodan-          #+#    #+#             */
/*   Updated: 2018/01/12 19:49:38 by sprodan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(void)
{
	ft_putendl("error");
	exit(EXIT_FAILURE);
}

void	ft_vecini(char *str)
{
	int i;
	int vecini;

	i = 0;
	vecini = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (str[i - 1] == '#' && (i - 1) >= 0)
				vecini++;
			if (str[i + 1] == '#')
				vecini++;
			if (str[i - 5] == '#' && (i - 5) >= 0)
				vecini++;
			if (str[i + 5] == '#' && (i + 5) <= 19)
				vecini++;
		}
		i++;
	}
	if (vecini != 6 && vecini != 8)
		ft_error();
}

void	ft_rules(char *str, int j)
{
	char	*tmp;
	int		i;
	int		count;

	tmp = ft_memalloc(21);
	tmp = ft_strncpy(tmp, (const char*)str, 21);
	if (tmp[20] != '\n' && j == 0)
		ft_error();
	i = -1;
	count = 0;
	while (++i < 20)
	{
		if (i == 4 || i == 9 || i == 14 || i == 19)
		{
			if (tmp[i] != '\n')
				ft_error();
		}
		else if (tmp[i] != '#' && tmp[i] != '.')
			ft_error();
		if (tmp[i] == '#')
			count++;
	}
	if (count != 4)
		ft_error();
	ft_vecini(tmp);
}

void	ft_check(char *str, int *nb_pieces)
{
	int i;
	int j;
	int len;
	int pieces;

	j = 0;
	i = 0;
	len = ft_strlen(str) - 20;
	pieces = 1;
	if (len % 21 != 0)
		ft_error();
	while (pieces <= (len / 21))
	{
		ft_rules(str + i, j);
		i = i + 21;
		pieces++;
	}
	if (pieces == (len / 21 + 1))
	{
		j = 1;
		ft_rules(str + i, j);
	}
	*nb_pieces = pieces;
}

char	*ft_openread(char *argv)
{
	int		fd;
	int		buff;
	char	tmp[547];

	if ((fd = open(argv, O_RDONLY)) < 0)
		ft_error();
	ft_bzero(tmp, 547);
	if ((buff = read(fd, tmp, 547)) < 0)
		ft_error();
	if (ft_strlen(tmp) > 545)
		ft_error();
	close(fd);
	return (ft_strdup(tmp));
}
