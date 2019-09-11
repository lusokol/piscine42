/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operateurs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:43:27 by lusokol           #+#    #+#             */
/*   Updated: 2019/09/11 11:20:07 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dooph.h"
#include <unistd.h>

void	ft_plus(int nb1, int nb2)
{
	int res;

	res = nb1 + nb2;
	ft_putnbr(res);
}

void	ft_moins(int nb1, int nb2)
{
	int res;

	res = nb1 - nb2;
	ft_putnbr(res);
}

void	ft_mult(int nb1, int nb2)
{
	int res;

	res = nb1 * nb2;
	ft_putnbr(res);
}

void	ft_div(int nb1, int nb2)
{
	int res;

	if (nb2 == 0)
	{
		write(1, "Stop : division by zero", 23);
		return ;
	}
	res = nb1 / nb2;
	ft_putnbr(res);
}

void	ft_mod(int nb1, int nb2)
{
	int res;

	if (nb2 == 0)
	{
		write(1, "Stop : modulo by zero", 21);
		return ;
	}
	res = nb1 % nb2;
	ft_putnbr(res);
}
