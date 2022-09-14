/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:51:47 by slin              #+#    #+#             */
/*   Updated: 2022/01/09 16:52:00 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ftt_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ftt_strjoin(char const *str1, char const *str2)
{
	char			*newstr;
	int				i;
	int				str1_size;
	int				str2_size;

	str1_size = ftt_strlen(str1);
	str2_size = ftt_strlen(str2);
	i = 0;
	newstr = malloc(sizeof(char) * (str1_size + str2_size + 1));
	if (!newstr)
		return (NULL);
	while (i < str1_size)
	{
		newstr[i] = str1[i];
		i++;
	}
	i = 0;
	while (i < str2_size)
	{
		newstr[str1_size + i] = str2[i];
		i++;
	}
	newstr[str1_size + str2_size] = '\0';
	return (newstr);
}

int	ftt_strchr(const char *str, int c)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ftt_substr(char const *s, int start, int len)
{
	char	*substring;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	if (start >= ftt_strlen(s))
		return (NULL);
	substring = malloc(sizeof(char) * (len + 1));
	if (!substring)
		return (NULL);
	while (i < len && s[start + i])
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}
