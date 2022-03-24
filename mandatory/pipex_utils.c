/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olakhdar <olakhdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:58:05 by olakhdar          #+#    #+#             */
/*   Updated: 2022/03/07 14:49:32 by olakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_checkfork1(t_list *ptr)
{
	if (ptr->childpid1 == -1)
	{
		perror("fork error");
		exit(1);
	}
}

void	ft_checkfork2(t_list *p)
{
	if (p->childpid2 == -1)
	{
		perror("fork error");
		exit(1);
	}
}

char	*ft_temp(char *argv)
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
