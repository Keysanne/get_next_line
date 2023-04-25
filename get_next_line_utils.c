/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbatteux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 09:59:15 by tbatteux          #+#    #+#             */
/*   Updated: 2023/04/25 10:02:45 by tbatteux         ###   ########.fr       */
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

char	*ft_strjoin(char const *s1, char const *s2)
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
