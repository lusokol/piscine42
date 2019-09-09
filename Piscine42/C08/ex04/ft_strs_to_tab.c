/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 11:33:08 by lusokol           #+#    #+#             */
/*   Updated: 2019/09/09 11:50:23 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int						ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char					*ft_strdup(char *src)
{
	char	*duplicate;
	int		i;

	duplicate = NULL;
	duplicate = (char*)malloc(sizeof(*duplicate) * (ft_strlen(src) + 1));
	if (!duplicate)
		return (NULL);
	i = -1;
	while (src[++i])
		duplicate[i] = src[i];
	duplicate[i] = '\0';
	return (duplicate);
}

struct s_stock_str		*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str		*par;
	int				i;

	if (!(par = (t_stock_str*)malloc(sizeof(*par) * (ac + 1))))
		return (NULL);
	i = 0;
	while (i < ac)
	{
		par[i].size = ft_strlen(av[i]);
		par[i].str = av[i];
		par[i].copy = ft_strdup(av[i]);
		i++;
	}
	par[ac].str = 0;
	return (par);
}
