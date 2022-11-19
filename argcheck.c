/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <sroggens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:43:05 by sroggens          #+#    #+#             */
/*   Updated: 2022/10/21 14:55:47 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mapsetting(t_base *base, char *argv)
{
	base->map.fd = open(argv, O_RDONLY);
	if (base->map.fd < 0)
	{
		ft_printf("File does not exist");
		exit(0);
	}
	base->map.temp = get_next_line(base->map.fd);
	if (base->map.temp == NULL)
	{
		ft_printf("File is empty or a directorie");
		exit(0);
	}
	base->map.len = ft_strlen(base ->map.temp) - 1;
	base->map.fulline = strdupgnl(base->map.temp);
	free(base->map.temp);
	while (base->map.temp)
	{
		base->map.temp = get_next_line(base->map.fd);
		if (base->map.temp == NULL)
			break ;
		base->map.fulline = strjoingnl(base->map.fulline,
				base->map.temp);
		free(base->map.temp);
	}
	base->map.map = ft_split(base->map.fulline, 10);
}

void	charactchecking(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == 48 || map[i] == 49 || map[i] == 80
			|| map[i] == 69 || map[i] == 67 || map[i] == '\0'
			|| map[i] == '\n')
			i++;
		else
		{
			ft_printf("Bad char used");
			exit(0);
		}
	}
}

void	checkarg(char *argv, int argc)
{
	int	i;

	i = ft_strlen(argv);
	if (argc != 2)
	{
		ft_printf("Too much arguments");
		exit(0);
	}
	if (ft_strnstr(argv, ".ber", 4) != 0 && argv[4] == '\0')
	{
		ft_printf("No args before .ber");
		exit(0);
	}
	if (ft_strnstr(argv, ".ber", ft_strlen(argv)) == 0)
	{
		ft_printf("Invalid map name");
		exit (0);
	}
	if (argv[i - 1] != 114 || (argv[i - 1] == 114 && argv[i - 2] != 101))
	{
		ft_printf("Invalid map name");
		exit(0);
	}
}

void	checkparsing(char **argv, int argc, t_base *base)
{
	int	i;

	i = 0;
	checkarg(argv[1], argc);
	mapsetting(base, argv[1]);
	countplayertotal(base->map.map);
	countexit(base->map.map);
	countobjects(base);
	formatmap(base);
	columncount(base);
	mapside(base);
	searchplayer(base);
	transforming(base, base->map.pc, base->map.pl);
	heightlenght(base);
}
