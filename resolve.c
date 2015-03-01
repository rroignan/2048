/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroignan <rroignan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 19:05:49 by rroignan          #+#    #+#             */
/*   Updated: 2015/03/01 19:05:53 by rroignan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ttfe.h"

static int	up(int ***tab)
{
	int i;
	int j;
	int res;

	res = vertical_fus1(tab, -1);
	j = -1;
	while (++j < 4)
	{
		i = -1;
		while (++i < 3)
			if ((*tab)[i][j] == 0 && (*tab)[i + 1][j])
			{
				(*tab)[i][j] = (*tab)[i + 1][j];
				(*tab)[i + 1][j] = 0;
				i = -1;
				res++;
			}
	}
	return (res);
}

static int	down(int ***tab)
{
	int i;
	int j;
	int res;

	res = vertical_fus2(tab, -1);
	j = -1;
	while (++j < 4)
	{
		i = 4;
		while (--i > 0)
			if ((*tab)[i][j] == 0 && (*tab)[i - 1][j])
			{
				(*tab)[i][j] = (*tab)[i - 1][j];
				(*tab)[i - 1][j] = 0;
				i = 4;
				res++;
			}
	}
	return (res);
}

static int	left(int ***tab)
{
	int i;
	int j;
	int res;

	res = horizontal_fus1(tab, -1);
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 3)
			if ((*tab)[i][j] == 0 && (*tab)[i][j + 1])
			{
				(*tab)[i][j] = (*tab)[i][j + 1];
				(*tab)[i][j + 1] = 0;
				j = -1;
				res++;
			}
	}
	return (res);
}

static int	right(int ***tab)
{
	int i;
	int j;
	int res;

	res = horizontal_fus2(tab, -1);
	i = -1;
	while (++i < 4)
	{
		j = 4;
		while (--j > 0)
			if ((*tab)[i][j] == 0 && (*tab)[i][j - 1])
			{
				(*tab)[i][j] = (*tab)[i][j - 1];
				(*tab)[i][j - 1] = 0;
				j = 4;
				res++;
			}
	}
	return (res);
}

int			resolve(t_env *env, int key)
{
	int i;
	int j;
	int res;

	if (key == KEY_UP)
		res = up(&env->tab);
	if (key == KEY_DOWN)
		res = down(&env->tab);
	if (key == KEY_LEFT)
		res = left(&env->tab);
	if (key == KEY_RIGHT)
		res = right(&env->tab);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
			if (env->tab[i][j++] == WIN_VALUE)
				env->win++;
		i++;
	}
	if (res == 0)
		return (0);
	return (1);
}
