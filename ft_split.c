/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isel-azz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 07:45:39 by isel-azz          #+#    #+#             */
/*   Updated: 2024/05/11 07:45:41 by isel-azz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

void	ending(int *start, int *end, int c, const char *s)
{
	while (s[*start] == c && s[*start] != '\0')
		*start += 1;
	*end = *start;
	while (s [*end] != c && s[*end] != '\0')
		*end += 1;
}

char	**freesplit(char **res, int i)
{
	if (res[i] == NULL)
	{
		while (i > 0)
			free(res[--i]);
		free(res);
	}
	return (NULL);
}

void	fill(int start, int end, const char *s, char *res)
{
	int	i;

	i = 0;
	while (start < end)
		res[i++] = s[start++];
	res[i] = '\0';
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	int		start;
	int		end;
	int		i;

	if (!s)
		return (NULL);
	res = (char **) malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	start = 0;
	end = 0;
	i = 0;
	while (i < count_words(s, c))
	{
		ending(&start, &end, c, s);
		res[i] = (char *) malloc((end - start + 1) * sizeof(char));
		if (!res[i])
			return (freesplit(res, i));
		fill(start, end, s, res[i]);
		start = end;
		i++;
	}
	res[i] = NULL;
	return (res);
}
