/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttfe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroignan <rroignan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 19:04:19 by rroignan          #+#    #+#             */
/*   Updated: 2015/03/01 20:35:14 by rroignan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ttfe.h"
#define ESCAPE 27

static int	free_tab(int ***tab)
{
	int i;

	i = 3;
	while (i >= 0)
	{
		free ((*tab)[i]);
		(*tab)[i--] = NULL;
	}
	free(*tab);
	*tab = NULL;
	return (0);
}

static int	print_tab(t_env *env)
{
	env->width = getmaxx(stdscr);
	env->height = getmaxy(stdscr);
	if (env->width <= 40 || env->height <= 9)
	{
		endwin();
		ft_putstr("Window too small");
		return (0);
	}
	clear();
	ft_pitch(env->width, env->height);
	ft_display(env->width, env->height, env->tab);
	refresh();
	return (1);
}

static void	endscreen(t_env *env)
{
	if (env->win == 1)
	{
		clear();
		env->win++;
		printw("\t\t\t\t\t\t\t\t\t\t\t\tYou win !\nPress any key to continue");
	}
	else if (env->win == -1)
	{
		clear();
		env->win = 0;
		printw("You loose.");
	}
}

static int	ft_init(void)
{
	int	v;

	if ((v = WIN_VALUE) <= 4)
	{
		ft_putstr("Wrong value");
		return (0);
	}
	while (v != 1)
	{
		if (v % 2 != 0)
		{
			ft_putstr("Wrong value");
			return (0);
		}
		v = v / 2;
	}
	initscr();
	keypad(stdscr, TRUE);
	start_color();
	srand(time(NULL));
	noecho();
	cbreak();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	bkgdset(COLOR_PAIR(1));
	return (1);
}

int			main(void)
{
	int		key;
	int		res;
	t_env	env;

	res = 1;
	if (!(ft_init()))
		return (0);
	env.win = 0;
	env.tab = init_tab();
	key = 0;
	while (key != ESCAPE)
	{
		if (!(print_tab(&env)))
			return (free_tab(&env.tab));
		endscreen(&env);
		key = getch();
		res = resolve(&env, key);
		if (res == 1)
			if (new_al(&env))
				env.win = -1;
	}
	endwin();
	return (free_tab(&env.tab));
}
