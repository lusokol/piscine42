/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:27:21 by lusokol           #+#    #+#             */
/*   Updated: 2019/09/11 11:19:25 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dooph.h"
#include <unistd.h>

int		ft_atoi(char *str)
{
	int i;
	int sign;
	int nbr;

	nbr = 0;
	sign = 1;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		sign = (str[i] == '-') ? -sign : sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}

void	ft_find_op(char a, int nb1, int nb2)
{
	void	(*op)(int, int);

	if (a == '+')
		op = &ft_plus;
	else if (a == '-')
		op = &ft_moins;
	else if (a == '/')
		op = &ft_div;
	else if (a == '*')
		op = &ft_mult;
	else if (a == '%')
		op = &ft_mod;
	else
	{
		ft_putnbr(0);
		return ;
	}
	(*op)(nb1, nb2);
}

int		main(int ac, char **av)
{
	int nbr1;
	int nbr2;

	if (ac != 4)
		return (0);
	nbr1 = ft_atoi(av[1]);
	nbr2 = ft_atoi(av[3]);
	ft_find_op(av[2][0], nbr1, nbr2);
	write(1, "\n", 1);
	return (0);
}
