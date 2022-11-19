/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:22:02 by sroggens          #+#    #+#             */
/*   Updated: 2022/09/14 15:59:20 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mapheart(char *map, int len)
{
	if (map[0] != 49 || map[len - 1] != 49)
	{
		ft_printf("Map not close");
		exit(0);
	}
}

void	mapside(t_base *base)
{
	int	i;

	i = 1;
	if (countline(base->map.map[0], 49) != base->map.len || countline
		(base->map.map[base->map.column - 1], 49) != base->map.len)
	{
		ft_printf("Map not close");
		exit(0);
	}
	while (i < base->map.column - 1)
	{
		mapheart(base->map.map[i], base->map.len);
		i++;
	}
}

void	formatmap(t_base *base)
{
	int	i;

	i = 0;
	while (base->map.map[i])
	{
		charactchecking(base->map.fulline);
		if (ft_strlen(base->map.map[i]) != base->map.len)
		{
			ft_printf("Erreur format map");
			exit(0);
		}
		i++;
	}
}

void	columncount(t_base *base)
{
	base->map.column = 0;
	while (base->map.map[base->map.column])
		base->map.column++;
}
