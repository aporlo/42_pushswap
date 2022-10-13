/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <lsomrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 22:37:40 by lsomrat           #+#    #+#             */
/*   Updated: 2022/10/07 22:40:58 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	to_push(t_list **head, char stack_name, long int data)
{
	t_list	*temp;

	(void)stack_name;
	if (*head)
	{
		temp = (t_list *)malloc(sizeof(t_list));
		if (!temp)
			error(*head);
		temp->next = *head;
		temp->prev = (*head)->prev;
		(*head)->prev = temp;
		temp->prev->next = temp;
		temp->data = data;
		*head = (*head)->prev;
	}
	else
	{
		*head = (t_list *)malloc(sizeof(t_list));
		if (!head)
			error(*head);
		(*head)->next = *head;
		(*head)->prev = *head;
		(*head)->data = data;
	}
}
