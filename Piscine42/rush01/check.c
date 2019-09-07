/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 10:29:18 by lusokol           #+#    #+#             */
/*   Updated: 2019/09/07 12:26:12 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int		check_left_right(int row, int n, int grid[6][6])
{
	int		i;
	int		count;
	int		view;
	int		max;

	i = 1;
	count = 0;
	view = 0;
	max = grid[row][0];
	while (i <= n)
	{
		if (grid[row][i] > count)
		{
			count = grid[row][i];
			view += 1;
			if (view > max)
				return (0);
		}
		i++;
	}
	if (grid[row][n] != 0 && view != max)
		return (0);
	return (1);
}

int		check_right_left(int row, int n, int grid[6][6])
{
	int		i;
	int		count;
	int		view;
	int		max;

	i = n;
	count = 0;
	view = 0;
	max = grid[row][n + 1];
	while (i >= 1)
	{
		if (grid[row][i] > count)
		{
			count = grid[row][i];
			view += 1;
			if (view > max && grid[row][n] != 0)
				return (0);
		}
		i--;
	}
	if (grid[row][n] != 0 && view != max)
		return (0);
	return (1);
}

int		check_up_down(int col, int row, int n, int grid[6][6])
{
	int		i;
	int		count;
	int		view;
	int		max;

	i = 1;
	count = 0;
	view = 0;
	max = grid[0][col];
	while (i <= row)
	{
		if (grid[i][col] > count)
		{
			count = grid[i][col];
			view += 1;
			if (view > max)
				return (0);
		}
		i++;
	}
	if (grid[n][col] != 0 && view != max)
		return (0);
	return (1);
}

int		check_down_up(int col, int n, int grid[6][6])
{
	int		i;
	int		count;
	int		view;
	int		max;

	i = n;
	count = 0;
	view = 0;
	max = grid[n + 1][col];
	while (i >= 1)
	{
		if (grid[i][col] > count)
		{
			count = grid[i][col];
			view += 1;
			if (view > max && grid[n][col] != 0)
				return (0);
		}
		i--;
	}
	if (grid[n][col] != 0 && view != max)
		return (0);
	return (1);
}

int		check(int row, int col, int n, int grid[6][6])
{
	if (check_left_right(row, n, grid) && check_right_left(row, n, grid)
			&& check_up_down(col, row, n, grid) && check_down_up(col, n, grid))
		return (1);
	return (0);
}
