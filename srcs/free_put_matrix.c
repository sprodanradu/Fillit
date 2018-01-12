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