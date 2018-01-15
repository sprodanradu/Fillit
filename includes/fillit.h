/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodan- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 18:16:05 by sprodan-          #+#    #+#             */
/*   Updated: 2018/01/15 18:16:57 by sprodan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef	struct		s_size
{
	char			piesa[4][4];
	int				lungime1;
	int				latime1;
	int				nb;
	int				lat;
}					t_etris;

void				ft_error(void);
void				ft_vecini(char *str);
void				ft_rules(char *str, int j);
void				ft_check(char *str, int *nb_pieces);
char				*ft_openread(char *argv);
void				fuck_the_normes(t_etris *tetris, int piece_nb, int y);
t_etris				*ft_create_struct(int piece_nb, char *str, int j);
t_etris				*take_20(char *str, int x, int piece_nb);
t_etris				**ft_vector_struct(int nr_piese, char *str);
int					fuck_the_normes_ftspot(t_etris *structura,
	int posini_x, int posini_y);
int					fuck_the_normes_ftspot2(t_etris *structura,
	int posini_x, int posini_y, char **patrat);
void				ft_scrie(char **patrat, int y, int x, t_etris *tetris);
int					ft_verifica_spot(char **patrat, int posini_y,
	int posini_x, t_etris *structura);
int					ft_backtrack(t_etris **matrice,
	char **patrat, int latura, int i);
void				ft_putmatrix(char **matrice, int latura);
void				ft_freematrix(char **matrice, int latura);
void				ft_dimens(t_etris *s);
char				*ft_moveleft(char *str);
char				*ft_movepiece(char *str);
void				remove_tetris(char litera, char **patrat, int latura);
void				fill_patrat(char **patrat, int latura);
char				**ft_patratalloc(int latura);

#endif
