/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvementenemy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 01:12:01 by sroggens          #+#    #+#             */
/*   Updated: 2022/09/22 06:20:05 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moveenemy(t_base *base)
{
	searchmonster(base);
	if (base->map.map[base->map.mc]
		[base->map.ml + base->map.mv[base->map.mtmp]] == '1')
		base->map.mv[base->map.mtmp] *= -1;
	if ((base->map.map[base->map.mc][base->map.ml + 1] == '1'
		&& base->map.map[base->map.mc][base->map.ml - 1] == '1')
			|| (base->map.map[base->map.mc][base->map.ml + 1] == '1'
				&& base->map.map[base->map.mc][base->map.ml - 1] == 'C')
			|| (base->map.map[base->map.mc][base->map.ml + 1] == '1'
				&& base->map.map[base->map.mc][base->map.ml - 1] == 'E')
			|| (base->map.map[base->map.mc][base->map.ml + 1] ==
				'C' && base->map.map[base->map.mc][base->map.ml - 1] == '1')
			|| (base->map.map[base->map.mc][base->map.ml + 1] ==
				'E' && base->map.map[base->map.mc][base->map.ml - 1] == '1')
			|| (base->map.map[base->map.mc][base->map.ml + 1] ==
				'C' && base->map.map[base->map.mc][base->map.ml - 1] == 'E')
			|| (base->map.map[base->map.mc][base->map.ml + 1] ==
				'E' && base->map.map[base->map.mc][base->map.ml - 1] == 'C'))
		return ;
	kill(base);
	base->map.map[base->map.mc][base->map.ml] = '0';
	base->map.map[base->map.mc]
	[base->map.ml + base->map.mv[base->map.mtmp]] = 'M';
}

void	searchmonster(t_base *base)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 1;
	while (base->map.map[i][j])
	{
		if (base->map.map[i][j] == 'M' && base->map.mtmp == count)
			break ;
		else if (base->map.map[i][j] == 'M')
			count++;
		else if (base->map.map[i][j + 1] == '\0')
		{
			i++;
			j = 0;
		}
		j++;
	}
	base->map.mc = i;
	base->map.ml = j;
}

void	kill(t_base *base)
{
	if (base->map.map[base->map.mc]
		[base->map.ml + base->map.mv[base->map.mtmp]] == 'P')
	{
		ft_printf("You died");
		exit (0);
	}
}

void	allmonstermove(t_base *base)
{
	while (base->map.mtmp != base->map.totalmonster + 1)
	{
		moveenemy(base);
		base->map.mtmp++;
	}
	base->map.mtmp = 1;
}
