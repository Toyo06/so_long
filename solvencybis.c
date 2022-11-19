/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvencybis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 06:56:18 by sroggens          #+#    #+#             */
/*   Updated: 2022/09/10 14:53:24 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	transfopart1(t_base *base, int i, int j)
{
	if (base->map.map[i][j + 1] == '0')
	{
		base->map.map[i][j + 1] = 'Y';
		transforming(base, i, j + 1);
	}
	if (base->map.map[i][j + 1] == 'C')
	{
		base->map.map[i][j + 1] = 'c';
		transforming(base, i, j + 1);
	}
	if (base->map.map[i][j + 1] == 'E')
		base->map.countexitcheck = 1;
}

void	transfopart2(t_base *base, int i, int j)
{
	if (base->map.map[i + 1][j] == '0')
	{
		base->map.map[i + 1][j] = 'Y';
		transforming(base, i + 1, j);
	}
	if (base->map.map[i + 1][j] == 'C')
	{
		base->map.map[i + 1][j] = 'c';
		transforming(base, i + 1, j);
	}
	if (base->map.map[i + 1][j] == 'E')
		base->map.countexitcheck = 1;
}

void	transfopart3(t_base *base, int i, int j)
{
	if (base->map.map[i][j - 1] == '0')
	{
		base->map.map[i][j - 1] = 'Y';
		transforming(base, i, j - 1);
	}
	if (base->map.map[i][j - 1] == 'C')
	{
		base->map.map[i][j - 1] = 'c';
		transforming(base, i, j - 1);
	}
	if (base->map.map[i][j - 1] == 'E')
		base->map.countexitcheck = 1;
}

void	transfopart4(t_base *base, int i, int j)
{
	if (base->map.map[i - 1][j] == '0')
	{
		base->map.map[i - 1][j] = 'Y';
		transforming(base, i -1, j);
	}
	if (base->map.map[i - 1][j] == 'C')
	{
		base->map.map[i - 1][j] = 'c';
		transforming(base, i - 1, j);
	}
	if (base->map.map[i - 1][j] == 'E')
		base->map.countexitcheck = 1;
}
