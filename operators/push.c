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

void	push(t_stack *stack, char stack_name)
{
	if (!stack->a && !stack->b)
		return ;
	if (stack_name == 'a')
	{
		to_push(&stack->b, &stack->a);
		print_opt(stack->to_print, "pa\n");
	}
	else if (stack_name == 'b')
	{
		to_push(&stack->a, &stack->b);
		print_opt(stack->to_print, "pb\n");
	}
}
