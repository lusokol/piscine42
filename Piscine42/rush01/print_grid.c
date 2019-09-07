/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 10:31:00 by lusokol           #+#    #+#             */
/*   Updated: 2019/09/07 12:27:09 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rush.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_grid(int n, int grid[6][6])
{
	int		i;
	int		j;

	j = 1;
	while (j <= n)
	{
		i = 1;
		while (i <= n)
		{
			ft_putchar(grid[j][i] + '0');
			if (i != n)
				ft_putchar(' ');
			i++;
		}
		ft_putchar('\n');
		j++;
	}
}
