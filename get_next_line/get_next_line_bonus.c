/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djo <djo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 16:18:55 by djo               #+#    #+#             */
/*   Updated: 2024/11/03 22:01:08 by djo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*line_to_put(char *buffer)
{
	int		i;
	char	*result;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
		i++;
	result = ft_calloc(i + 1, sizeof(char));
	i = 0;
	while (buffer[i] != '\n' && buffer[i])
	{
		result[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		result[i] = '\n';
	return (result);
}

char	*read_buffer(int fd, char *buf)
{
	char	*buffer;
	int		stat_of_read;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		free(buffer);
	stat_of_read = 1;
	while (stat_of_read)
	{
		stat_of_read = read(fd, buffer, BUFFER_SIZE);
		if (stat_of_read == -1)
		{
			free(buffer);
			free(buf);
			return (NULL);
		}
		buffer[stat_of_read] = '\0';
		buf = ft_join(buf, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (buf);
}

char	*get_next_line(int fd)
{
	static char	*buffer[4096];
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer[fd])
		return (NULL);
	buffer[fd] = read_buffer(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	result = line_to_put(buffer[fd]);
	buffer[fd] = ft_next(buffer[fd]);
	return (result);
}

/*
int main(void)
{
    int		fd;
    char	*line;

	fd = open("text.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("%s", line);
    while (line)
    {
		free(line);
		line = get_next_line(fd);
		printf("%s", line);
    }
	free(line);
	return (0);
}
*/
