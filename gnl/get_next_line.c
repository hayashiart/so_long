/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 22:32:13 by slin              #+#    #+#             */
/*   Updated: 2022/01/04 14:26:14 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ftt_str(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*pos = NULL;
	char		buff[BUFFER_SIZE + 1];
	char		*tmp;
	char		*returnstr;
	int			reader;

	returnstr = NULL;
	reader = 1;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	while (!ftt_strchr(pos, '\n') && reader > 0)
	{
		reader = read(fd, buff, BUFFER_SIZE);
		if (reader == -1)
			return (NULL);
		buff[reader] = '\0';
		tmp = pos;
		pos = ftt_strjoin(tmp, buff);
		free(tmp);
	}
	returnstr = ftt_substr(pos, 0, ftt_str(pos) + 1);
	tmp = pos;
	pos = ftt_substr(tmp, ftt_str(tmp) + 1, ftt_strlen(tmp) - ftt_str(tmp) - 1);
	free(tmp);
	return (returnstr);
}
