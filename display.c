/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroignan <rroignan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 12:00:19 by rroignan          #+#    #+#             */
/*   Updated: 2015/03/01 16:48:20 by schane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ttfe.h"

void	ft_display(int h, int v, int **tab)
{
	int i;
	int	j;
	int	b;
	int	k;
	int	l;

	j = v / 2 - v / 4 - (v / 4) / 2;
	b = 0;
	k = 0;
	move(0, 0);
	while (j <= v && b != 4)
	{
		i = h / 2 - h / 4 - (h / 4) / 2;
		move(j, i);
		l = 0;
		while (i <= h)
		{
			move(j, i);
			printw("%d", tab[k][l++]);
			i = i + h / 4;
		}
		j = j + v / 4;
		b++;
		k++;
	}
}
