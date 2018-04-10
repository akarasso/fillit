/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 18:51:07 by akarasso          #+#    #+#             */
/*   Updated: 2018/04/10 18:28:41 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		ft_lstcount(t_piece *elem)
{
	int len;

	len = 0;
	while (elem)
	{
		len++;
		elem = elem->next;
	}
	return (len);
}

void	store_shape(t_piece *elem, int x[4], int y[4])
{
	int x_min;
	int	y_min;
	int i;

	x_min = 10;
	y_min = 10;
	i = 0;
	while (i < 4)
	{
		x_min = (x[i] < x_min) ? x[i] : x_min;
		y_min = (y[i] < y_min) ? y[i] : y_min;
		i++;
	}
	i = 0;
	while (i < 4)
	{
		printf("XI:%d Value %d\n", i, x[i] - x_min);
		printf("YI:%d Value %d\n", i, y[i] - y_min);
		elem->shape[i].x = x[i] - x_min;
		elem->shape[i].y = y[i] - y_min;
		i++;
	}
	printf("===============\n");
}

int		tr_to_shape(t_piece *elem, char *content)
{
	int		x[4];
	int		y[4];
	int		line;
	int		index;
	int		i;

	i = 0;
	line = 0;
	index = 0;
	while (i < BUFF_SIZE)
	{
		if (content[i] == '#')
		{
			x[index] = line % 4;
			y[index] = line / 4;
			index++;
		}
		if (content[i] == '\n')
			line++;
		i++;
	}
	store_shape(elem, x, y);
	return (1);
}

t_piece		*push_piece(t_piece **pcs, int index)
{
	t_piece *elem;

	elem = *pcs;
	if (elem)
	{
		while (elem->next)
			elem = elem->next;
		if (!(elem->next = (t_piece*)ft_memalloc(sizeof(*elem))))
			return (0);
		elem->next->next = 0;
		elem->next->index = index;
		return (elem->next);
	}
	else
	{
		if (!(elem = (t_piece*)ft_memalloc(sizeof(*elem))))
			return (0);
		elem->next = 0;
		elem->index = index;
		*pcs = elem;
		return (elem);
	}
}
