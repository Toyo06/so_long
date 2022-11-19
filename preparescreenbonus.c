/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparescreen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 12:13:21 by sroggens          #+#    #+#             */
/*   Updated: 2022/09/22 06:45:29 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	setscreen(t_base *base)
{
	int	i;

	i = 0;
	base->map.mv = malloc(sizeof(int) * base->map.totalmonster);
	while (i < base->map.totalmonster + 1)
	{
		base->map.mv[i] = 1;
		i++;
	}
	base->map.mv[i] = 0;
	base->posplayer.playergoingdown = 3;
	base->conso.conso = 1;
	base->map.mtmp = 1;
	base->mlx.window = mlx_new_window(base->mlx.mlx, base->mlx.totalheight,
			base->mlx.totallenght, "So_long");
	printtheimage(base);
	base->map.walkprint = ft_itoa(base->map.walk);
	mlx_string_put(base->mlx.mlx, base->mlx.window, 25, 10, 0x77b5fe,
		base->map.walkprint);
}

void	printtheimage(t_base *base)
{
	int	x;
	int	y;

	base->map.column = base->map.column ;
	base->map.len = base->map.len ;
	y = 0;
	x = 0;
	while ((x * y) - 1 != (base->map.len * base->map.column))
	{
		mlx_put_image_to_window(base->mlx.mlx,
			base->mlx.window, selecttiles(base, x, y), y * 32, x * 32);
		if (y != base->map.len)
			y++;
		else if (y == base->map.len)
		{
			y = 0;
			x++;
		}
		if (x == base->map.column)
			break ;
	}
}

void	*selecttiles(t_base *base, int x, int y)
{
	if (base->map.map[x][y] == '1')
		base->mlx.tileset = selectwall(base, x, y);
	else if (base->map.map[x][y] == '0')
		base->mlx.tileset = selectground(base);
	else if (base->map.map[x][y] == 'E')
		base->mlx.tileset = selectexit(base);
	else if (base->map.map[x][y] == 'C')
		base->mlx.tileset = selectconso(base);
	else if (base->map.map[x][y] == 'P')
		base->mlx.tileset = selectplayer(base);
	else
		base->mlx.tileset = selectmonster(base);
	return (base->mlx.tileset);
}

void	settingscreen(t_base *base)
{
	normalmap(base);
	texturesetting(base);
	imagesetexitconso(base);
	imagesetwall(base);
	imagesetplayer(base);
	imagesetground(base);
	imagesetmonster(base);
	setscreen(base);
	mlx_hook(base->mlx.window, 17, 1L << 5, closebycross, NULL);
	mlx_key_hook(base->mlx.window, touchkey, base);
	loop(base);
	mlx_loop(base->mlx.mlx);
}
