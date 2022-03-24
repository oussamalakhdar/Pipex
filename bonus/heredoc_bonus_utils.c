/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olakhdar <olakhdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 21:31:31 by olakhdar          #+#    #+#             */
/*   Updated: 2022/03/13 10:44:20 by olakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_fork1(t_hdoc *ptr)
{
	ptr->childpid1 = fork();
	if (ptr->childpid1 == -1)
	{
		perror("fork error");
		exit(1);
	}
}

void	ft_fork2(t_hdoc *f)
{
	f->childpid2 = fork();
	if (f->childpid2 == -1)
	{
		perror("fork error");
		exit(1);
	}
}

void	ft_parents(t_hdoc *ptr)
{
	if (close(ptr->pipefd2[0]) == -1)
	{
		perror("Close Error");
		exit(1);
	}
	if (close(ptr->pipefd2[1]) == -1)
	{
		perror("Close Error");
		exit(1);
	}
	if (wait(NULL) == -1)
	{
		perror("Wait Error");
		exit(1);
	}
	if (wait(NULL) == -1)
	{
		perror("Wait Error");
		exit(1);
	}
	if (close(ptr->fd) == -1)
	{
		perror("Close Error");
		exit(1);
	}
}

void	ft_open(t_hdoc *pt, char **argv)
{
	pt->fd = open(argv[5], O_WRONLY | O_CREAT | O_APPEND);
	if (pt->fd == -1)
	{
		perror("Open Error");
		exit(1);
	}
}

void	ft_child2_extra(t_hdoc *c)
{
	if (dup2(c->fd, 1) == -1)
	{
		perror("Dup Error");
		exit(1);
	}
	if (close(c->fd) == -1)
	{
		perror("Close Error");
		exit(1);
	}
}
