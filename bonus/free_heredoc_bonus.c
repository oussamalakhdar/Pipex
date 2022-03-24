/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_heredoc_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olakhdar <olakhdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 11:45:44 by olakhdar          #+#    #+#             */
/*   Updated: 2022/03/13 10:44:15 by olakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_freeheredoc(t_hdoc *ptr)
{
	int	i;

	i = 0;
	while (ptr->cmd1[i])
	{
		free(ptr->cmd1[i]);
		i++;
	}
	free(ptr->cmd1);
	i = 0;
	while (ptr->cmd2[i])
	{
		free(ptr->cmd2[i]);
		i++;
	}
	free(ptr->cmd2);
	free(ptr->buffer);
}
