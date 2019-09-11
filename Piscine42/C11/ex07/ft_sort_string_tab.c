/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 11:34:19 by lusokol           #+#    #+#             */
/*   Updated: 2019/09/11 12:48:17 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_swap(char **s1, char **s2)
{
	char *tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

int		ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	int		is_sorted;
	int		ac;

	ac = 0;
	while (tab[ac])
		ac++;
	is_sorted = 0;
	while (!is_sorted)
	{
		i = 1;
		is_sorted = 1;
		while (i < ac)
		{
			if ((*cmp)(tab[i - 1], tab[i]) > 0)
			{
				ft_swap(&tab[i - 1], &tab[i]);
				is_sorted = 0;
			}
			i++;
		}
		ac--;
	}
}