/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olakhdar <olakhdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 18:10:00 by olakhdar          #+#    #+#             */
/*   Updated: 2022/03/07 11:19:51 by olakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

t_list	*ft_lstnew(char **cmd, char *path)
{
	t_list	*ptr;

	ptr = malloc(sizeof(t_list));
	if (ptr == NULL)
		return (NULL);
	ptr->cmd = cmd;
	ptr->path = path;
	ptr->next = NULL;
	return (ptr);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	if ((*lst) == NULL)
	{
		*lst = new;
		(*lst)->next = NULL;
		return ;
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = new;
}

void	ft_cmdlists(t_list **lst, int argc, char *argv[], char **envp)
{	
	t_list	*new;
	int		i;

	i = 2;
	new = NULL;
	while (argc - 3 > 0)
	{
		new = ft_lstnew(ft_split(argv[i], ' '),
				ft_checkcmd_bonus(envp, argv[i]));
		ft_lstadd_back(lst, new);
		i++;
		argc--;
	}
}

void	ft_free(t_list **lst)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *lst;
	while (tmp)
	{
		*lst = tmp;
		i = 0;
		while ((*lst)->cmd[i])
			free((*lst)->cmd[i++]);
		free((*lst)->cmd);
		free((*lst)->path);
		free(*lst);
		tmp = tmp->next;
	}
}
