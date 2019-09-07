/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 10:50:22 by lusokol           #+#    #+#             */
/*   Updated: 2019/09/05 11:04:17 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int		i;
	int		*tmp;

	tmp = NULL;
	if (min >= max)
	{
		*range = tmp;
		return (0);
	}
	if (!(tmp = malloc(sizeof(int) * (max - min))))
		return (-1);
	i = 0;
	while (i < max - min)
	{
		tmp[i] = min + i;
		i++;
	}
	*range = tmp;
	return (max - min);
}

int main()
{
	int **tab;
	int i = 0;
	int min = -15;
	int max = 10;

	printf("%i\n", ft_ultimate_range(tab, min, max));
	while (i < max - min)
	{
		printf("%i ", tab[0][i]);
		i++;
	}
}
