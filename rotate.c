/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <lsomrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 23:36:36 by lsomrat           #+#    #+#             */
/*   Updated: 2022/10/08 14:30:44 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack, char stack_name)
{
	if (stack->a && stack_name == 'a')
	{
		stack->a = stack->a->next;
		print_opt(stack->to_print, "ra\n");
	}
	else if (stack->b && stack_name == 'b')
	{
		stack->b = stack->b->next;
		print_opt(stack->to_print, "rb\n");
	}
	else if (stack->a && stack->b && stack_name == 'c')
	{
		stack->a = stack->a->next;
		stack->b = stack->b->next;
		print_opt(stack->to_print, "rr\n");
	}
}
