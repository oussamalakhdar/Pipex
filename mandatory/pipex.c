/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olakhdar <olakhdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 14:06:29 by olakhdar          #+#    #+#             */
/*   Updated: 2022/03/13 10:04:06 by olakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	ft_parent(t_list *ptr)
{
	if (close(ptr->pipefd[0]) == -1)
	{
		perror("Close Error");
		exit(1);
	}
	if (close(ptr->pipefd[1]) == -1)
	{
		perror("Close Error");
		exit(1);
	}
	if (close(ptr->fd1) == -1)
	{
		perror("Close Error");
		exit(1);
	}
	if (close(ptr->fd2) == -1)
	{
		perror("Close Error");
		exit(1);
	}
	if (wait(NULL) == -1)
	{
		perror("Wait Error");
		exit(1);
	}
}

static void	ft_open(t_list *pt, char **argv)
{
	pt->fd1 = open(argv[1], O_RDONLY);
	if (pt->fd1 == -1)
	{
		perror("Open Error");
		exit(1);
	}
	pt->fd2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC);
	if (pt->fd2 == -1)
	{
		perror("Open Error");
		exit(1);
	}
}

static void	ft_child2(t_list *p, char **envp, char **argv)
{
	if (close(p->pipefd[1]) == -1)
	{
		perror("Close Error");
		exit(1);
	}
	if (dup2(p->pipefd[0], 0) == -1)
	{
		perror("Dup Error");
		exit(1);
	}
	if (close(p->pipefd[0]) == -1)
	{
		perror("Close Error");
		exit(1);
	}
	if (dup2(p->fd2, 1) == -1)
	{
		perror("Dup Error");
		exit(1);
	}
	if (execve(ft_checkcmd(envp, argv[3]), p->cmd2, envp) == -1)
	{
		perror("Execve Error");
		exit(1);
	}
}

static void	ft_child1(t_list *ptr, char **envp, char **argv)
{
	if (close(ptr->pipefd[0]) == -1)
	{
		perror("Close Error");
		exit(1);
	}
	if (dup2(ptr->fd1, 0) == -1)
	{
		perror("Dup Error");
		exit(1);
	}
	if (dup2(ptr->pipefd[1], 1) == -1)
	{
		perror("Dup Error");
		exit(1);
	}
	if (close(ptr->pipefd[1]) == -1)
	{
		perror("Close Error");
		exit(1);
	}
	if (execve(ft_checkcmd(envp, argv[2]), ptr->cmd1, envp) == -1)
	{
		perror("Execve Error");
		exit(1);
	}
}

int	main(int argc, char *argv[], char **envp)
{
	t_list	l;

	if (argc == 5)
	{
		l.cmd1 = ft_split(argv[2], ' ');
		l.cmd2 = ft_split(argv[3], ' ');
		ft_open(&l, argv);
		pipe(l.pipefd);
		l.childpid1 = fork();
		ft_checkfork1(&l);
		if (l.childpid1 == 0)
			ft_child1(&l, envp, argv);
		l.childpid2 = fork();
		ft_checkfork2(&l);
		if (l.childpid2 == 0)
			ft_child2(&l, envp, argv);
		ft_parent(&l);
		if (wait(NULL) == -1)
		{
			perror("Wait Error");
			exit(1);
		}
	}
	return (0);
}
