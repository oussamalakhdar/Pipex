/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olakhdar <olakhdar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:43:05 by olakhdar          #+#    #+#             */
/*   Updated: 2022/03/13 10:44:24 by olakhdar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdlib.h>
# include <stdio.h> 
# include <unistd.h>
# include <fcntl.h>
# define BUFFER_SIZE 1

typedef struct s_list
{
	char			**cmd;
	char			*path;
	struct s_list	*next;
}	t_list;

typedef struct p_struct
{
	int		fd1;
	int		fd2;
	int		childpid;
	int		*pipefd;
	int		nmbpipes;
}	t_struct;

typedef struct h_hdoc
{
	int		fd;
	int		pipefd1[2];
	int		pipefd2[2];
	int		childpid1;
	int		childpid2;
	char	**cmd1;
	char	**cmd2;
	char	*buffer;
}	t_hdoc;

char	**ft_path_bonus(char **envp);
char	**ft_split(char const *s, char c);
char	*ft_strdup(char *s1);
char	*ft_checkcmd_bonus(char **envp, char *argv);
void	ft_cmdlists(t_list **lst, int argc, char *argv[], char **envp);
t_list	*ft_lstnew(char **cmd, char *path);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_closepipes(t_struct *c);
void	ft_openpipes(t_struct *o);
void	ft_openfiles(t_struct *p, int argc, char **argv);
void	ft_parent(t_struct *p);
void	ft_heredoc(int argc, char *argv[], char **envp);
void	ft_fork1(t_hdoc *ptr);
void	ft_fork2(t_hdoc *f);
void	ft_parents(t_hdoc *ptr);
void	ft_open(t_hdoc *pt, char **argv);
void	ft_child2_extra(t_hdoc *c);
char	*get_next_line(int fd);
char	*ft_substr(char *s, int start, int len);
int		ft_strlen(char *str);
int		ft_strchr(char *s, char c);
int		ft_strncmp(char *s1, char *s2, int n);
void	ft_free(t_list **lst);
void	ft_freeheredoc(t_hdoc *ptr);
void	ft_middlecmds(t_struct *d, int j);
void	ft_lastcmd(t_struct *f, int j);
void	ft_firstcmd(t_struct *f, int j);

#endif