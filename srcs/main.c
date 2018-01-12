#include "fillit.h"

void	fill_patrat(char **patrat, int latura)
{
	int y;
	int x;

	y = 0;
	while (y < latura)
	{
		x = 0;
		while (x < latura)
		{
			patrat[y][x] = '.';
			x++;
		}
		y++;
	}
}

char	**ft_patratalloc(int latura)
{
	int		i;
	char	**lat_y;

	i = 0;
	lat_y = (char **)malloc(sizeof(char**) * latura);
	while (i < latura)
	{
		lat_y[i] = (char *)malloc(sizeof(char*) * latura);
		i++;
	}
	fill_patrat(lat_y, latura);
	return (lat_y);
}

int		main(int argc, char **argv)
{
	char	*read;
	int 	nb_pieces;
	int 	i;
	t_etris	**finalvector; 
	int 	latura_minim;
	char	**patrat;

	i = 0;     
	if (argc != 2) 
		ft_putstr("usage: fillit input_file\n"); // USAGE 
	read = ft_openread(argv[1]);
	ft_check(read, &nb_pieces);
	
	latura_minim = ft_sqrt((4 * nb_pieces));
	finalvector = ft_vector_struct(nb_pieces, read);
	free(read);
	
	patrat=ft_patratalloc(latura_minim);
	while(ft_backtrack(finalvector, patrat, latura_minim, i) == 0)
	{
		ft_freematrix(patrat, latura_minim);
		latura_minim++;
		patrat = ft_patratalloc(latura_minim);
	}
	ft_putmatrix(patrat,latura_minim);
	return (0);
}