/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 10:31:15 by lusokol           #+#    #+#             */
/*   Updated: 2019/09/05 10:50:02 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		calcul(int min, int max)
{
	if (min >= max)
		return (0);
	return (max - min);
}

int		*ft_range(int min, int max)
{
	int *tab;
	int i;

	tab = malloc(calcul(min, max) * sizeof(int) + 1);
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (min + i < max)
	{
		tab[i] = min + i;
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

int main()
{
	int *tab;
	int i = 0;
	int min = -15;
	int max = 36;

	tab = ft_range(min, max);
	while (i < max - min && calcul(min, max))
	{
		printf("%i ", tab[i]);
		i++;
	}
}
