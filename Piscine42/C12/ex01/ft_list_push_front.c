/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lusokol <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 11:19:48 by lusokol           #+#    #+#             */
/*   Updated: 2019/09/14 16:31:25 by lusokol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list nouveau;
   
	//*nouveau = malloc(sizeof(*nouveau));

	nouveau.data = data;
	nouveau.next = *begin_list;
	*begin_list = &nouveau;
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

	ft_list_push_front(&begin, 42);
	while (begin)
	{
		printf("%d\n", begin->data);
		begin = begin->next;
	}
}
