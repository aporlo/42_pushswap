/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <lsomrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 22:44:35 by lsomrat           #+#    #+#             */
/*   Updated: 2022/10/07 22:35:18 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	del_top(t_list **head);

void	push(t_stack *stack, char stack_name)
{
	long int	data;

	if (stack->a && stack_name == 'a')
	{
		data = stack->b->data;
		to_push(&stack->a, 'b', data);
		del_top(&stack->a);
		print_opt(stack->to_print, "pb\n");
	}
	else if (stack->b && stack_name == 'b')
	{
		data = stack->a->data;
		to_push(&stack->b, 'a', data);
		del_top(&stack->b);
		print_opt(stack->to_print, "pa\n");
	}
}

static void	del_top(t_list **head)
{
	t_list	*temp;

	if (*head)
	{
		if ((*head)->next == *head)
		{
			free(*head);
			*head = NULL;
		}
		else
		{
			temp = *head;
			*head = (*head)->next;
			temp->prev->next = *head;
			(*head)->prev = temp->prev;
			free(temp);
		}
	}
}
