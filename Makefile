# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: olakhdar <olakhdar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/03 12:53:12 by olakhdar          #+#    #+#              #
#    Updated: 2022/03/16 13:38:22 by olakhdar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mandatory/pipex

BONUS = bonus/pipex_bonus

CC = gcc

FLAGS =  -Wall -Werror -Wextra

FILES = mandatory/pipex.c mandatory/pipex_utils.c mandatory/ft_checkcmd.c mandatory/ft_path.c mandatory/ft_split.c \

BFILES = bonus/pipex_bonus.c bonus/ft_lists_bonus.c bonus/ft_checkcmd_bonus.c bonus/ft_path_bonus.c \
		bonus/ft_split_bonus.c bonus/get_next_line_bonus.c bonus/here_doc_bonus.c  \
		bonus/heredoc_bonus_utils.c bonus/pipex_bonus_utils.c bonus/pipex_utils_bonus.c \
		bonus/free_heredoc_bonus.c  bonus/generate_cmds.c \

all: $(NAME)

bonus: $(BONUS)

$(NAME): 
	$(CC) $(FLAGS) $(FILES) -o $(NAME)

$(BONUS):
	cc $(FLAGS) $(BFILES) -o $(BONUS)

clean:
	rm -f $(NAME) $(BONUS)

fclean: clean

re: fclean all