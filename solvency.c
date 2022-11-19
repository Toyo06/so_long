/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvency.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 20:23:00 by sroggens          #+#    #+#             */
/*   Updated: 2022/09/12 14:08:07 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	transforming(t_base *base, int i, int j)
{
	transfopart1(base, i, j);
	transfopart2(base, i, j);
	transfopart3(base, i, j);
	transfopart4(base, i, j);
}

void	checking(t_base *base)
{
	int	i;

	i = 0;
	base->map.countobjectcheck = 0;
	if (base->map.countexitcheck != 1)
	{
		ft_printf("Cannot finish the map");
		exit(0);
	}
	while (base->map.map[i])
	{
		base->map.countobjectcheck += countforcheckobjects(base->map.map[i]);
		i++;
	}
	if (base->map.countobjectcheck != base->map.totalconso)
	{
		ft_printf("Cannot finish the map");
		exit(0);
	}
}

int	countforcheckobjects(char *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		if (map[i] == 'c')
			j++;
		i++;
	}
	return (j);
}

char	*getbackmap(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == 'Y')
			map[i] = '0';
		else if (map[i] == 'c')
			map[i] = 'C';
		i++;
	}
	return (map);
}

void	normalmap(t_base *base)
{
	int	i;

	i = 0;
	while (base->map.map[i])
	{
		base->map.map[i] = getbackmap(base->map.map[i]);
		i++;
	}
}
