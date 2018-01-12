#include "fillit.h"

void	remove_tetris(char litera, char **patrat, int latura)
{
  int 	x;
  int 	y; 
  int	block_count;

  block_count = 0;
  y = 0;
  while(block_count < 4)
  {

  		x = 0;
  		while(x < latura)
  		{	
  			if (patrat[y][x] == litera)
  			{
  				patrat[y][x] = '.';
  				block_count++;
  			}
  			x++;
  		}
  		y++;
  }
}

void	ft_scrie(char **patrat, int y, int x, t_etris *tetris)
{
	int loc_x;
	int loc_y;
	int ini;

	ini = x;
	loc_y = 0;
	while (loc_y < tetris->latime1)
	{
		x = ini;
		loc_x = 0;
		while (loc_x < tetris->lungime1)
		{
			if (!(tetris->piesa[loc_y][loc_x] == '.'))
				patrat[y][x] = tetris->piesa[loc_y][loc_x];
			x++;
			loc_x++;
		}
		loc_y++;
		y++;
	}
}


int		ft_verifica_spot(char **patrat, int posini_y, int posini_x, t_etris *structura)
{
	int		x;
	int		y;
	int		ini;
	
	if ((structura->lat - posini_x) < structura->lungime1)
		return (0);
	if ((structura->lat - posini_y) < structura->latime1)
		return (0);
	ini = posini_x;
	y = 0;
	while (y < structura->latime1)
	{
		x = 0;
		posini_x = ini;
		while (x < structura->lungime1)
		{
			if (patrat[posini_y][posini_x] == '.' || structura->piesa[y][x] == '.')
				{
					x++;
					posini_x++;
				}
			else
				return(0);
		}
		y++;
		posini_y++;
	}
	return (1);
}

int	ft_backtrack(t_etris **matrice, char **patrat, int latura, int i)
{
	int 	x;
	int 	y;
	t_etris	*piesa1;

	if (matrice[i] == NULL)
		return (1);
	matrice[i]->lat = latura;
	piesa1 = matrice[i];
	y = 0;
	while (y < latura)
	{
		x = 0;
		while(x < latura)
		{
			if (ft_verifica_spot(patrat,y,x,piesa1))
			{
				ft_scrie(patrat,y,x,piesa1);
				if (ft_backtrack(matrice,patrat,latura,i + 1))
					return (1);
				else
					remove_tetris(piesa1->nb + 65,patrat,latura);
			}
			x++;
		}
		y++;
	}
	return (0);
}
