/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 12:02:50 by sroggens          #+#    #+#             */
/*   Updated: 2022/09/21 22:23:48 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	imagesetground(t_base *base)
{
	base->mlx.ground = mlx_xpm_file_to_image(base->mlx.mlx,
			base->image.ground, &base->mlx.height, &base->mlx.lenght);
}

void	imagesetmonster(t_base *base)
{
	base->mlx.monster = mlx_xpm_file_to_image(base->mlx.mlx,
			base->image.monster, &base->mlx.height, &base->mlx.lenght);
}
