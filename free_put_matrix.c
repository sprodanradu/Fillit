#include "fillit.h"

void	ft_putmatrix(char **matrix, int size)
{
	int y;
	int x;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (x < size)
		{
			ft_putchar(matrix[y][x]);
			x++;
		}
		y++;
	}
}

void	ft_freematrix(char **matrix, int size)
{
	int y;

	y = 0;
	while (y < size)
	{
		free(matrix[y]);
		y++;
	}
}