/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:53:33 by lusokol           #+#    #+#             */
/*   Updated: 2019/09/06 10:35:26 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void			ft_putchar(char c)
{
	write(1, &c, 1);
}

unsigned int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char			*ft_swaptab(char *tab)
{
	int		i;
	char	tmp;
	int		size;

	size = ft_strlen(tab);
	i = 0;
	while (i < size / 2 && size >= 1)
	{
		tmp = tab[i];
		tab[i] = tab[size - i - 1];
		tab[size - i - 1] = tmp;
		i++;
	}
	return (tab);
}

int				check_error(char *base)
{
	int		i;
	int		j;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

char			*ft_putnbr_base(int nbr, char *base, int i, char *tab)
{
	unsigned int	nb;

	if (!check_error(base))
		return (0);
	if (nbr < 0)
	{
		ft_putchar('-');
		nb = -(unsigned int)nbr;
	}
	else
		nb = nbr;
	if (nb < ft_strlen(base))
	{
		tab[i] = (base[nb]);
		i++;
		tab[i] = '\0';
	}
	else
	{
		tab[i] = base[nb % ft_strlen(base)];
		ft_putnbr_base(nb / ft_strlen(base), base, ++i, tab);
	}
	return (tab);
}
