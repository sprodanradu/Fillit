#include "fillit.h"

char	**ft_matrixalloc(int size1, int size2)
{
	int		i;
	char	**lat_y;

	if (!(lat_y = (char**)malloc(sizeof(lat_y) * size1)))
		return (NULL);
	i = 0;
	while (i < size2)
	{
		if (!(lat_y[i] = (char*)malloc(sizeof(char) * size2)))
			return (NULL);
		i++;
	}
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
		ft_error("usage: fillit input_file\n"); // USAGE 
	read = ft_openread(argv[1]);
	ft_check(read,&nb_pieces);
	latura_minim = ft_sqrt((4 * nb_pieces));
	finalvector = ft_vector_struct(nb_pieces,read);
	free(read);
	patrat = ft_matrixalloc(latura_minim,latura_minim);
	while(!(ft_backtrack(finalvector,patrat,latura_minim,i)))
	{
		latura_minim++;
		ft_freematrix(patrat,latura_minim);
		patrat = ft_matrixalloc(latura_minim,latura_minim);
	}
		ft_putmatrix(patrat,latura_minim);
		ft_freematrix(patrat,latura_minim);
	return (0);
}