/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factiorial.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 12:52:38 by lusokol           #+#    #+#             */
/*   Updated: 2019/09/03 12:56:24 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int		i;
	int		result;

	if (nb < 0)
		return (0);
	i = 0;
	result = 1;
	while (i++ < nb)
		result = result * i;
	return (result);
}
