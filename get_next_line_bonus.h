/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 15:34:08 by tbatteux          #+#    #+#             */
/*   Updated: 2023/05/02 15:34:11 by tbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <stdlib.h>

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# ifndef FD_LIMITS
#  define FD_LIMITS 1024
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

char	*get_next_line(int fd);
int		ft_strlen(const char *str);
int		found_newline(t_list *stash);
t_list	*ft_lst_get_last(t_list *stash);
void	read_and_stash(int fd, t_list **stash);
void	add_to_stash(t_list **stash, char *buf, int readed);
void	extract_line(t_list *stash, char **line);
void	generate_line(char **line, t_list *stash);
void	clean_stash(t_list **stash);
void	free_stash(t_list *stash);
#endif
