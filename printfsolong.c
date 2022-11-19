/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfsolong.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:17:31 by sroggens          #+#    #+#             */
/*   Updated: 2022/09/10 13:56:22 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putcharprintf(char c, int *counter)
{
	write(1, &c, 1);
	(*counter)++;
}

int	ft_printf(const char *txt, ...)
{
	int		i;
	int		count;
	va_list	params;

	va_start(params, txt);
	i = 0;
	count = 0;
	while (txt[i])
	{
		if (txt[i] == '%')
		{
			i++;
			ft_selectnextwords(params, txt[i], &count);
		}
		else
			ft_putcharprintf(txt[i], &count);
		i++;
	}
	va_end(params);
	return (count);
}
