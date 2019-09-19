/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 14:48:51 by lusokol           #+#    #+#             */
/*   Updated: 2019/09/16 14:50:16 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_util.h"

char	*ft_strcpy(char *dest, char *src)
{
	unsigned int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strcat(char *dest, char *src)
{
	unsigned int i;
	unsigned int j;

	j = 0;
	while (dest[j] != '\0')
		j++;
	i = 0;
	while (src[i] != '\0')
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

int		ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;
	int				state;

	i = 0;
	state = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && state == 0)
	{
		state = (unsigned char)s1[i] - (unsigned char)s2[i];
		i++;
	}
	if (state == 0)
		state = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (state);
}

int		add_char_to_buffer(char *buffer, char cbuf, int length, int limit)
{
	int	i;

	if (limit == 0)
		return (0);
	if (length == limit)
	{
		i = 0;
		while (i < length - 1)
		{
			buffer[i] = buffer[i + 1];
			i++;
		}
		buffer[length - 1] = cbuf;
		return (length);
	}
	buffer[length] = cbuf;
	return (length + 1);
}

int		ft_atoi(char *str)
{
	long	result;
	int		i;

	result = 0;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
		str[i] == '\f' || str[i] == '\r' || str[i] == '\v')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result *= 10;
			result += (str[i] - '0');
		}
		else
			return (-1);
		i++;
	}
	return (result);
}
