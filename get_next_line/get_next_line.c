/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouron <mlouron@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 12:03:50 by mlouron           #+#    #+#             */
/*   Updated: 2025/06/04 10:38:55 by mlouron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*stock_line(char *buf)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	j = 0;
	while (buf[i] != '\n' && buf[i])
		i++;
	if (buf[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = buf[j];
		j++;
	}
	line[i] = '\0';
	return (line);
}

char	*stock_rest(char *stash)
{
	size_t	i;
	size_t	j;
	char	*rest;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\0')
		return (free(stash), NULL);
	if (stash[i++] != '\n')
		return (free(stash), NULL);
	j = 0;
	while (stash[i + j])
		j++;
	if (j == 0)
		return (free(stash), NULL);
	rest = malloc(sizeof(char) * (j + 1));
	if (!rest)
		return (free(stash), NULL);
	j = 0;
	while (stash[i])
		rest[j++] = stash[i++];
	rest[j] = '\0';
	free(stash);
	return (rest);
}

char	*get_next_line(int fd)
{
	static char		*stash;
	char			*buf;
	char			*line;
	ssize_t			byte_read;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	byte_read = 1;
	while (byte_read > 0 && !ft_strchr(stash, '\n'))
	{
		byte_read = read(fd, buf, BUFFER_SIZE);
		if (byte_read == -1)
			return (free(stash), free(buf), stash = NULL, NULL);
		if (byte_read == 0)
			break ;
		buf[byte_read] = '\0';
		stash = ft_strjoin(stash, buf);
	}
	free(buf);
	if (!stash || !*stash)
		return (free(stash), stash = NULL, NULL);
	line = stock_line(stash);
	stash = stock_rest(stash);
	return (line);
}

// int main(void)
// {
// 	char *line;
// 	int fd;
// 	fd = open("test.txt", O_RDONLY);
// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	return 0;
// }