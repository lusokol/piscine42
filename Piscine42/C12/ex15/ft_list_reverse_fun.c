/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:18:58 by lusokol           #+#    #+#             */
/*   Updated: 2019/09/19 15:22:49 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;

	i = 0;
	if (!begin_list)
		return (NULL);
	while (i < nbr && begin_list->next != NULL)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (begin_list);
}

int		ft_list_size(t_list *begin_list)
{
	int		size;

	size = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		size++;
	}
	return (size);
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	int		i;
	int		j;
	void	*tmp;
	t_list	*end;

	i = 0;
	j = ft_list_size(begin_list);
	if (!begin_list || !begin_list->next)
		return ;
	while (i < j)
	{
		j--;
		end = ft_list_at(begin_list, j - i);
		tmp = end->data;
		end->data = begin_list->data;
		begin_list->data = tmp;
		i++;
		begin_list = begin_list->next;
	}
}
