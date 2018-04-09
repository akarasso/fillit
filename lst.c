/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 18:51:07 by akarasso          #+#    #+#             */
/*   Updated: 2018/04/09 18:52:51 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void    push_piece(t_piece **pcs, char *content)
{
	t_piece *elem;

	elem = *pcs;
	if (elem)
	{
		while (elem->next)
			elem = elem->next;
		elem->next = (t_piece*)ft_memalloc(sizeof(*elem));
		elem->next->next = 0;
		elem->next->str = content;
	}
	else
	{
		*pcs = (t_piece*)ft_memalloc(sizeof(*pcs));
		(*pcs)->next = 0;
		(*pcs)->str = content;
	}
}
