/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaldhahe <zaldhahe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 18:19:23 by zaldhahe          #+#    #+#             */
/*   Updated: 2024/01/29 21:14:22 by zaldhahe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*buffer_line(int fd, char *str, char *buffer)
{
	ssize_t	cread;
	char	*tmp;

	cread = 1;
	while (cread > 0)
	{
		cread = read(fd, buffer, BUFFER_SIZE);
		if (cread == -1)
		{
			free(str);
			return (NULL);
		}
		else if (cread == 0)
			break ;
		buffer[cread] = 0;
		if (!str)
			str = ft_strdup("");
		tmp = str;
		str = ft_strjoin(tmp, buffer);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (str);
}

char	*get_line(char *lbuffer)
{
	char	*str;
	ssize_t	i;
	
	i = 0;
	while (lbuffer[i] != '\0' && lbuffer[i] != '\n')
		i++;
	if (lbuffer[i] == 0 || lbuffer[1] == 0)
		return (NULL);
	str = ft_substr(lbuffer, i + 1, ft_strlen(lbuffer) - 1);
	lbuffer[i + 1] = 0;
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;
	char		*buffer;

	buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
	{
		free(str);
		free(buffer);
		str = NULL;
		buffer = NULL;
		return (NULL);
	}
	line = buffer_line(fd, str, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	str = get_line(line);
	return (line);
}

// int main()
// {
// 	int fd = open("h.txt", O_RDONLY);
// 	char *str = get_next_line(fd);
// 	while (str)
// 	{
// 		printf("%s\n", str);
// 		str = get_next_line(fd);
// 	}
// }