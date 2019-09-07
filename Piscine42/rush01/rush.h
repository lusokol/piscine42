/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 12:16:48 by lusokol           #+#    #+#             */
/*   Updated: 2019/09/07 12:41:56 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RUSH_H
# define FT_RUSH_H

int		check_grid(int pos, int n, int grid[6][6]);
void	print_grid(int n, int grid[6][6]);
int		check_left_right(int row, int n, int grid[6][6]);
int		check(int row, int col, int n, int grid[6][6]);
void	init_grid(char *str, int n, int grid[6][6]);
int		backtrack(int pos, int n, int grid[6][6]);

#endif
