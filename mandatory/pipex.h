/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olakhdar <olakhdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:43:05 by olakhdar          #+#    #+#             */
/*   Updated: 2022/03/07 14:52:50 by olakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdio.h> 
# include <unistd.h>
# include <fcntl.h>

typedef struct s_list
{
	int		fd1;
	int		fd2;
	int		pipefd[2];
	int		childpid1;
	int		childpid2;
	char	**cmd1;
	char	**cmd2;
}	t_list;

char	**ft_path(char **envp);
char	**ft_split(char const *s, char c);
char	*ft_checkcmd(char **envp, char *argv);
void	ft_checkfork1(t_list *ptr);
void	ft_checkfork2(t_list *p);
char	*ft_strdup(const char *s1);
char	*ft_temp(char *argv);

#endif