/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 20:15:00 by sroggens          #+#    #+#             */
/*   Updated: 2022/09/21 22:25:47 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	texturesetting(t_base *base)
{
	base->image.exit1 = "./texture/exit/exit1.xpm";
	base->image.exit2 = "./texture/exit/exit2.xpm";
	base->image.conso1 = "./texture/conso/conso1.xpm";
	base->image.conso2 = "./texture/conso/conso2.xpm";
	base->image.conso3 = "./texture/conso/conso3.xpm";
	base->image.wallnord = "./texture/wall/wallnord.xpm";
	base->image.wallsud = "./texture/wall/wallsud.xpm";
	base->image.wallest = "./texture/wall/wallest.xpm";
	base->image.wallouest = "./texture/wall/wallouest.xpm";
	base->image.player1 = "./texture/player/player1.xpm";
	base->image.player2 = "./texture/player/player2.xpm";
	base->image.player3 = "./texture/player/player3.xpm";
	base->image.player4 = "./texture/player/player4.xpm";
	base->image.player5 = "./texture/player/player5.xpm";
	base->image.ground = "./texture/ground/desertground.xpm";
	base->image.wallelse = "./texture/wall/wallelse.xpm";
	base->image.monster = "./texture/monster/monster.xpm";
	if (open(base->image.player5, O_RDONLY) == -1)
	{
		ft_printf("Wrong path or no texture");
		exit (0);
	}
}

void	imagesetexitconso(t_base *base)
{
	base->mlx.mlx = mlx_init();
	base->mlx.exit1 = mlx_xpm_file_to_image(base->mlx.mlx, base->image.exit1,
			&base->mlx.height, &base->mlx.lenght);
	base->mlx.exit2 = mlx_xpm_file_to_image(base->mlx.mlx, base->image.exit2,
			&base->mlx.height, &base->mlx.lenght);
	base->mlx.conso1 = mlx_xpm_file_to_image(base->mlx.mlx, base->image.conso1,
			&base->mlx.height, &base->mlx.lenght);
	base->mlx.conso2 = mlx_xpm_file_to_image(base->mlx.mlx, base->image.conso2,
			&base->mlx.height, &base->mlx.lenght);
	base->mlx.conso3 = mlx_xpm_file_to_image(base->mlx.mlx, base->image.conso3,
			&base->mlx.height, &base->mlx.lenght);
}

void	imagesetwall(t_base *base)
{
	base->mlx.wallnord = mlx_xpm_file_to_image(base->mlx.mlx,
			base->image.wallnord, &base->mlx.height, &base->mlx.lenght);
	base->mlx.wallsud = mlx_xpm_file_to_image(base->mlx.mlx,
			base->image.wallsud, &base->mlx.height, &base->mlx.lenght);
	base->mlx.wallouest = mlx_xpm_file_to_image(base->mlx.mlx,
			base->image.wallouest, &base->mlx.height, &base->mlx.lenght);
	base->mlx.wallest = mlx_xpm_file_to_image(base->mlx.mlx,
			base->image.wallest, &base->mlx.height, &base->mlx.lenght);
	base->mlx.wallelse = mlx_xpm_file_to_image(base->mlx.mlx,
			base->image.wallelse, &base->mlx.height, &base->mlx.lenght);
}

void	imagesetplayer(t_base *base)
{
	base->mlx.player1 = mlx_xpm_file_to_image(base->mlx.mlx,
			base->image.player1, &base->mlx.height, &base->mlx.lenght);
	base->mlx.player2 = mlx_xpm_file_to_image(base->mlx.mlx,
			base->image.player2, &base->mlx.height, &base->mlx.lenght);
	base->mlx.player3 = mlx_xpm_file_to_image(base->mlx.mlx,
			base->image.player3, &base->mlx.height, &base->mlx.lenght);
	base->mlx.player4 = mlx_xpm_file_to_image(base->mlx.mlx,
			base->image.player4, &base->mlx.height, &base->mlx.lenght);
	base->mlx.player5 = mlx_xpm_file_to_image(base->mlx.mlx,
			base->image.player5, &base->mlx.height, &base->mlx.lenght);
}

void	heightlenght(t_base *base)
{
	int	len;

	len = 0;
	base->mlx.lenght = 32;
	base->mlx.height = 32;
	base->mlx.totalheight = ft_strlen(base->map.map[0]) * base->mlx.height;
	while (base->map.map[len])
		len++;
	base->mlx.totallenght = len * base->mlx.lenght;
}
