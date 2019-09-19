/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:25:20 by lusokol           #+#    #+#             */
/*   Updated: 2019/09/19 15:25:46 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

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

void		ft_list_merged(t_list **begin_list1, t_list *begin_list2)
{
	t_list		*tmp;

	if (*begin_list1 == NULL)
		*begin_list1 = begin_list2;
	else
	{
		tmp = *begin_list1;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = begin_list2;
	}
}

void		ft_sorted_list_merge(t_list **begin_list1,
		t_list *begin_list2, int (*cmp)())
{
	ft_list_merged(begin_list1, begin_list2);
	ft_list_sorted(begin_list1, (*cmp));
}
