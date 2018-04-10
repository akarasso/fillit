/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 14:46:08 by akarasso          #+#    #+#             */
/*   Updated: 2018/04/10 15:22:02 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		map_crt(t_fillit *fillit)
{
	char	**map;
	int		i;

	i = 0;
	if (!(map = (char**)ft_memalloc(fillit->len * 4)))
		return (0);
	while (i < fillit->len * 4)
	{
		if (!(map[i] = (char *)ft_memalloc(fillit->len * 4)))
			return (0);
		i++;
	}
	return (1);
}
