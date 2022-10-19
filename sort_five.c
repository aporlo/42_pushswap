/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <lsomrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:12:47 by lsomrat           #+#    #+#             */
/*   Updated: 2022/10/12 14:13:22 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	get_last(t_stack *stack, int low, int size);
// static void	push_loweset(t_stack *stack, int low, int size);

// void	sort_five(t_stack *stack, int size)
// {
// 	int	low;

// 	low = stack->a->data;
// 	get_last(stack, low, size);
// 	push_loweset(stack, low, size);
// 	sort_three(stack);
// 	if (size == 4)
// 	{
// 		push(stack, 'b');
// 		return ;
// 	}
// 	// check_case(stack);
// 	push(stack, 'b');
// 	if (stack->a->data > stack->a->next->data
// 		&& stack->a->data < stack->a->next->next->data)
// 		swap(stack, 'a');
// 	else if (stack->a->data > stack->a->next->next->next->data)
// 		rotate(stack, 'a');
// 	push(stack, 'b');
// }

// static void	get_last(t_stack *stack, int low, int size)
// {
// 	if (size == 5)
// 	{
// 		if (low == stack->a->next->next->next->next->data)
// 			reverse(stack, 'a');
// 	}
// 	if (low == stack->a->next->next->next->data)
// 	{
// 		reverse(stack, 'a');
// 		if (size == 5)
// 			reverse(stack, 'a');
// 		/**size == 0;**/
// 	}
// }

// static void	push_loweset(t_stack *stack, int low, int size)
// {
// 	int		i;

// 	i = 0;
// 	while (i < 2)
// 	{
// 		if (stack->a->data == low)
// 		{
// 			push(stack, 'a');
// 			if (size == 5)
// 				push(stack, 'a');
// 			/* size == 0;**/
// 			i = 2;
// 		}
// 		else
// 		{
// 			rotate(stack, 'a');
// 		}
// 	}
// }
