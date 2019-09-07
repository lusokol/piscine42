/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:54:33 by lusokol           #+#    #+#             */
/*   Updated: 2019/09/06 10:36:21 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		check_error(char *base);
int		ft_strlen(char *str);
char	*ft_putnbr_base(int nbr, char *base, int i, char *tab);
char	*ft_swaptab(char *tab);

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

int		check_base(char *base)
{
	int i;
	int j;

	i = 0;
	if (ft_strlen(base) < 2)
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

char	*ft_malloc(int nbr, char *base_to)
{
	int		i;
	int		nb;
	char	*tab;

	i = 0;
	nb = nbr;
	while (nb)
	{
		nb = nb / ft_strlen(base_to);
		i++;
	}
	tab = malloc(sizeof(char) * i + 2 * sizeof(char));
	return (ft_swaptab(ft_putnbr_base(nbr, base_to, 0, tab)));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int sign;
	int i;
	int j;
	int count;
	int nbr2;

	i = 0;
	nbr2 = 0;
	count = check_str(nbr, base_from);
	sign = 1;
	if (!(check_base(base_from)) || !(check_error(base_to)))
		return (NULL);
	while ((nbr[i] >= 9 && nbr[i] <= 13) || nbr[i] == ' ')
		i++;
	while (nbr[i] == '+' || nbr[i] == '-')
		sign = (nbr[i++] == '-') ? -sign : sign;
	while (--count >= 0 && check_base(base_from))
	{
		j = 0;
		while (nbr[i] != base_from[j])
			j++;
		nbr2 = nbr2 + (ft_recursive_power(ft_strlen(base_from), count) * j);
		i++;
	}
	return (ft_malloc(nbr2 * sign, base_to));
}
