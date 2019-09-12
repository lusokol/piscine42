/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:14:17 by lusokol           #+#    #+#             */
/*   Updated: 2019/09/12 15:36:18 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *grid;

	if (!(grid = malloc(sizeof(*tab) * length)))
		return (NULL);
	i = 0;
	while (i < length)
	{
		grid[i] = (*f)(tab[i]);
		i++;
	}
	return (grid);
}
