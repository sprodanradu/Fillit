/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 14:05:58 by sprodan-          #+#    #+#             */
/*   Updated: 2017/12/14 14:29:53 by sprodan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int			a[2];
	long long	n;

	a[0] = 0;
	a[1] = 1;
	n = 0;
	while ((str[a[0]] == 32) || (str[a[0]] >= 9 && str[a[0]] <= 13))
		a[0]++;
	if (str[a[0]] == '-' || str[a[0]] == '+')
		a[0]++;
	if (str[a[0] - 1] == '-')
		a[1] = -1;
	while (str[a[0]] >= '0' && str[a[0]] <= '9')
	{
		if (n > 922337203685477580)
			return (-1);
		if (n < -922337203685477580)
			return (0);
		n = (n * 10) + a[1] * (str[a[0]++] - 48);
		if (a[1] == 1 && n < 0)
			return (-1);
		if (a[1] == -1 && n > 0)
			return (0);
	}
	return ((int)n);
}
