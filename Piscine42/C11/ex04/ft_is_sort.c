/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 13:01:42 by lusokol           #+#    #+#             */
/*   Updated: 2019/09/10 14:25:42 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int bon;
	int inv;
	int egal;

	i = -1;
	bon = 0;
	inv = 0;
	egal = 0;
	while (++i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) >= 0)
			inv++;
		if ((*f)(tab[i], tab[i + 1]) <= 0)
			bon++;
		if ((*f)(tab[i], tab[i + 1]) == 0)
			egal++;
	}
	if (egal == length - 1 || length <= 2)
		return (1);
	inv -= egal;
	bon -= egal;
	if ((inv != 0 && bon == 0) || (inv == 0 && bon != 0))
		return (1);
	return (0);
}
