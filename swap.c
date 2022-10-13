/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <lsomrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 04:17:40 by lsomrat           #+#    #+#             */
/*   Updated: 2022/10/06 22:14:09 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	to_swap(t_list *list)
{
	long int	tmp;

	if (list && list->next != list)
	{
		tmp = list->data;
		list->data = list->next->data;
		list->next->data = tmp;
	}
	return ;
}

void	swap(t_stack *stack, char stack_name)
{
	if (stack->a && (stack_name == 'a'))
	{
		to_swap(stack->a);
		print_opt(stack->to_print, "sa\n");
	}
	else if (stack->b && (stack_name == 'b'))
	{
		to_swap(stack->b);
		print_opt(stack->to_print, "sb\n");
	}
	else if (stack->a && stack->b && (stack_name == 'c'))
	{
		to_swap(stack->a);
		to_swap(stack->b);
		print_opt(stack->to_print, "ss\n");
	}
}
