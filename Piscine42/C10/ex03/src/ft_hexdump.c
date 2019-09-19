/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:00:45 by lusokol           #+#    #+#             */
/*   Updated: 2019/09/16 15:00:50 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgen.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "ft_hexdump.h"
#include "ft_str.h"

int		write_hex(int size, int nbr)
{
	char	*str;
	int		i;

	str = malloc(sizeof(*str) * size + 1);
	i = 0;
	while (i < size)
		str[i++] = '0';
	i = size - 1;
	while (nbr > 0)
	{
		str[i] = ((nbr % 16 > 9) ? 'a' - 10 : '0') + (nbr % 16);
		nbr /= 16;
		i--;
	}
	write(1, str, size);
	free(str);
	return (1);
}

int		write_chars(char *buffer, int bytes)
{
	int	i;

	i = 0;
	write(1, "|", 1);
	while (i < bytes)
	{
		if (buffer[i] < ' ' || buffer[i] > 127)
			write(1, ".", 1);
		else
			write(1, &buffer[i], 1);
		i++;
	}
	write(1, "|", 1);
	return (1);
}

int		write_chars_hex(char *buffer, int c_op, int bytes)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (i >= bytes)
			write(1, "  ", 2);
		else
			write_hex(2, buffer[i]);
		if (i < 15)
			write(1, "  ", (c_op && i == 7) ? 2 : 1);
		i++;
	}
	return (1);
}

void	clean_buffer(t_buffer *buffer)
{
	int	i;

	i = buffer->bytes;
	while (i < 16)
	{
		buffer->current[i] = '\0';
		i++;
	}
}

void	display_buffer(t_buffer *buf, int c_op)
{
	static int	start;
	static int	same;

	if (buf == NULL)
		if (write_hex((c_op) ? 8 : 7, start) &&
			((write(1, "\n", 1)) ? 1 : 1))
			return ;
	if (buf->previous[0] != '\0' &&
		buf->bytes == 16 &&
		ft_ncmp(buf->previous, buf->current, 16) == 0)
	{
		if (!same && (same = 1))
			write(1, "*\n", 2);
	}
	else
	{
		write_hex((c_op) ? 8 : 7, start);
		write(1, "  ", (c_op) ? 2 : 1);
		write_chars_hex(buf->current, c_op, buf->bytes);
		if (c_op)
			write(1, "  ", 2) && write_chars(buf->current, buf->bytes);
		same = write(1, "\n", 1) - 1;
	}
	start += buf->bytes;
}
