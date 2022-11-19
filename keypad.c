/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypad.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:57:45 by sroggens          #+#    #+#             */
/*   Updated: 2022/10/11 04:15:18 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	touchkey(int key, void *params)
{
	printf("%d\n", key);
	if (key == 53)
		exit(0);
	if (key == 126 || key == 13)
		upanddown_mouvement(params, -1);
	if (key == 125 || key == 1)
		upanddown_mouvement(params, 1);
	if (key == 123 || key == 0)
		leftright_mouvement(params, -1);
	if (key == 124 || key == 2)
		leftright_mouvement(params, 1);
	return (0);
}

int	closebycross(int key, int x, int y, void *params)
{
	(void)y;
	(void)x;
	(void)key;
	(void)params;
	exit(0);
	return (0);
}
