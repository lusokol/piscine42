/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:23:51 by lusokol           #+#    #+#             */
/*   Updated: 2019/09/19 15:24:32 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_list_push_fronted(t_list **begin_list, void *data)
{
	t_list	*temp;

	temp = *begin_list;
	if (!temp)
		*begin_list = ft_create_elem(data);
	else
	{
		temp = ft_create_elem(data);
		temp->next = *begin_list;
		*begin_list = temp;
	}
}

void		ft_list_sorted(t_list **begin_list, int (*cmp)())
{
	t_list		*curr;
	t_list		*next;
	void		*tmp;

	curr = *begin_list;
	if (curr == NULL || curr->next == NULL)
		return ;
	while (curr->next)
	{
		next = curr->next;
		if ((*cmp)(curr->data, next->data) > 0)
		{
			tmp = curr->data;
			curr->data = next->data;
			next->data = tmp;
			curr = *begin_list;
		}
		else
			curr = curr->next;
	}
}

void		ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	ft_list_push_fronted(begin_list, data);
	ft_list_sorted(begin_list, (*cmp));
}
