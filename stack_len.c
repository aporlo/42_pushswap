/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <lsomrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 21:39:20 by lsomrat           #+#    #+#             */
/*   Updated: 2022/10/12 21:39:23 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack *stack, char stack_name)
{
	t_list		*head;
	t_list		*end;
	int			len;

	if (stack_name == 'a')
		head = stack->a;
	else
		head = stack->b;
	if (head)
	{
		if (stack_name == 'a')
			end = stack->a->prev;
		else
			end = stack->b->prev;
	}
	len = 0;
	while (head)
	{
		len++;
		if (head == end)
			break ;
		head = head->next;
	}
	return (len);
}
