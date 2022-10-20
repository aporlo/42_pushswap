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

t_list	*stack_last(t_list *list)
{
	int	len;

	len = stack_len(list);
	while (--len && len >= 0)
	{
		list = list->next;
	}
	return (list);
}

void	to_push(t_list **from_stack, t_list **to_stack)
{
	t_list	*head;
	t_list	*last;

	if (!*from_stack)
		return ;
	head = *from_stack;
	last = stack_last(*from_stack);
	*from_stack = (*from_stack)->next;
	last->next = *from_stack;
	if (*to_stack)
	{
		head->next = *to_stack;
		last = stack_last(*to_stack);
		*to_stack = head;
		last->next = head;
	}
	else
	{
		*to_stack = head;
		(*to_stack)->next = *to_stack;
	}
	if (*from_stack == *to_stack)
	{
		*from_stack = NULL;
	}
}
