/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akarasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 17:10:32 by akarasso          #+#    #+#             */
/*   Updated: 2018/04/10 17:37:34 by akarasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		error_read(char *buff, int ret)
{
	int shape_char_count;
	int i;

	if (ret < 20)
		return (0);
	shape_char_count = 0;
	i = 0;
	while (i < 20)
	{
		if (buff[i] == '#')
			shape_char_count++;
		if (buff[i] != '#' && buff[i] != '.' && buff[i] != '\n')
			return (0);
		if (i % 5 == 4 && buff[i] != '\n')
			return (0);
		i++;
	}
	if ((ret == 21 && buff[20] != '\n') || shape_char_count != 4)
		return (0);
	return (1);
}
