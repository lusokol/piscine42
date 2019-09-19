/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:03:35 by lusokol           #+#    #+#             */
/*   Updated: 2019/09/18 16:31:31 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*liste;
	t_list	*address;

	liste = ft_create_elem(strs[size - 1]);
	address = liste;
	while (size)
	{
		liste->data = strs[size - 1];
		if (size - 1)
			liste->next = ft_create_elem(strs[size - 1]);
		else
			liste->next = 0;
		size--;
		liste = liste->next;
	}
	return (address);
}
