/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkcmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olakhdar <olakhdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:11:52 by olakhdar          #+#    #+#             */
/*   Updated: 2022/03/07 14:52:36 by olakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;

	i = 0;
	while (s1[i])
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_error(char *s)
{
	if (s == NULL)
	{
		perror("Command Not Found");
		exit(127);
	}
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '/';
	while (s2[j])
	{
		str[++i] = s2[j];
		j++;
	}
	str[++i] = '\0';
	return (str);
}

char	*ft_checkcmd(char **envp, char *argv)
{
	int		i;
	char	*str;
	char	**s;
	char	*temp;

	i = 0;
	if (access(argv, F_OK) == 0)
		return (argv);
	s = ft_path(envp);
	temp = ft_temp(argv);
	while (s[i++])
	{
		str = ft_strjoin(s[i], temp);
		if (access(str, F_OK) == 0)
		{
			free(temp);
			return (str);
		}
		free(str);
	}
	free(temp);
	ft_error(s[i]);
	return (NULL);
}
