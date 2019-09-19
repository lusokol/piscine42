/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 14:51:37 by lusokol           #+#    #+#             */
/*   Updated: 2019/09/16 14:52:08 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgen.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <stdio.h>
#include "ft_util.h"
#include "ft_error.h"

int	g_output;

int	g_total;

int		get_opt(int argc, char **argv)
{
	int		c_op;

	if (argc < 2)
		return (usage_info(argv[0]));
	else if (argc == 2 && ft_strcmp("-c", argv[1]) == 0)
		return (error_message(argv[0], "option requires an argument -- c\n"));
	else if (ft_strcmp("-c", argv[1]) != 0)
		return (usage_info(argv[0]));
	c_op = ft_atoi(argv[2]);
	if (c_op < 0)
		illegal_offset(argv[0], argv[2]);
	return (c_op);
}

int		header(char *filename, int number)
{
	char	formated[500];
	int		length;

	formated[0] = '\0';
	if (number > 0)
		ft_strcat(formated, "\n");
	ft_strcat(formated, "==> ");
	ft_strcat(formated, filename);
	ft_strcat(formated, " <==\n");
	length = 0;
	while (formated[length])
		length++;
	write(1, formated, length);
	return (g_output + 1);
}

int		read_file(char *filename, int c_op)
{
	char		*buffer;
	int			length;
	char		cbuf;
	int			ret;
	const int	file = open(filename, O_RDONLY);

	if (file < 0)
		return (-1);
	length = 0;
	buffer = malloc(sizeof(*buffer) * c_op);
	while ((ret = read(file, &cbuf, 1)) > 0)
		length = add_char_to_buffer(buffer, cbuf, length, c_op);
	if ((length >= 0 || ret == -1) && g_total > 1)
		g_output = header(filename, g_output);
	if (c_op > length)
		write(1, buffer, length);
	else
		write(1, (buffer + length - c_op), c_op);
	close(file);
	free(buffer);
	if (ret == -1 || ret >= 0)
		return (0);
	return (-1);
}

int		read_stdin(int c_op)
{
	char	*buffer;
	int		length;
	char	cbuf;
	int		ret;

	length = 0;
	buffer = malloc(sizeof(*buffer) * c_op + 1);
	ret = 0;
	while ((ret = read(0, &cbuf, 1)) > 0)
		length = add_char_to_buffer(buffer, cbuf, length, c_op);
	if (ret == 0 && length > 0)
		write(1, buffer, length);
	free(buffer);
	return (ret);
}

int		main(int argc, char **argv)
{
	int	ret;
	int	c_op;
	int	i;

	g_output = 0;
	g_total = argc - 3;
	ret = 0;
	c_op = get_opt(argc, argv);
	if (c_op < 0)
		return (1);
	if (argc == 3)
		ret = read_stdin(c_op);
	i = 3;
	while (i < argc)
	{
		if (read_file(argv[i], c_op) < 0)
			ret = error(argv[0], argv[i]);
		i++;
	}
	return (ret);
}
