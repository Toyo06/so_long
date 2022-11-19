/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerseek.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:17:54 by sroggens          #+#    #+#             */
/*   Updated: 2022/09/21 20:19:02 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	searchplayer(t_base *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base->map.map[i][j])
	{
		if (base->map.map[i][j] == 'P')
			break ;
		else if (base->map.map[i][j + 1] == '\0')
		{
			i++;
			j = 0;
		}
		j++;
	}
	base->map.pc = i;
	base->map.pl = j;
}
