/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 10:41:42 by lusokol           #+#    #+#             */
/*   Updated: 2019/09/04 15:39:56 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_putchar(char c)
{
	write(1, &c, 1);
}

void    ft_putstr_imp(char *str, int size)
{
	int        i;

	i = 0;
	while (i < 16 && size > 0)
	{
		if (str[i] >= 32 && str[i] < 127)
			ft_putchar(str[i]);
		else
			ft_putchar('.');
		i++;
		size--;
	}

}

void    ft_putnbr_hexa(long int nb, int i)
{
	char    *base;

	base = "0123456789abcdef";
	if (nb < 0)
		nb = -nb;
	if (i > 0)
		ft_putnbr_hexa(nb / 16, --i);
	ft_putchar(base[nb % 16]);
}

void    ft_putstr_hexa(char *str, unsigned int i, unsigned int size)
{
	unsigned int    j;
	j = 0;
	while (j < 16)
	{
		if (i + j < size)
		{
			ft_putnbr_hexa(str[j], 1);
		}
		else
		{
			ft_putchar(' ');
			ft_putchar(' ');
		}
		if (j % 2)
			ft_putchar(' ');
		j++;
	}
}

void    *ft_print_memory(void *addr, unsigned int size)
{
	char            *addr_str;
	unsigned int        i;

	addr_str = (char*)addr;
	i = 0;
	while (i < size)
	{
		ft_putnbr_hexa((long int)addr, 15);
		ft_putchar(':');
		ft_putchar(' ');
		ft_putstr_hexa((char*)addr, i, size);
		ft_putstr_imp(addr_str, (size - i));
		ft_putchar('\n');
		i += 16;
		addr_str += 16;
		addr += 16;
	}
	return (addr);
}
