/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 10:29:49 by lusokol           #+#    #+#             */
/*   Updated: 2019/09/07 12:26:26 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		check_row(int row, int col, int n, int grid[6][6])
{
	int		i;

	i = 1;
	while (i <= n)
	{
		if (grid[row][i] == grid[row][col] && i != col)
			return (0);
		i++;
	}
	return (1);
}

int		check_col(int row, int col, int n, int grid[6][6])
{
	int		i;

	i = 1;
	while (i <= n)
	{
		if (grid[i][col] == grid[row][col] && i != row)
			return (0);
		i++;
	}
	return (1);
}

int		check_grid(int pos, int n, int grid[6][6])
{
	int		row;
	int		col;

	col = pos % n ? pos % n : n;
	row = pos % n ? pos / n + 1 : pos / n;
	if (!check_row(row, col, n, grid))
		return (0);
	if (!check_col(row, col, n, grid))
		return (0);
	if (!check(row, col, n, grid))
		return (0);
	return (1);
}
