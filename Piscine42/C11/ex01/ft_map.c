/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 12:14:17 by lusokol           #+#    #+#             */
/*   Updated: 2019/09/10 14:19:05 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_map(int *tab, int length, void (*f)(int))
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
}
