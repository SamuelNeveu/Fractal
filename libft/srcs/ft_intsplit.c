/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saneveu <saneveu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 12:58:57 by saneveu           #+#    #+#             */
/*   Updated: 2019/04/12 18:09:16 by saneveu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		in_carset(char const *set, char c)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int		ct(const char *str, const char *set)
{
	int len;
	int i;

	len = 0;
	i = 0;
	while (str[i])
	{
		while (in_carset(set, str[i]))
			i++;
		if (str[i])
			len++;
		while (str[i] && !in_carset(set, str[i]))
			i++;
	}
	return (len);
}

int				*ft_intsplit(const char *str, const char *set)
{
	int i;
	int x;
	int *tab;

	if (!(tab = (int *)malloc(sizeof(int) * ct(str, set))))
		return (0);
	x = 0;
	i = 0;
	while (str[i])
	{
		while (in_carset(set, str[i]))
			i++;
		if (str[i])
		{
			tab[x++] = ft_atoi(str + i);
			while (str[i] && !in_carset(set, str[i]))
				i++;
		}
	}
	return (tab);
}
