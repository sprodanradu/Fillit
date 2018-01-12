
#include "fillit.h"

void	ft_error(char *str)
{
	puts(str);
	exit(0);
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
		ft_error("numar de vecini diferit de 6 sau 8 -> piesa nevalida");
}

void	ft_rules(char *str, int j)
{	
	char	*tmp;
	int		i;
	int		count;

	tmp = ft_memalloc(21);
	tmp = ft_strncpy(tmp,(const char*)str,21);
	if (tmp[20] != '\n' && j == 0) 
		ft_error("nu am newline dupa block");
	i = 0;
	count = 0;
	while (i < 20)
	{
		if (i == 4 || i == 9 || i == 14 || i == 19) 
		{	
			if (tmp[i] != '\n')
				ft_error("nu am newline pe pozitie in block");
		}
		else if (tmp[i] != '#' && tmp[i] != '.')  
			ft_error("alteva pe langa # si .");
		if (tmp[i] == '#')
			count++;
		i++;
	}
	if (count != 4)
		ft_error("mai mult de 4 #-uri");
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
		ft_error("modulo de len/21 nu da 0 -> prea multe caractere");
	while (pieces <= (len / 21))
	{	
		ft_rules(str + i,j);
		i = i + 21;
		pieces++;
	}
	if (pieces == (len / 21 + 1))
	{
		j = 1;
		ft_rules(str + i, j);
	}
	*nb_pieces = pieces;
	printf("pieces = %d\n", pieces);
}

char	*ft_openread(char *argv)
{
	int		fd;
	int 	buff;
	char	tmp[547];
	
	if ((fd = open(argv, O_RDONLY)) < 0) 
		ft_error("eroare de open"); 
	ft_bzero(tmp, 547);
	if ((buff = read(fd, tmp, 547)) < 0)
		ft_error("eroare de read");	
	if (ft_strlen(tmp) > 545)  // error?? ??? ????
		ft_error("mai mult de 545 de caractere // > 26 piese");
	close(fd);
	return (ft_strdup(tmp));
}
