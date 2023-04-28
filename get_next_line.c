/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:11:24 by tbatteux          #+#    #+#             */
/*   Updated: 2023/04/28 15:54:03 by tbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int	is_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i++])
		if (str[i] == '\n')
			return (0);
	return (1);
}

char	*recup_reste(char *lu)
{
	char	*reste;
	int		i;

	i = 0;
	if (is_valid(lu) == 0)
	{
		while (lu[i] != '\n' && lu[i])
			i++;
		reste = ft_strdup(&lu[i + 1]);
		return (reste);
	}
	else
		return ("");
}

char	*recup_ligne(char *lu, int ret, int fd)
{
	char	*relire;
	char	*ligne;
	int		i;

	if (is_valid(lu) == 1 && ret < BUFFER_SIZE)
		return (lu);
	while (is_valid(lu) == 1 && ret == BUFFER_SIZE)
	{
		relire = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!relire)
			return (NULL);
		ret = read(fd, relire, BUFFER_SIZE);
		relire[ret] = 0;
		lu = ft_strjoin(lu, relire);
		free(relire);
	}
	ligne = ft_strdup(lu);
	i = 0;
	while (ligne[i] != '\n' && ligne[i])
		i++;
	ligne[i + 1] = 0;
	free(lu);
	return (ligne);
}

char	*get_next_line(int fd)
{
	char		*lu;
	char		*ligne;
	static char	*reste = NULL;
	int			ret;

	lu = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!lu)
		return (NULL);
	ret = read(fd, lu, BUFFER_SIZE);
	lu[ret] = 0;
	if (ret == -1 || fd < 0 || BUFFER_SIZE < 1)
	{
		free(lu);
		return (NULL);
	}
	if (reste == NULL)
		ligne = ft_strdup(lu);
	else
		ligne = ft_strjoin(reste, lu);
	free(lu);
	reste = recup_reste(ligne);
	lu = recup_ligne(ligne, ret, fd);
	return (lu);
}

int	main(void)
{
	int		fd;
	char	*recup;

	fd = open("texte.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	recup = get_next_line(fd);
	printf("%s", recup);
	recup = get_next_line(fd);
	printf("%s", recup);
	recup = get_next_line(fd);
	printf("%s", recup);
	recup = get_next_line(fd);
	printf("%s", recup);
	recup = get_next_line(fd);
	printf("%s", recup);
         free(recup);
	if (close(fd) != -1)
		return (0);
	return (0);
}
