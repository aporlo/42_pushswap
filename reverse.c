/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <lsomrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:43:13 by lsomrat           #+#    #+#             */
/*   Updated: 2022/10/08 16:49:45 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_reverse(int to_print, char *opt);

void	reverse(t_stack *stack, char stack_name)
{
	if (stack->a && stack_name == 'a')
	{
		stack->a = stack_last(stack->a);
		print_reverse(stack->to_print, "rra\n");
	}
	else if (stack->b && stack_name == 'b')
	{
		stack->b = stack_last(stack->b);
		print_reverse(stack->to_print, "rrb\n");
	}
	else if (stack->a && stack->b && stack_name == 'c')
	{
		stack->a = stack_last(stack->a);
		stack->b = stack_last(stack->b);
		print_reverse(stack->to_print, "rrr\n");
	}
}

static void	print_reverse(int to_print, char *opt)
{
	if (to_print)
		write(1, opt, 4);
}
