/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypad.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:57:45 by sroggens          #+#    #+#             */
/*   Updated: 2022/09/22 06:01:54 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	touchkey(int key, void *params)
{
	if (key == 53)
		exit(0);
	if (key == 126 || key == 13)
		mouvebonusupanddown(params, -1);
	if (key == 125 || key == 1)
		mouvebonusupanddown(params, 1);
	if (key == 123 || key == 0)
		mouvebonusleftandright(params, -1);
	if (key == 124 || key == 2)
		mouvebonusleftandright(params, 1);
	return (0);
}

int	closebycross(int key, int x, int y, void *params)
{
	(void)y;
	(void)x;
	(void)key;
	(void)params;
	exit(0);
	return (0);
}

void	mouvebonusupanddown(t_base *base, int nb)
{
	if (base->map.totalmonster > 0)
		allmonstermove(base);
	upanddown_mouvement(base, nb);
}

void	mouvebonusleftandright(t_base *base, int nb)
{
	if (base->map.totalmonster > 0)
		allmonstermove(base);
	leftright_mouvement(base, nb);
}
