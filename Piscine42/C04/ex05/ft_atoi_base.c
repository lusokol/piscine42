/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 12:14:54 by lusokol           #+#    #+#             */
/*   Updated: 2019/09/04 18:48:19 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	return (nb * ft_recursive_power(nb, power - 1));
}

int		ft_size(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		check_base(char *base)
{
	int i;
	int j;

	i = 0;
	if (ft_size(base) < 2)
		return (0);
	while (base[i])
	{
		if (base[i] == '\t' || base[i] == '\n' || base[i] == '\r' ||
				base[i] == '\v' || base[i] == '\f' || base[i] == ' ' ||
				base[i] == '-' || base[i] == '+')
			return (0);
		i++;
	}
	i = 0;
	while (base[i + 1])
	{
		j = i + 1;
		while (base[i] != base[j] && base[j] != '\0')
			j++;
		if (base[i] == base[j])
			return (0);
		i++;
	}
	return (1);
}

int		check_str(char *str, char *base)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
		i++;
	while (base[j])
	{
		j = 0;
		while (base[j] != str[i] && base[j] != '\0')
			j++;
		count = (base[j] == str[i] && str[i] != '\0') ? count + 1 : count;
		i++;
	}
	return (count);
}

int		ft_atoi_base(char *str, char *base)
{
	int sign;
	int i;
	int j;
	int count;
	int nbr;

	i = 0;
	nbr = 0;
	count = check_str(str, base);
	sign = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
		sign = (str[i++] == '-') ? -sign : sign;
	while (--count >= 0 && check_base(base))
	{
		j = 0;
		while (str[i] != base[j])
			j++;
		nbr = nbr + (ft_recursive_power(ft_size(base), count) * j);
		i++;
	}
	return (nbr * sign);
}
