/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 10:50:00 by lusokol           #+#    #+#             */
/*   Updated: 2019/09/08 13:06:22 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int				ft_charset(char c, char *charset)
{
	int			i;

	i = 0;
	while (c != charset[i] && charset[i] != '\0')
		i++;
	if (charset[i] != '\0')
		return (0);
	return (1);
}

int				ft_taillem(char *str, int i, char *charset)
{
	int			j;

	j = 0;
	while (ft_charset(str[i], charset) && str[i] != '\0')
	{
		i++;
		j++;
	}
	return (j);
}

int				ft_nbr_mots(char *str, char *charset)
{
	int			i;
	int			nbr_mots;

	i = 0;
	nbr_mots = 0;
	while (str[i] && charset[0])
	{
		while (ft_charset(str[i], charset) == 0)
			i++;
		if (str[i])
			nbr_mots++;
		while (ft_charset(str[i], charset) == 1 && str[i] != '\0')
			i++;
	}
	if (!(charset[0]))
		return (1);
	return (nbr_mots);
}

char			**ft_split(char *str, char *charset)
{
	int			is;
	int			i;
	int			j;
	char		**tab;

	is = 0;
	i = 0;
	if (!(tab = malloc(sizeof(char*) * (ft_nbr_mots(str, charset) + 1))))
		return (0);
	while (i < ft_nbr_mots(str, charset) && str[0] != '\0')
	{
		j = 0;
		while (ft_charset(str[is], charset) == 0 && str[is])
			is++;
		if (!(tab[i] = malloc(sizeof(char) * ft_taillem(str, is, charset) + 1)))
			return (0);
		while (ft_charset(str[is], charset) == 1 && str[is])
			tab[i][j++] = str[is++];
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = 0;
	return (tab);
}
