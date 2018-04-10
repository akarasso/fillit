/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 18:54:21 by akarasso          #+#    #+#             */
/*   Updated: 2018/04/10 17:55:41 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
int		verify_piece(char *str)
{
	int len;

	len = 0;
	//printf("%s %zu\n", str, ft_strlen(str));
	while (*str)
	{
		//printf("Adresse %p\n", str);
		if ((len + 1) % 5 == 0)
		{
			if (*str != '\n')
			{
				printf("Bad nl\n");
				return (0);
			}
		}
		else
		{
			if (!(*str == '#' || *str == '.'))
			{
				printf("Bad char read %d at %d\n", *str, len);
				return (0);
			}
		}
		len++;
		str++;
	}
	if (len != 20)
	{
		//printf("Bad len piece |%d|\n", len);
		return (0);
	}
	return (1);
}
