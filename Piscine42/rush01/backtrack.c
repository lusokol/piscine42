/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 10:28:51 by lusokol           #+#    #+#             */
/*   Updated: 2019/09/07 12:25:25 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		backtrack(int pos, int n, int grid[6][6])
{
	int		row;
	int		col;
	int		val;

	col = pos % n ? pos % n : n;
	row = pos % n ? pos / n + 1 : pos / n;
	val = 0;
	if (pos == n * n + 1)
	{
		print_grid(n, grid);
		return (1);
	}
	else
	{
		val = 0;
		while (++val <= n)
		{
			grid[row][col] = val;
			if (check_grid(pos, n, grid))
				if (backtrack(pos + 1, n, grid))
					return (1);
		}
		grid[row][col] = 0;
		return (0);
	}
}
