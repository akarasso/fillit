/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myparser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 13:21:03 by akarasso          #+#    #+#             */
/*   Updated: 2018/04/10 18:17:04 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

int		parse_to_piece(t_piece **pieces, char *buff, int index)
{
	t_piece *elem;
	elem = *pieces;

	if (!(elem = push_piece(pieces, index)))
		return (0);
	tr_to_shape(elem, buff);
	return (1);
}

int		read_file(int fd, t_piece **pieces)
{
	char	buff[BUFF_SIZE];
	int		ret;
	int		lastret;
	int		index;

	index = 0;
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (!error_read(buff, ret))
			return 0;
		if (!(parse_to_piece(pieces, buff, index)))
			return 0;
		index++;
		lastret = ret;
	}
	if (lastret != 20)
		return (0);
	return (1);
}

void	get_pieces(int fd, t_piece **pieces)
{
	read_file(fd, pieces);
}
