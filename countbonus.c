/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 13:41:57 by sroggens          #+#    #+#             */
/*   Updated: 2022/09/21 20:19:27 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	countline(char *map, int search)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		if (map[i] == search)
			count++;
		i++;
	}
	return (count);
}

void	countobjects(t_base *base)
{
	int	i;

	i = 0;
	base->map.totalconso = 0;
	while (base->map.map[i])
	{
		base->map.totalconso += countline(base->map.map[i], 67);
		i++;
	}
	if (base->map.totalconso == 0)
	{
		ft_printf("No objects on the map");
		exit(0);
	}
}

void	countexit(char **map)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		count += countline(map[i], 67);
		i++;
	}
	if (count == 0)
	{
		ft_printf("No exit on the map");
		exit(0);
	}
}

void	countplayertotal(char **map)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		count += countline(map[i], 80);
		if (count > 1)
		{
			ft_printf("Too many players on the map");
			exit(0);
		}
		i++;
	}
	if (count < 1)
	{
		ft_printf("No player on the map");
		exit(0);
	}
}

void	countmonster(t_base *base)
{
	int	i;

	base->map.totalmonster = 0;
	i = 0;
	while (base->map.map[i])
	{
		base->map.totalmonster += countline(base->map.map[i], 77);
		i++;
	}
}
