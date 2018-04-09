/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 18:54:21 by akarasso          #+#    #+#             */
/*   Updated: 2018/04/09 19:21:23 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		verify_piece(char *str)
{
	int len;

	len = 0;
	while (*str)
	{
		if (len != 0 && len + 1 % 5 == 0 && *str != '\n')
		{
			printf("%d %c", len, *str);
			return (0);
		}
		else if (len + 1 % 5 != 0 && !(*str == '.' || *str == '#'))
		{
			printf("read bad char %c %d\n", *str, len);
			return (0);
		}
		len++;
		str++;
	}
	if (len != 20)
	{
		printf("Bad len %d\n", len);
		return (0);
	}
	return (1);
}
