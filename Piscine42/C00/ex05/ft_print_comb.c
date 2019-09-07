/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:08:41 by lusokol           #+#    #+#             */
/*   Updated: 2019/09/02 13:42:13 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb(void)
{
	char	first;
	char	second;
	char	third;

	first = '0' - 1;
	third = '2' - 1;
	while (++first <= '7')
	{
		second = first;
		while (++second <= '8')
		{
			third = second;
			while (++third <= '9')
			{
				ft_putchar(first);
				ft_putchar(second);
				ft_putchar(third);
				if (first != '7')
					write(1, ", ", 2);
			}
		}
	}
}
