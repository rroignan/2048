/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_fus1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schane <schane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 17:22:28 by schane            #+#    #+#             */
/*   Updated: 2015/03/01 18:00:17 by schane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ttfe.h"

int horizontal_fus1(int ***tab, int i)
{
	int j;
	int k;
	int mv;

	mv = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 3)
		{
			k = j;
			while (++k < 4)
				if ((*tab)[i][j] == (*tab)[i][k] && (*tab)[i][k] != 0)
				{
					(*tab)[i][j] += (*tab)[i][j];
					(*tab)[i][k] = 0;
					mv++;
					break ;
				}
				else if ((*tab)[i][j] != 0 && (*tab)[i][k] != 0)
					break ;
		}
	}
	return (mv);
}
