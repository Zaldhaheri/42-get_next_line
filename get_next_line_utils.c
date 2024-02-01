/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaldhahe <zaldhahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:19:18 by zaldhahe          #+#    #+#             */
/*   Updated: 2024/02/01 20:00:54 by zaldhahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char) c)
			break ;
		str++;
	}
	if (*str == (char)c)
		return ((char *)str);
	return (NULL);
}

char	*ft_strdup(const char *str)
{
	char	*dup;
	int		i;

	i = 0;
	dup = (char *) malloc(ft_strlen(str) + 1);
	if (!dup)
		return (NULL);
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*r;
	size_t			i;
	unsigned int	strlen;

	i = 0;
	strlen = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start >= strlen)
		return (ft_strdup(""));
	if (len + start >= strlen)
		len = strlen - start;
	r = malloc(sizeof(char) * len + 1);
	if (!r)
		return (NULL);
	while (s[start] && i < len)
		r[i++] = s[start++];
	r[i] = '\0';
	return (r);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	size_t	j;
	char	*r;

	i = 0;
	j = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	r = (char *) malloc(sizeof(char) * (len1 + len2 + 1));
	if (!r)
		return (NULL);
	while (s1[i])
	{
		r[i] = s1[i];
		i++;
	}
	while (s2[j])
		r[i++] = s2[j++];
	r[i] = '\0';
	return (r);
}
