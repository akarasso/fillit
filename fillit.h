/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 10:54:04 by akarasso          #+#    #+#             */
/*   Updated: 2018/04/09 18:58:24 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
typedef struct	s_piece
{
	char			*str;
	struct s_piece	*next;
}				t_piece;

void	get_pieces(int fd, t_piece **pieces);
void    push_piece(t_piece **pcs, char *content);
int     verify_piece(char *str);

#endif
