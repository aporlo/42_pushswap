/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <lsomrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 03:40:07 by lsomrat           #+#    #+#             */
/*   Updated: 2022/10/09 03:40:11 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	is_sorted(t_list **list)
{
	t_list	*head;
	t_list	*temp;

	head = *list;
	temp = head->next;
	if (head->data > head->next->data)
		return (0);
	while (temp->next != head)
	{
		if (temp->data > temp->next->data)
			return (0);
		temp = temp->next;
	}
	return (1);
}
