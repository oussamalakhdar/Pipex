/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olakhdar <olakhdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 21:39:50 by olakhdar          #+#    #+#             */
/*   Updated: 2022/03/07 11:46:21 by olakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_child2(t_hdoc *p, char **envp, char **argv)
{
	if (close(p->pipefd2[1]) == -1)
	{
		perror("Close Error");
		exit(1);
	}
	if (dup2(p->pipefd2[0], 0) == -1)
	{
		perror("Dup Error");
		exit(1);
	}
	if (close(p->pipefd2[0]) == -1)
	{
		perror("Close Error");
		exit(1);
	}
	ft_child2_extra(p);
	if (execve(ft_checkcmd_bonus(envp, argv[4]), p->cmd2, envp) == -1)
	{
		perror("Execve Error");
		exit(1);
	}
}

void	ft_child1_extra(t_hdoc *c)
{
	if (close(c->pipefd2[0]) == -1)
	{
		perror("Close Error");
		exit(1);
	}
	if (dup2(c->pipefd2[1], 1) == -1)
	{
		perror("Dup Error");
		exit(1);
	}
	if (close(c->pipefd2[1]) == -1)
	{
		perror("Close Error");
		exit(1);
	}	
}

void	ft_child1(t_hdoc *ptr, char **envp, char **argv)
{
	if (close(ptr->pipefd1[1]) == -1)
	{
		perror("Close Error");
		exit(1);
	}
	if (dup2(ptr->pipefd1[0], 0) == -1)
	{
		perror("Dup Error");
		exit(1);
	}
	if (close(ptr->pipefd1[0]) == -1)
	{
		perror("Close Error");
		exit(1);
	}
	ft_child1_extra(ptr);
	if (execve(ft_checkcmd_bonus(envp, argv[3]), ptr->cmd1, envp) == -1)
	{
		perror("Execve Error");
		exit(1);
	}
}

void	ft_process(t_hdoc *pt, char **envp, char **argv)
{
	if (pipe(pt->pipefd1) == -1)
	{
		perror("Pipe Error");
		exit(1);
	}
	while (pt->buffer)
	{
		write(1, "pipe heredoc>", 13);
		pt->buffer = get_next_line(0);
		if (ft_strncmp(pt->buffer, argv[2], ft_strlen(argv[2])) == 1)
		{
			free(pt->buffer);
			break ;
		}
		write(pt->pipefd1[1], pt->buffer, ft_strlen(pt->buffer));
		free(pt->buffer);
	}
	ft_child1(pt, envp, argv);
}

void	ft_heredoc(int argc, char **argv, char **envp)
{
	t_hdoc	hd;

	if (argc > 5)
	{
		hd.cmd1 = ft_split(argv[3], ' ');
		hd.cmd2 = ft_split(argv[4], ' ');
		ft_open(&hd, argv);
		pipe(hd.pipefd2);
		ft_fork1(&hd);
		hd.buffer = ft_strdup("");
		if (hd.childpid1 == 0)
			ft_process(&hd, envp, argv);
		ft_fork2(&hd);
		if (hd.childpid2 == 0)
			ft_child2(&hd, envp, argv);
		ft_parents(&hd);
		ft_freeheredoc(&hd);
	}
}
