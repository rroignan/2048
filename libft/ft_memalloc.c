/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroignan <rroignan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 10:09:49 by rroignan          #+#    #+#             */
/*   Updated: 2015/03/01 19:25:45 by rroignan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	if ((int)size > 0)
	{
		if ((str = (unsigned char *)malloc(sizeof(size))) == NULL)
			return (NULL);
		while (i < size)
		{
			str[i] = 0;
			i++;
		}
		return ((void *)str);
	}
	return (NULL);
}
