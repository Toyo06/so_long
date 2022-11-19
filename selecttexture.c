/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selecttexture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 10:59:18 by sroggens          #+#    #+#             */
/*   Updated: 2022/09/22 00:22:13 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*selectwall(t_base *base, int x, int y)
{
	if (x == 0)
		return (base->mlx.wallnord);
	else if (x == base->map.column - 1)
		return (base->mlx.wallsud);
	else if (y == 0)
		return (base->mlx.wallouest);
	else if (y == base->map.len - 1)
		return (base->mlx.wallest);
	else
		return (base->mlx.wallelse);
}

void	*selectground(t_base *base)
{
	return (base->mlx.ground);
}

void	*selectplayer(t_base *base)
{
	return (base->mlx.player3);
}

void	*selectconso(t_base *base)
{
	if (base->conso.conso == 1)
		return (base->mlx.conso1);
	if (base->conso.conso == 2)
		return (base->mlx.conso2);
	if (base->conso.conso == 3)
		return (base->mlx.conso3);
	return (base->mlx.conso2);
}

void	*selectexit(t_base *base)
{
	if (base->map.totalconso == base->map.conso)
		return (base->mlx.exit2);
	else
		return (base->mlx.exit1);
}
