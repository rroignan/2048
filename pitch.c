/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pitch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroignan <rroignan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 10:24:01 by rroignan          #+#    #+#             */
/*   Updated: 2015/03/01 18:27:17 by schane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ttfe.h"

static void	ft_horizontal(int h, int v)
{
	move(v / 2 - v / 4, 1);
	whline(stdscr, ' ', h);
	move(v / 2, 1);
	whline(stdscr, ' ', h);
	move(v / 2 + v / 4, 1);
	whline(stdscr, ' ', h);
}

static void	ft_vertical(int h, int v)
{
	move(1, h / 2 - h / 4);
	wvline(stdscr, ' ', v);
	move(1, h / 2);
	wvline(stdscr, ' ', v);
	move(1, h / 2 + h / 4);
	wvline(stdscr, ' ', v);
}

static void	ft_frame(int h, int v)
{
	wvline(stdscr, ' ', v);
	whline(stdscr, ' ', h);
	move(1, h - 1);
	wvline(stdscr, ' ', v);
	move(v - 1, 1);
	whline(stdscr, ' ', h);
}

void		ft_pitch(int h, int v)
{
	init_color(COLOR_MAGENTA, 430, 450, 400);
	init_pair(2, COLOR_WHITE, COLOR_BLUE);
	attron(COLOR_PAIR(2));
	ft_frame(h, v);
	ft_vertical(h, v);
	ft_horizontal(h, v);
	attroff(COLOR_PAIR(2));
}
