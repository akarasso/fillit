/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 10:54:04 by akarasso          #+#    #+#             */
/*   Updated: 2018/04/10 17:51:40 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE 21
# include <stdio.h>

typedef struct	s_shape
{
	int	x;
	int y;
}				t_shape;

typedef struct	s_piece
{
	t_shape			shape[4];
	char			*str;
	int				index;
	struct s_piece	*next;
}				t_piece;

typedef struct	s_fillit
{
	t_piece	*lst;
	int		len;
	char	**map;
}				t_fillit;

t_piece    *push_piece(t_piece **pcs, int index);
void	get_pieces(int fd, t_piece **pieces);
int     verify_piece(char *str);
int		ft_lstcount(t_piece *lst);
int		map_crt(t_fillit *fillit);

/*
** Lst
*/
int     tr_to_shape(t_piece *elem, char *content);

/*
** Error
*/
int     error_read(char *buff, int ret);
#endif
