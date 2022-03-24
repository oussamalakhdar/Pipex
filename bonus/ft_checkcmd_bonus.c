/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkcmd_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olakhdar <olakhdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:11:52 by olakhdar          #+#    #+#             */
/*   Updated: 2022/03/07 14:38:44 by olakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	ft_error(char *s)
{
	if (s == NULL)
	{
		free(s);
		perror("Command Not Found");
		exit(127);
	}
}

static void	ft_freearray(char **s, int i)
{
	while (s[i++])
		free(s[i]);
	free(s);
}

static char	*ft_strjoin(char *s1, char *s2)
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
	free(s1);
	return (str);
}

static char	*ft_temp(char *argv)
{
	int		i;
	char	*temp;

	i = 0;
	temp = ft_strdup(argv);
	while (temp[i] && temp[i] != ' ')
		i++;
	temp[i] = '\0';
	return (temp);
}

char	*ft_checkcmd_bonus(char **envp, char *argv)
{
	int		i;
	char	*str;
	char	**s;
	char	*temp;

	i = 0;
	if (access(argv, F_OK) == 0)
		return (argv);
	s = ft_path_bonus(envp);
	temp = ft_temp(argv);
	while (s[i])
	{
		str = ft_strjoin(s[i], temp);
		if (access(str, F_OK) == 0)
		{
			ft_freearray(s, i);
			free(temp);
			return (str);
		}
		free (str);
		i++;
	}
	free(temp);
	ft_error(s[i]);
	return (NULL);
}
