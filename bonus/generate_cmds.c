/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olakhdar <olakhdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:13:46 by olakhdar          #+#    #+#             */
/*   Updated: 2022/03/07 14:22:10 by olakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_middlecmds(t_struct *d, int j)
{
	if (dup2(d->pipefd[(j - 1) * 2], 0) == -1)
	{
		perror("Dup Error");
		exit(1);
	}
	if (close(d->pipefd[(j - 1) * 2]) == -1)
	{
		perror("Close Error");
		exit(1);
	}
	if (dup2(d->pipefd[(j * 2) + 1], 1) == -1)
	{
		perror("Dup Error");
		exit(1);
	}
	if (close(d->pipefd[(j * 2) + 1]) == -1)
	{
		perror("Close Error");
		exit(1);
	}
}

void	ft_lastcmd(t_struct *f, int j)
{
	if (dup2(f->pipefd[(j - 1) * 2], 0) == -1)
	{
		perror("Dup Error");
		exit(1);
	}
	if (close(f->pipefd[(j - 1) * 2]) == -1)
	{
		perror("Close Error");
		exit(1);
	}
	if (dup2(f->fd2, 1) == -1)
	{
		perror("Dup Error");
		exit(1);
	}
	if (close(f->fd2) == -1)
	{
		perror("Close Error");
		exit(1);
	}
}

void	ft_firstcmd(t_struct *f, int j)
{
	if (dup2(f->fd1, 0) == -1)
	{
		perror("Dup Error");
		exit(1);
	}
	if (close(f->fd1) == -1)
	{
		perror("Close Error");
		exit(1);
	}
	if (dup2(f->pipefd[(j * 2) + 1], 1) == -1)
	{
		perror("Dup Error");
		exit(1);
	}
	if (close(f->pipefd[(j * 2) + 1]) == -1)
	{
		perror("Close Error");
		exit(1);
	}
}
