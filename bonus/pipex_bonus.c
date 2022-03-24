/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olakhdar <olakhdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 19:50:00 by olakhdar          #+#    #+#             */
/*   Updated: 2022/03/24 10:16:01 by olakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_fork(t_struct *ptr)
{
	ptr->childpid = fork();
	if (ptr->childpid == -1)
	{
		perror("fork Error");
		exit(1);
	}
}

void	ft_commands(t_struct *ptr, t_list *lst, int j)
{
	if (j == 0)
		ft_firstcmd(ptr, j);
	else if (!lst->next)
		ft_lastcmd(ptr, j);
	else
		ft_middlecmds(ptr, j);
}

void	ft_processs(t_struct *p, int argc, char **argv, char **envp)
{
	t_list	*lst;
	t_list	*tmp;
	int		j;

	j = 0;
	lst = NULL;
	tmp = NULL;
	ft_cmdlists(&lst, argc, argv, envp);
	tmp = lst;
	while (lst != NULL)
	{
		ft_fork(p);
		if (p->childpid == 0)
		{
			ft_commands(p, lst, j);
			ft_closepipes(p);
			execve(lst->path, lst->cmd, envp);
		}
		lst = lst->next;
		j++;
	}
	ft_free(&tmp);
}

int	main(int argc, char *argv[], char **envp)
{
	t_struct	l;

	if (argc > 4)
	{
		if ((ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) == 1) && argc == 6)
			ft_heredoc(argc, argv, envp);
		else
		{
			l.nmbpipes = argc - 4;
			l.pipefd = malloc((l.nmbpipes * 2) * sizeof(int));
			if (!l.pipefd)
				return (0);
			ft_openfiles(&l, argc, argv);
			ft_openpipes(&l);
			ft_processs(&l, argc, argv, envp);
			ft_parent(&l);
		}
	}
	return (0);
}
