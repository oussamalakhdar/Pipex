/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olakhdar <olakhdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 21:21:02 by olakhdar          #+#    #+#             */
/*   Updated: 2022/03/13 11:02:10 by olakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_closepipes(t_struct *c)
{
	int	i;

	i = 0;
	while (i < c->nmbpipes * 2)
	{
		close(c->pipefd[i]);
		i++;
	}
}

void	ft_parent(t_struct *p)
{
	int	i;

	i = 0;
	ft_closepipes(p);
	while (i < p->nmbpipes + 1)
	{
		wait(NULL);
		i++;
	}
	if (close(p->fd1) == -1)
	{
		perror("Close Error");
		exit(1);
	}
	if (close(p->fd2) == -1)
	{
		perror("Close Error");
		exit(1);
	}
}

void	ft_openpipes(t_struct *o)
{
	int	i;

	i = 0;
	while (i < o->nmbpipes)
	{
		if (pipe(o->pipefd + i * 2) == -1)
		{
			perror("Pipe Error");
			exit(1);
		}
		i++;
	}
}

void	ft_openfiles(t_struct *p, int argc, char **argv)
{
	p->fd1 = open(argv[1], O_RDONLY);
	if (p->fd1 == -1)
	{
		perror("Open error");
		exit(1);
	}
	p->fd2 = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC);
	if (p->fd2 == -1)
	{
		perror("Open error");
		exit(1);
	}
}
