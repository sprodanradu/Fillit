#include "fillit.h"

t_etris		*ft_create_struct(int piece_nb, char *str)
{
	int			j;
	int 		x;
	int			y;
	t_etris		*tetris;
	
	y = 0;	
	x = 0;
	j = 0;
	if (!(tetris = (t_etris*)malloc(sizeof(t_etris))))
		return (NULL);
	while (y < 4)
	{
		if (str[j] == '#' || str[j] == '.')
		{
			if (str[j] == '#')
				tetris->piesa[y][x] = 65 + piece_nb;
			else
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
	ft_dimens(tetris);
	free(str);
	return(tetris);
}

t_etris     *take_20(char *str, int x, int piece_nb)
{
    int     i;
    char    *arr;

    if(!(arr = (char*)malloc(sizeof(char) * 20)))
        return (NULL);
    i = 0;
    while (i < 20)
    {
        arr[i] = str[i + x];
        i++;
    }
    ft_movepiece(arr);  // de aici il bagi direct in struct si dupa ii dai free din main probabil 
    return(ft_create_struct(piece_nb, arr)); // Aici in loc de return array o faci sa returneze struct si scrii array-ul in struct direct, dupa vectorul ** o sa se creeze cu take ca parametru
}

t_etris		**ft_vector_struct(int nr_piese, char *str)
{
	int 		piece_nb;
	t_etris		**vector;
	char		*string;
	int			x;

	x = 0;
	piece_nb = 0;
	string = str;
	if(!(vector = (t_etris**)malloc(sizeof(t_etris) * (nr_piese + 1))))
		return (NULL);
	while (piece_nb < nr_piese)
	{
		vector[piece_nb] = take_20(string,x,piece_nb);
		piece_nb++;
		x+=21;
	}
	vector[piece] = NULL;
	return(vector);
}