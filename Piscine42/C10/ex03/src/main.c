/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 15:02:02 by lusokol           #+#    #+#             */
/*   Updated: 2019/09/16 15:02:03 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgen.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include "ft_hexdump.h"
#include "ft_str.h"

int		g_total;

int		error(char *program, char *filename, char *message)
{
	char	formated[500];
	int		length;

	ft_strcpy(formated, basename(program));
	ft_strcat(formated, ": ");
	ft_strcat(formated, filename);
	ft_strcat(formated, ": ");
	if (!message)
		ft_strcat(formated, strerror(errno));
	else
		ft_strcat(formated, message);
	ft_strcat(formated, "\n");
	length = 0;
	while (formated[length])
		length++;
	write(2, formated, length);
	return (errno);
}

int		read_file(char *filename, t_buffer *buf, int c_op)
{
	int			ret;
	const int	file = open(filename, O_RDONLY);

	if (file < 0)
		return (-1);
	g_total++;
	while ((ret = read(file, buf->current + buf->bytes, (16 - buf->bytes))) > 0)
	{
		if (ret == 16 || buf->bytes + ret == 16)
		{
			buf->bytes = 16;
			display_buffer(buf, c_op);
			buf->bytes = 0;
		}
		else
			buf->bytes += ret;
		ft_ncpy(buf->previous, buf->current, 16);
		buf->total += ret;
	}
	close(file);
	return (ret);
}

int		read_stdin(t_buffer *buf, int c_op)
{
	int		ret;

	while ((ret = read(0, buf->current + buf->bytes, (16 - buf->bytes))) > 0)
	{
		if (ret == 16 || buf->bytes + ret == 16)
		{
			buf->bytes = 16;
			display_buffer(buf, c_op);
			buf->bytes = 0;
		}
		else
			buf->bytes += ret;
		ft_ncpy(buf->previous, buf->current, 16);
		buf->total += ret;
	}
	return (ret);
}

void	init_buffer(t_buffer *buffer)
{
	buffer->previous = malloc(sizeof(*buffer->previous) * 16);
	buffer->current = malloc(sizeof(*buffer->current) * 16);
	buffer->bytes = 0;
	buffer->total = 0;
}

int		main(int argc, char **argv)
{
	int			ret;
	int			c_op;
	int			i;
	t_buffer	buffer;

	init_buffer(&buffer);
	c_op = 0;
	g_total = 0;
	if (argc > 1 && ft_ncmp(argv[1], "-C", 2) == 0)
		c_op = 1;
	if ((argc == 2 && c_op) || (argc == 1 && c_op == 0))
		ret = read_stdin(&buffer, c_op);
	i = c_op;
	while (++i < argc)
		if (read_file(argv[i], &buffer, c_op) < 0)
			ret = error(argv[0], argv[i], NULL);
	if (buffer.bytes > 0)
		display_buffer(&buffer, c_op);
	if (buffer.total > 0)
		display_buffer(NULL, c_op);
	if (g_total == 0 && ((c_op && argc > 2) || (!c_op && argc > 1)))
		error(argv[0], argv[argc - 1], "Bad file descriptor");
	free(buffer.previous);
	free(buffer.current);
	return (ret);
}
