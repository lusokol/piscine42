/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 17:41:38 by lusokol           #+#    #+#             */
/*   Updated: 2019/09/02 17:44:02 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_alpha_num(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
			|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

int		check_char(char cf, char cs)
{
	if (cs >= 'A' && cs <= 'Z')
	{
		if (is_alpha_num(cf))
			return (1);
	}
	else if (cs >= 'a' && cs <= 'z')
	{
		if (!is_alpha_num(cf))
			return (2);
	}
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int		i;

	i = 0;
	if (str[i] >= 'a' && str[i] <= 'z')
		str[i] -= 32;
	i++;
	while (str[i])
	{
		if (check_char(str[i - 1], str[i]) == 2)
			str[i] -= 32;
		else if (check_char(str[i - 1], str[i]) == 1)
			str[i] += 32;
		i++;
	}
	return (str);
}
