/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sokaraku <sokaraku@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 17:59:28 by sokaraku          #+#    #+#             */
/*   Updated: 2023/11/20 16:19:52 by sokaraku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_cut(char const *s, char c, size_t *pos)
{
	size_t	i;
	size_t	first_pos;
	char	*str;

	i = 0;
	while (s[*pos] == c && s[*pos])
		(*pos)++;
	first_pos = *pos;
	while (s[*pos] != c && s[*pos])
		(*pos)++;
	str = (char *)malloc((*pos - first_pos + 1) * sizeof(char));
	if (!str)
		return (str);
	while (first_pos + i < *pos)
	{
		str[i] = s[first_pos + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (s[0] != c && s[0])
		count++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1])
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	words;
	size_t	pos;
	size_t	i;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	tab = ft_calloc(words + 1, sizeof(char *));
	pos = 0;
	i = 0;
	if (!tab)
		return (NULL);
	while (i < words)
		tab[i++] = ft_cut(s, c, &pos);
	tab[words] = NULL;
	return (tab);
}
