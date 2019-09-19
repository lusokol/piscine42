/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 11:49:03 by lusokol           #+#    #+#             */
/*   Updated: 2019/09/18 20:28:30 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/all.h"

int		ft_read_syms(const char *filename)
{
	int			fd;
	int			i;
	char		*info;
	char		buffer[2];

	buffer[0] = 0;
	i = -1;
	info = malloc(sizeof(char) * 30);
	fd = open(filename, O_RDONLY);
	if (-1 == fd)
		return (-2);
	while ((read(fd, buffer, 1) > 0))
	{
		if (++i > 20)
			return (-1);
		else if (buffer[0] != '\n')
			info[i] = buffer[0];
		else
			break ;
	}
	info[i] = '\0';
	g_map_info = save_info(info);
	g_map_info->fd = fd;
	free(info);
	return (1);
}

int		ft_read_syms_from_input(char **input)
{
	int			i;
	char		*info;

	i = 0;
	info = malloc(sizeof(char) * 30);
	if (!input)
		return (-1);
	while (**input)
	{
		if (i > 20)
			return (-1);
		else if (**input != '\n')
			info[i] = **input;
		else
		{
			(*input)++;
			break ;
		}
		i++;
		(*input)++;
	}
	info[i] = '\0';
	g_map_info = save_info(info);
	free(info);
	return (1);
}

char	*read_from_input(void)
{
	char	buffer[2];
	int		flag;
	int		total_size;
	char	*str;

	buffer[1] = '\0';
	total_size = 0;
	str = malloc(sizeof(char) * 1009000);
	flag = 0;
	while ((flag = read(0, buffer, 1)) > 0)
	{
		total_size += flag;
		ft_strcat(str, buffer);
	}
	return (str);
}

int		ft_validate_argv(const char *filename, char *input)
{
	int test;

	if (input == 0)
	{
		if ((test = ft_read_syms(filename)) == -1)
			return (-1);
		else if (test == -2)
			return (-2);
	}
	else
		if (ft_read_syms_from_input(&input) == -1)
			return (-1);
	if (g_map_info->size < 0)
		return (-1);
	if (g_map_info->full == g_map_info->empty || g_map_info->full ==
			g_map_info->obstacle || g_map_info->empty == g_map_info->obstacle)
		return (-1);
	g_sqr = malloc(sizeof(t_biggest));
	g_sqr->row = 0;
	g_sqr->col = -1;
	g_sqr->d = 0;
	if (map_reader(g_map_info->fd, input) == -1)
		return (-1);
	print_t_map(g_map_info->int_map);
	free_everything();
	return (1);
}

int		main(int argc, char **argv)
{
	int		i;
	char	*ptr;
	int		j;

	i = 1;
	while (i < argc)
	{
		main_helper(i);
		if ((j = ft_validate_argv(argv[i], 0)) == -1)
			ft_putstr("map error\n");
		else if (j == -2)
			ft_putstr("Error\n");
		i++;
	}
	if (i == 1)
	{
		main_helper(i);
		ptr = read_from_input();
		i = 0;
		while (ptr[i] != '\n' && ptr[i] != '\0')
			i++;
		if (i < 4)
		{
			ft_putstr("map error\n");
			return (0);
		}
		if (ft_validate_argv((const char *)(0), ptr) == -1)
			ft_putstr("map error\n");
	}
	return (0);
}
