/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 09:58:29 by tbatteux          #+#    #+#             */
/*   Updated: 2023/04/25 15:51:53 by tbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	char	*buf;
	int	ret;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	ret = read(fd, buf, BUFFER_SIZE);
	return (buf);
}

int	main()
{
	int	fd;

	fd = open("texte.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	printf("%s", get_next_line(fd));
	printf("\n");
	printf("%s", get_next_line(fd));
	printf("\n");
	printf("%s", get_next_line(fd));
	if (close(fd) != -1);
		return (0);
	return (0);
}
