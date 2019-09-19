/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 10:34:16 by lusokol           #+#    #+#             */
/*   Updated: 2019/09/19 13:40:31 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void		ft_list_remove_if(t_list **begin_list,
		void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list *prev;
	t_list *tmp;

		tmp = *begin_list;
	while (tmp && (*cmp)(tmp->data, data_ref) == 0)
	{
		*begin_list = tmp->next;
		(*free_fct)(tmp->data);
		free(tmp);
		tmp = *begin_list;
	}
	while (tmp)
	{
		while (tmp && (*cmp)(tmp->data, data_ref))
		{
			prev = tmp;
			tmp = tmp->next;
		}
		if (!tmp)
			return ;
		prev->next = tmp->next;
		(*free_fct)(tmp->data);
		free(tmp);
		tmp = prev->next;
	}
}
