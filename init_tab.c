/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schane <schane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 17:31:24 by schane            #+#    #+#             */
/*   Updated: 2015/03/01 18:24:49 by schane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ttfe.h"

static void	set_z(int ***tab)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			(*tab)[i][j] = 0;
			j++;
		}
		i++;
	}
}

int			**init_tab(void)
{
	int x;
	int y;
	int x2;
	int y2;
	int **tab;

	x = 0;
	x2 = 0;
	tab = (int **)malloc(4 * sizeof(int*));
	while (x < 4)
		tab[x++] = (int *)malloc(4 * sizeof(int));
	set_z(&tab);
	x = x2;
	while (x == x2)
	{
		x = rand() % 4;
		x2 = rand() % 4;
	}
	y = rand() % 4;
	y2 = rand() % 4;
	tab[x][y] = RAND_TF();
	tab[x2][y2] = RAND_TF();
	return (tab);
}
