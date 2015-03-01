/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttfe.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroignan <rroignan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 11:07:20 by rroignan          #+#    #+#             */
/*   Updated: 2015/03/01 21:25:24 by rroignan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TTFE_H
# define TTFE_H
# define RAND_TF() (rand() % 4) ? 2 : 4

# include <curses.h>
# include <stdlib.h>
# include <time.h>
# include "libft.h"

typedef struct	s_env
{
	int	height;
	int	width;
	int	win;
	int	**tab;
}				t_env;

enum			e_const
{
	WIN_VALUE = 2048
}				;

int				vertical_fus1(int ***tab, int j);
int				vertical_fus2(int ***tab, int j);
int				horizontal_fus1(int ***tab, int i);
int				horizontal_fus2(int ***tab, int i);
int				new_al(t_env *env);
int				resolve(t_env *env, int key);
int				**init_tab(void);
void			ft_pitch(int h, int v);
void			ft_display(int h, int v, int **tab);

#endif
