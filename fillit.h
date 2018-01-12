#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <stdio.h>
# include "libft.h"


typedef	struct    	s_size
{
		char	piesa[4][4];
		int		lungime1;
		int 	latime1;
		int		nb;
		int		lat;
}					t_etris;

void    ft_dimens(t_etris *s);
char	*ft_movepiece(char *str);
void	ft_error(char *str);
int		ft_backtrack(t_etris **matrice, char **patrat, int latura, int i);
void	ft_check(char *str, int *nb_pieces);
char	*ft_openread(char *argv);

t_etris **ft_vector_struct(int nr_piese, char *str);

void	ft_putmatrix(char **matrix, int size);
void	ft_freematrix(char **matrix, int size);

#endif
