/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 09:58:29 by tbatteux          #+#    #+#             */
/*   Updated: 2023/04/26 16:58:25 by tbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	is_valid(char *str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			j++;
		i++;
	}
	if (j == 0)
		return (1);
	return (0);
}
char	*recup_reste(char *lu)
{
	char	*reste;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (is_valid(lu) == 0)
	{
		while (lu[i] != '\n')
			i++;
		i++;
		while (lu[i])
			reste[j++] = lu[i++];
	}
	else
		while (lu[i])
			reste[j++] = lu[i++];
	reste[j] = 0;
	return (reste);
}

char	*recup_ligne(char *lu, int ret, int fd)
{
	char	*relire;
	char	*ligne;
	int		i;

	i = 0;
	if (is_valid(lu) == 1 && ret < BUFFER_SIZE)
		return (lu);
	while (is_valid(lu) == 1 && ret == BUFFER_SIZE)
	{
		relire = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!relire)
			return (NULL);
		ret = read(fd, relire, BUFFER_SIZE);
		lu = ft_strjoin(lu, relire);
		free(relire);
	}
	while (lu[i - 1] != '\n')
	{
		ligne[i] = lu[i];
		i++;
	}
	ligne[i] = 0;
	free(lu);
	return (ligne);
}

char	*get_next_line(int fd)
{
	char	*lu;
	int		ret;
	static char	*reste = NULL;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (reste == NULL)
	{
		reste = malloc(sizeof(char *));
		if (!reste)
			return (NULL);
		reste[0] = 0;
	}
	lu = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!lu)
		return (NULL);
	ret = read(fd, lu, BUFFER_SIZE);
	lu = ft_strjoin(reste, lu);
	printf("%s\n", reste);
	reste = recup_reste(lu);
	printf("reste :%s\n", reste);
	lu = recup_ligne(lu, ret, fd);
	printf("fonction ligne \n");
	printf("reste :%s\n", reste);
	return (lu);
}

int	main()
{
	int	fd;

	fd = open("texte.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	get_next_line(fd);
	printf("\n\n\n");
	get_next_line(fd);
	if (close(fd) != -1);
		return (0);
	return (0);
}
