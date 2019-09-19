/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:01:05 by lusokol           #+#    #+#             */
/*   Updated: 2019/09/18 15:07:04 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	struct s_list	*ajout;
	struct s_list	*debut;

	debut = (*begin_list);
	ajout = ft_create_elem(data); 
	while ((*begin_list)->next)
		(*begin_list) = (*begin_list)->next;
	(*begin_list)->next = ajout;
	ajout->data = data;
	ajout->next = 0;
	(*begin_list) = debut;
}
