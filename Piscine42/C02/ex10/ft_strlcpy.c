/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 17:54:06 by lusokol           #+#    #+#             */
/*   Updated: 2019/09/02 17:56:48 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (src[j] != '\0')
		j++;
	while (i < size)
	{
		if ((i < size - 1) && (src[i] != '\0'))
			dest[i] = src[i];
		else
		{
			dest[i] = '\0';
			return (j);
		}
		i++;
	}
	return (j);
}
