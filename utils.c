/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sroggens <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 15:35:26 by sroggens          #+#    #+#             */
/*   Updated: 2022/09/10 14:03:55 by sroggens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strnstr(char *haystack, char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (needle[0] == 0)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		while (haystack[i + j] == needle[j] && i + j < len)
		{
			if (needle[j + 1] == 0)
				return ((char *)haystack + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

char	*ft_strdup(char *src)
{
	char	*dst;
	int		i;

	i = 0;
	if (!src)
		return (0);
	dst = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		lenword1;
	int		lenword2;
	char	*str;

	i = -1;
	if (s1 && s2)
	{
		lenword1 = ft_strlen(s1);
		lenword2 = ft_strlen(s2);
		str = (char *)malloc(sizeof(char) * (lenword1 + lenword2 + 1));
		if (str == 0)
			return (0);
		while (s1[++i])
			str[i] = s1[i];
		i = -1;
		while (s2[++i])
			str[lenword1 + i] = s2[i];
		str[lenword1 + i] = 0;
		return (str);
	}
	return (NULL);
}

int	checklettre(int ascii, char *lane)
{
	int	i;

	i = 0;
	while (lane[i] != '\n' && lane[i] != ascii)
		i++;
	if (lane[i] == ascii)
		return (1);
	return (0);
}
