/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:17:35 by lusokol           #+#    #+#             */
/*   Updated: 2019/09/04 15:31:16 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char	tmp;
	unsigned char	*tab;
	char			*hex;

	hex = "0123456789abcdef";
	tab = (unsigned char*)str;
	while (*tab != '\0')
	{
		if (*tab >= ' ' && *tab <= '~')
			write(1, tab, 1);
		else
		{
			ft_putchar('\\');
			tmp = *tab / 16;
			ft_putchar(hex[tmp]);
			tmp = *tab % 16;
			ft_putchar(hex[tmp]);
		}
		tab++;
	}
}
