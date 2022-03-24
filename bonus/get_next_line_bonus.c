/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olakhdar <olakhdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 20:17:38 by olakhdar          #+#    #+#             */
/*   Updated: 2022/02/26 18:12:28 by olakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	free(s1);
	return (str);
}

static char	*ft_rest(char **stock)
{
	int		j;
	char	*tmp;
	char	*line;

	j = ft_strchr(*stock, '\n');
	line = ft_substr(*stock, 0, j + 1);
	tmp = *stock;
	*stock = ft_substr(*stock, j + 1, ft_strlen(*stock + j + 1));
	free(tmp);
	return (line);
}

static char	*ft_line(char **stock)
{
	char	*line;

	if (ft_strchr(*stock, '\n') != -1)
		line = ft_rest(stock);
	else if ((*stock)[0] == '\0')
	{
		free(*stock);
		*stock = NULL;
		return (NULL);
	}
	else
	{
		line = ft_substr(*stock, 0, ft_strlen(*stock));
		free(*stock);
		*stock = NULL;
	}
	return (line);
}

static void	ft_stock(char **stock, int fd)
{
	int		i;
	char	*buffer;

	i = 0;
	while (ft_strchr(*stock, '\n') == -1)
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (buffer == NULL)
			return ;
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1 || i == 0)
		{
			free(buffer);
			break ;
		}
		buffer[i] = '\0';
		*stock = ft_strjoin(*stock, buffer);
		free(buffer);
	}
}

char	*get_next_line(int fd)
{
	static char	*stock;

	if (!stock)
	{
		stock = ft_strdup("");
		if (!stock)
			return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_stock(&stock, fd);
	return (ft_line(&stock));
}
