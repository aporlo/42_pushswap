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

// int	get_distance(t_stack *stack, int i)
// {
// 	t_list	*head;
// 	int		distance;
// 	int		len;

// 	head = stack->a;
// 	distance = 0;
// 	len = stack_len(head);
// 	while (len--)
// 	{
// 		if (i == head->index)
// 			break ;
// 		distance++;
// 		head = head->next;
// 	}
// 	return (distance);
// }

// void	sort_four(t_stack *stack)
// {
// 	int			distance;

// 	distance = get_distance(stack, get_min(stack, -1));
// 	if (distance == 1)
// 		rotate(stack, 'a');
// 	else if (distance == 2)
// 	{
// 		rotate(stack, 'a');
// 		rotate(stack, 'a');
// 	}
// 	else if (distance == 3)
// 	{
// 		reverse(stack, 'a');
// 	}
// 	if (is_sorted(&stack->a))
// 		return ;
// 	push(stack, 'b');
// 	sort_three(stack);
// 	push(stack, 'a');
// }

// void	sort_five(t_stack *stack)
// {
// 	int			distance;

// 	distance = get_distance(stack, get_min(stack, -1));
// 	if (distance == 1)
// 		rotate(stack, 'a');
// 	else if (distance == 2)
// 	{
// 		rotate(stack, 'a');
// 		rotate(stack, 'a');
// 	}
// 	else if (distance == 3)
// 	{
// 		reverse(stack, 'a');
// 		reverse(stack, 'a');
// 	}
// 	else if (distance == 4)
// 	{
// 		reverse(stack, 'a');
// 	}
// 	if (is_sorted(&stack->a))
// 		return ;
// 	push(stack, 'b');
// 	sort_four(stack);
// 	push(stack, 'a');
// }

// if (head->index == min && head->next->index != next_min)
	// {
	// 	rotate(stack, 'a');
	// 	swap(stack, 'a');
	// 	reverse(stack, 'a');
	// }
	// else if (head->index == next_min)
	// {
	// 	if (head->next->index == min)
	// 		swap(stack, 'a');
	// 	else
	// 		reverse(stack, 'a');
	// }
	// else
	// {
	// 	if (head->next->index == min)
	// 		rotate(stack, 'a');
	// 	else
	// 	{
	// 		swap(stack, 'a');
	// 		reverse(stack, 'a');
	// 	}
	// }
