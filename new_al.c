/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_al.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroignan <rroignan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 19:05:31 by rroignan          #+#    #+#             */
/*   Updated: 2015/03/01 19:05:35 by rroignan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ttfe.h"

static int	lose(t_env *env)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (i + 1 < 4 && env->tab[i][j] == env->tab[i + 1][j])
				return (0);
			if (j + 1 < 4 && env->tab[i][j] == env->tab[i][j + 1])
				return (0);
			if (env->tab[i][j] == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int			new_al(t_env *env)
{
	int x;
	int y;
	int value;

	x = 0;
	y = 0;
	value = 0;
	x = rand() % 4;
	y = rand() % 4;
	while (env->tab[x][y] != 0)
	{
		x = rand() % 4;
		y = rand() % 4;
	}
	value = RAND_TF();
	env->tab[x][y] = value;
	return (lose(env));
}
