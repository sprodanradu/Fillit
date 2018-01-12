/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_erasespace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:05:02 by sprodan-          #+#    #+#             */
/*   Updated: 2018/01/09 21:18:22 by sprodan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void    ft_dimens(t_etris *s)
{
    int     i; // y la tine, lungime
    int     j; // x la tine, latime
    int     lungime;
    int     latime;
    int     count;

    i = 0;
    lungime = 0;
    latime = 0;
    count = 0;
    while (i < 4 && count != 4)
    {
        j = 0;
        while (j < 4 && count != 4)
        {
            if (!(s->piesa[i][j] == '.') && lungime < j)
                lungime = j;
            if (!(s->piesa[i][j] == '.') && latime < i)
                latime = i;
            if (!(s->piesa[i][j] == '.'))
                count++;
            j++;
        }
        i++;
    }
    s->lungime1 = lungime + 1;
    s->latime1 = latime + 1;
}

char    *ft_moveleft(char *str)
{
    int i;
    
    while (str[0] == '.' && str[5] == '.' && str[10] == '.' && str[15] == '.' )
    {
        i = 0;
        while (i < 19)
        {
            if (str[i] != '\n') 
            {
                if (str[i + 1] == '\n')
                    str[i] = str[i + 2];    
                else 
                    str[i] = str[i + 1];
            }
            i++;
        }
    }
    return (str);
}

char    *ft_movepiece(char *str)
{
    int     i;
    
    while (str[0] == '.' && str[1] == '.' && str[2] == '.' && str[3] == '.')
    {
        i = 0;
        while (i < 14)
        {
            str[i] = str[i + 5];
            i++;
        }
        i = 15;
        while (i < 19)
            str[i++] = '.';
    }
    str = ft_moveleft(str);
    return (str);
}