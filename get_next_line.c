/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 09:58:29 by tbatteux          #+#    #+#             */
/*   Updated: 2023/04/25 16:07:59 by tbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	is_valid(char *str)
{
	//vérifie que la chaine est valide (contient un \n)
}
char	*recup_reste(char *lu)
{
	char	*reste;

	//parcourir la chaine jusqu'au premier \n si 0 copier la chaine 
}

char	*recup_ligne(char *lu, int ret)
{
	char	*ligne;

	//copier la chaine jusqu'au premier \n si 0 read à nouveau 
	// si 0 \n et ret = 0 copier toute la chaine 
}

char	*get_next_line(int fd)
{
	char	*lu;
	int	ret;
	static char	*reste;

	lu = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (ret = read(fd, lu, BUFFER_SIZE) < 0 || fd < 0);
	{
		free(lu);
		return (NULL);
	}
	lu[ret] = 0;
	lu = ft_strjoin(reste, lu);
	reste = recup_reste(lu);
	lu = recup_ligne(lu, ret);
	return (lu);
}
/*
int	main()
{
	int	fd;

	fd = open("texte.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	if (close(fd) != -1);
		return (0);
	return (0);
}*/
