/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_fus2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schane <schane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 17:23:43 by schane            #+#    #+#             */
/*   Updated: 2015/03/01 18:04:46 by schane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ttfe.h"

int horizontal_fus2(int ***tab, int i)
{
	int j;
	int k;
	int mv;

	mv = 0;
	while (++i < 4)
	{
		j = 4;
		while (--j > 0)
		{
			k = j;
			while (--k >= 0)
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
