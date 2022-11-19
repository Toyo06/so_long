/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 15:01:14 by sroggens          #+#    #+#             */
/*   Updated: 2022/09/22 06:45:42 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	refreshmap(t_base *base)
{
	static long int	i;

	i++;
	if (i == 10)
	{
		animeconso(base);
		i = 0;
	}
	usleep(300);
	selectplayer(base);
	printtheimage(base);
	base->map.walkprint = ft_itoa(base->map.walk);
	mlx_string_put(base->mlx.mlx, base->mlx.window, 50, 10, 0x77b5fe,
		base->map.walkprint);
	return (0);
}

int	animeconso(t_base *base)
{
	base->conso.conso++;
	if (base->conso.conso == 4)
		base->conso.conso = 1;
	return (0);
}

void	loop(t_base *base)
{
	mlx_loop_hook(base->mlx.mlx, refreshmap, base);
}	
