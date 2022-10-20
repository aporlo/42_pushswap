/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <lsomrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:43:13 by lsomrat           #+#    #+#             */
/*   Updated: 2022/10/20 16:43:16 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_distance(t_stack *stack, int i)
{
	t_list	*head;
	int		distance;
	int		len;

	head = stack->a;
	distance = 0;
	len = stack_len(head);
	while (len--)
	{
		if (i == head->index)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}

void	sort_four(t_stack *stack)
{
	int			distance;

	distance = get_distance(stack, get_min(stack, -1));
	if (distance == 1)
		rotate(stack, 'a');
	else if (distance == 2)
	{
		rotate(stack, 'a');
		rotate(stack, 'a');
	}
	else if (distance == 3)
	{
		reverse(stack, 'a');
	}
	if (is_sorted(&stack->a))
		return ;
	push(stack, 'b');
	sort_three(stack);
	push(stack, 'a');
}
