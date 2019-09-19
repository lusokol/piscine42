/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 11:53:02 by lusokol           #+#    #+#             */
/*   Updated: 2019/09/19 10:32:28 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int i;

	i = 0;
	while (begin_list && i <= nbr)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (begin_list);
}

void	ft_list_reverse(t_list **begin_list)
{
	t_list *current;
	t_list *previous;
	t_list *tmp;

	previous = 0;
	current = *begin_list;
	while (current)
	{
		tmp = current->next;
		current->next = previous;
		previous = current;
		current = tmp;
	}
	(*begin_list) = previous;
}
