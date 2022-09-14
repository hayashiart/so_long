/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 23:13:13 by slin              #+#    #+#             */
/*   Updated: 2022/01/09 16:57:24 by slin             ###   ########.fr       */
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

void	ft_end(char *tmp, char **pos, int fd)
{
	tmp = pos[fd];
	pos[fd] = ftt_substr(tmp, ftt_str(tmp) + 1,
			ftt_strlen(tmp) - ftt_str(tmp) - 1);
	free(tmp);
}

char	*get_next_line(int fd)
{
	static char	*pos[1024] = {0};
	char		buff[BUFFER_SIZE + 1];
	char		*tmp;
	char		*returnstr;
	int			reader;

	returnstr = NULL;
	reader = 1;
	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 1)
		return (NULL);
	while (!ftt_strchr(pos[fd], '\n') && reader > 0)
	{
		reader = read(fd, buff, BUFFER_SIZE);
		if (reader == -1)
			return (NULL);
		buff[reader] = '\0';
		tmp = pos[fd];
		pos[fd] = ftt_strjoin(tmp, buff);
		free(tmp);
	}
	returnstr = ftt_substr(pos[fd], 0, ftt_str(pos[fd]) + 1);
	ft_end(tmp, pos, fd);
	return (returnstr);
}
