/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 13:30:49 by sroggens          #+#    #+#             */
/*   Updated: 2022/09/22 06:39:18 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdarg.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

typedef struct s_map
{
	int		conso;
	int		totalconso;
	char	**map;
	int		totalmonster;
	int		fd;
	int		len;
	int		column;
	char	*fulline;
	char	*temp;
	int		countobjectcheck;
	int		countexitcheck;
	int		pc;
	int		pl;
	int		walk;
	int		mc;
	int		ml;
	int		*mv;
	int		mtmp;
	char	*walkprint;
}				t_map;

typedef struct s_image
{
	char	*exit1;
	char	*exit2;
	char	*conso1;
	char	*conso2;
	char	*conso3;
	char	*wallnord;
	char	*wallsud;
	char	*wallest;
	char	*wallouest;
	char	*player1;
	char	*player2;
	char	*player3;
	char	*player4;
	char	*player5;
	char	*ground;
	char	*wallelse;
	char	*monster;
}				t_image;

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
	void	*exit1;
	void	*exit2;
	void	*conso1;
	void	*conso2;
	void	*conso3;
	void	*wallnord;
	void	*wallsud;
	void	*wallest;
	void	*wallouest;
	void	*wallelse;
	void	*player1;
	void	*player2;
	void	*player3;
	void	*player4;
	void	*player5;
	int		totalheight;
	int		totallenght;
	int		lenght;
	int		height;
	int		conso;
	void	*tileset;
	void	*ground;
	void	*monster;
}				t_mlx;

typedef struct s_posplayer
{
	int	playergoingdown;
}				t_posplayer;

typedef struct s_conso
{
	int	conso;
}				t_conso;

typedef struct s_base
{
	t_map		map;
	t_image		image;
	t_mlx		mlx;
	t_posplayer	posplayer;
	t_conso		conso;
}				t_base;

//-------------------split.c-------------------
char	**ft_split(char *s, char c);
//-------------------itoa.c--------------------
char	*ft_itoa(int n);
//-------------------printfsolong.c------------
void	ft_putcharprintf(char c, int *counter);
int		ft_printf(const char *txt, ...);
//--------------------printfsolong2.c----------
void	ft_selectnextwords(va_list params, char txt, int *count);
//---------------get_next_line_utils_so_long.c--
int		ft_strlen(char *str);
char	*strdupgnl(char *buffer);
int		comparegnl(char *box);
char	*strjoingnl(char *box, char *buffer);
//------------gt_next_line_solong.c-----------
char	*writeligne(char *box);
char	*newbox(char *box);
char	*gnlbis(int fd, char *box);
char	*get_next_line(int fd);
//---------------------utils.c----------------
char	*ft_strnstr(char *haystack, char *needle, size_t len);
char	*ft_strdup(char *src);
char	*ft_strjoin(char *s1, char *s2);
int		checklettre(int ascii, char *lane);
//--------------------count.c-----------------
int		countline(char *map, int search);
void	countobjects(t_base *base);
void	countexit(char **map);
void	countplayertotal(char **map);
//-------------------argcheck.c--------------
void	mapsetting(t_base *base, char *argv);
void	charactchecking(char *map);
void	checkarg(char *argv, int argc);
void	checkparsing(char **argv, int argc, t_base *base);
//-------------------testmap.c---------------
void	mapheart(char *map, int len);
void	mapside(t_base *base);
void	formatmap(t_base *base);
void	columncount(t_base *base);
//--------------------solvency.c-------------
void	transforming(t_base *base, int i, int j);
void	checking(t_base *base);
int		countforcheckobjects(char *map);
char	*getbackmap(char *map);
void	normalmap(t_base *base);
//--------------------solvencybis.c--------------
void	transfopart1(t_base *base, int i, int j);
void	transfopart2(t_base *base, int i, int j);
void	transfopart3(t_base *base, int i, int j);
void	transfopart4(t_base *base, int i, int j);
//---------------------texture.c-----------------
void	heightlenght(t_base *base);
void	imagesetplayer(t_base *base);
void	imagesetwall(t_base *base);
void	imagesetexitconso(t_base *base);
void	texturesetting(t_base *base);
//---------------------texture2.c-------------------
void	imagesetground(t_base *base);
void	imagesetmonster(t_base *base);
//---------------------selecttexture.c---------------
void	*selectwall(t_base *base, int j, int i);
void	*selectground(t_base *base);
void	*selectplayer(t_base *base);
void	*selectconso(t_base *base);
void	*selectexit(t_base *base);
//---------------------preparescreen.c-------------
void	setscreen(t_base *base);
void	printtheimage(t_base *base);
void	*selecttiles(t_base *base, int i, int j);
void	settingscreen(t_base *base);
//-----------------------loop.c---------------------
int		refreshmap(t_base *base);
void	loop(t_base *base);
int		animeconso(t_base *base);
//-----------------------keypad.c-------------------
int		touchkey(int key, void *params);
int		closebycross(int key, int x, int y, void *params);
//-----------------------playermouvement.c------------
void	upanddown_mouvement(t_base *base, int nb);
void	posactualplayer(t_base *base);
void	leftright_mouvement(t_base *base, int nb);
//-----------------------playerseek.c-----------------
void	searchplayer(t_base *base);
//***************************************************
//***************************************************
//************************BONUS**********************
//***************************************************
//***************************************************
//---------------------countbonus.c------------------
void	countmonster(t_base *base);
void	countplayertotal(char **map);
void	countexit(char **map);
void	countobjects(t_base *base);
int		countline(char *map, int search);
//--------------------argcheckbonus.c----------------
void	mapsetting(t_base *base, char *argv);
void	charactchecking(char *map);
void	checkarg(char *argv, int argc);
void	checkparsing(char **argv, int argc, t_base *base);
//--------------------selectexturebonus.c------------
void	*selectmonster(t_base *base);
//--------------------preparescreenbonus.c-----------
void	setscreen(t_base *base);
void	printtheimage(t_base *base);
void	*selecttiles(t_base *base, int x, int y);
void	settingscreen(t_base *base);
//-------------------mouvementenemy.c----------------
void	moveenemy(t_base *base);
void	searchmonster(t_base *base);
void	kill(t_base *base);
void	allmonstermove(t_base *base);
//-------------------keypadbonus.c-------------------
void	mouvebonusupanddown(t_base *base, int nb);
void	mouvebonusleftandright(t_base *base, int nb);
int		touchkey(int key, void *params);
#endif
