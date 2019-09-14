/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 15:01:05 by lusokol           #+#    #+#             */
/*   Updated: 2019/09/14 16:31:29 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_push_back(t_list **begin_list, void *data)
{
	struct s_list	ajout;

	//ajout = malloc(sizeof(t_list));
	while (begin_list)
	{
		begin_list = begin_list->next;
	}
	begin_list->next = ajout;
	ajout.data = data;
	ajout.next = 0;
}

int main()
{
	struct s_list	elem1;
	struct s_list	elem2;
	struct s_list	elem3;
	struct s_list	elem4;
	struct s_list	*begin;

	begin = &elem1;
	elem1.next = &elem2;
	elem2.next = &elem3;
	elem3.next = &elem4;
	elem4.next = 0;

	elem1.data = 5;
	elem2.data = 10;
	elem3.data = 25;
	elem4.data = 35;

	ft_list_push_back(&begin, 42);
	while (begin)
	{
		printf("%d\n", begin->data);
		begin = begin->next;
	}
}
