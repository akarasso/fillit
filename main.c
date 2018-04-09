/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 13:23:11 by akarasso          #+#    #+#             */
/*   Updated: 2018/04/09 18:56:25 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "fillit.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int	main(int argc, char **argv)
{
	int		fd;
	t_piece	*pieces;
	char	*lines;

	pieces = 0;
	if (argc == 2 && (fd = open(argv[1], O_RDONLY)) > 0)
	{
		lines = 0;
		get_pieces(fd, &pieces);
		while (pieces)
		{
			printf("Content\n%s\n", pieces->str);
			pieces = pieces->next;
		}
	}
}
