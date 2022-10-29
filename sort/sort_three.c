/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <lsomrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:45:15 by lsomrat           #+#    #+#             */
/*   Updated: 2022/10/11 15:50:26 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	to_sort(t_stack *stack, t_list *head, int min, int next_min);

void	sort_three(t_stack *stack)
{
	t_list		*head;
	int			min;
	int			next_min;

	head = stack->a;
	min = get_min(stack, -1);
	next_min = get_min(stack, min);
	to_sort(stack, head, min, next_min);
}

static void	to_sort(t_stack *stack, t_list *head, int min, int next_min)
{
	if (head->index == min && head->next->index != next_min)
	{
		rotate(stack, 'a');
		swap(stack, 'a');
		reverse(stack, 'a');
	}
	else if (head->index == next_min)
	{
		if (head->next->index == min)
			swap(stack, 'a');
		else
			reverse(stack, 'a');
	}
	else
	{
		if (head->next->index == min)
			rotate(stack, 'a');
		else
		{
			swap(stack, 'a');
			reverse(stack, 'a');
		}
	}
}

int	get_min(t_stack *stack, int data)
{
	t_list	*head;
	int		min;
	int		len;

	head = stack->a;
	min = head->index;
	len = stack_len(head);
	while (len--)
	{
		head = head->next;
		if (head->index < min && head->index != data)
			min = head->index;
	}
	return (min);
}
