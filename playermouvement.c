/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playermouvement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:07:50 by sroggens          #+#    #+#             */
/*   Updated: 2022/09/22 00:28:20 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	upanddown_mouvement(t_base *base, int nb)
{
	searchplayer(base);
	if (base->map.map[base->map.pc + nb][base->map.pl] == 'E' && base->map.conso
			== base->map.totalconso)
		exit (0);
	else if (base->map.map[base->map.pc + nb][base->map.pl] == 'E')
		return ;
	else if (base->map.map[base->map.pc + nb][base->map.pl] == '1')
		return ;
	else if (base->map.map[base->map.pc + nb][base->map.pl] == 'C')
		base->map.conso++;
	else if (base->map.map[base->map.pc + nb][base->map.pl] == 'M')
	{
		ft_printf("You died");
		exit (0);
	}
	base->map.map[base->map.pc + nb][base->map.pl] = 'P';
	base->map.map[base->map.pc][base->map.pl] = '0';
	base->map.walk++;
}

void	leftright_mouvement(t_base *base, int nb)
{
	searchplayer(base);
	if (base->map.map[base->map.pc][base->map.pl + nb] == 'E' && base->map.conso
			== base->map.totalconso)
		exit(0);
	else if (base->map.map[base->map.pc][base->map.pl + nb] == 'E')
		return ;
	else if (base->map.map[base->map.pc][base->map.pl + nb] == '1')
		return ;
	else if (base->map.map[base->map.pc][base->map.pl + nb] == 'C')
		base->map.conso++;
	else if (base->map.map[base->map.pc][base->map.pl + nb] == 'M')
	{
		ft_printf("You died");
		exit (0);
	}
	base->map.map[base->map.pc][base->map.pl + nb] = 'P';
	base->map.map[base->map.pc][base->map.pl] = '0';
	base->map.walk++;
}
