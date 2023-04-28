/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:11:24 by tbatteux          #+#    #+#             */
/*   Updated: 2023/04/28 15:53:41 by tbatteux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*final;
	int		i;

	i = 0;
	while (s[i])
		i++;
	final = malloc ((i + 1) * sizeof(char));
	if (!final)
		return (NULL);
	i = 0;
	while (s[i])
	{
		final[i] = s[i];
		i++;
	}
	final[i] = 0;
	return (final);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	int		j;
	char	*final;

	final = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!final)
		return (NULL);
	j = -1;
	while (s1[++j])
		final[j] = s1[j];
	j = -1;
	while (s2[++j])
		final[ft_strlen(s1) + j] = s2[j];
	final[ft_strlen(s1) + j] = 0;
	return (final);
}
