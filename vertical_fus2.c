/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_fus2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schane <schane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 17:21:53 by schane            #+#    #+#             */
/*   Updated: 2015/03/01 18:26:55 by schane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ttfe.h"

int vertical_fus2(int ***tab, int j)
{
	int i;
	int k;
	int mv;

	mv = 0;
	while (++j < 4)
	{
		i = 4;
		while (--i > 0)
		{
			k = i;
			while (--k >= 0)
				if ((*tab)[i][j] == (*tab)[k][j] && (*tab)[k][j] != 0)
				{
					(*tab)[i][j] += (*tab)[i][j];
					(*tab)[k][j] = 0;
					mv++;
					break ;
				}
				else if ((*tab)[i][j] != 0 && (*tab)[k][j] != 0)
					break ;
		}
	}
	return (mv);
}
