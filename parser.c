/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myparser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 13:21:03 by akarasso          #+#    #+#             */
/*   Updated: 2018/04/09 18:58:31 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

#define BUFF_SIZE 128

void	parse_to_piece(char *buffer, int len, t_piece **pieces)
{
	t_piece *elem;
	char	*tmp;	
	elem = *pieces;
	while (len >= 20)
	{
		tmp = ft_strsub((const char*)buffer, 0, 20);
		if (verify_piece(tmp))
			push_piece(pieces, ft_strsub((const char*)buffer, 0, 20));
		len = len - 21;
		buffer += 20;
		if (*buffer == '\n')
			buffer++;
	}
}

void	read_file(int fd, int *len, char **lines)
{
	char	*tmp;
	char	buff[BUFF_SIZE + 1];
	int		ret;

	*lines = ft_strnew(0);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = 0;
		tmp = ft_strjoin(*lines, buff);
		free(*lines);
		*lines = tmp;
		*len += ret;
	}
}

void	get_pieces(int fd, t_piece **pieces)
{
	char	*rd;
	int		len;

	read_file(fd, &len, &rd);
	parse_to_piece(rd, len, pieces);
}
