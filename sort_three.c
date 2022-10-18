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
static int	get_min(t_stack *stack, int data);

void	sort_three(t_stack *stack)
{
	t_list		*head;
	int		min;
	int		next_min;

	head = stack->a;
	min = get_min(stack, -1);
	next_min = get_min(stack, min);
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

// void	sort_three(t_stack *stack)
// {
// 	while (stack->a)
// 	{
// 		printf("index is %d\n", stack->a->index);
// 		stack->a = stack->a->next;
// 	}

// 	if ((stack->a->data < stack->a->next->data)
// 		&& (stack->a->next->data > stack->a->next->next->data)
// 		&& (stack->a->next->next->data > stack->a->data))
// 	{
// 		printf("hello1\n");
// 		swap(stack, 'a');
// 		rotate(stack, 'a');
// 	}
// 	else if ((stack->a->data > stack->a->next->data)
// 		&& (stack->a->next->data > stack->a->next->next->data)
// 		&& (stack->a->next->next->data < stack->a->data))
// 	{
// 		printf("hello2\n");
// 		rotate(stack, 'a');
// 		swap(stack, 'a');
// 	}
// 	else if ((stack->a->data < stack->a->next->data)
// 		&& (stack->a->next->next->data < stack->a->next->data))
// 	{
// 		printf("hello3\n");
// 		reverse(stack, 'a');
// 	}
// 	else if ((stack->a->data > stack->a->next->next->data)
// 		&& (stack->a->data > stack->a->next->data))
// 	{
// 		printf("hello4\n");
// 		rotate(stack, 'a');
// 	}
// 	else if ((stack->a->data > stack->a->next->data)
// 		&& (stack->a->data < stack->a->next->next->data))
// 	{
// 		printf("hello5\n");
// 		swap(stack, 'a');
// 	}
// }

int	get_min(t_stack *stack, int data)
{
	t_list	*head;
	t_list	*temp;
	int		min;

	head = stack->a;
	temp = head->next;
	min = temp->index;
	while (head != temp)
	{
		temp = temp->next;
		if (temp->index < min && temp->index != data)
			min = temp->index;
	}
	return (min);
}
