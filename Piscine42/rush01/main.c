/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 10:30:36 by lusokol           #+#    #+#             */
/*   Updated: 2019/09/07 12:41:43 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "rush.h"

int		main(int argc, char **argv)
{
	int		grid[6][6];
	int		n;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	n = 4;
	init_grid(argv[1], n, grid);
	if (!backtrack(1, n, grid))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (0);
}
