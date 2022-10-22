/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <lsomrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 19:31:47 by lsomrat           #+#    #+#             */
/*   Updated: 2022/10/09 00:36:57 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static void	push_swap(t_stack *stack)
{
	stack->to_print = 1;
	if (is_sorted(&stack->a))
	{
		free_stack(stack->a);
		return ;
	}
	else
		sorting(stack);
}

int	main(int argc, char **argv)
{
	t_stack		stack;

	if (argc < 2)
		return (1);
	check_arg(argc, argv);
	stack.a = NULL;
	stack.b = NULL;
	if (arg_tolist(&stack.a, argc, argv))
		return (1);
	// arg_tolist(&stack.a, argc, argv);
	// if (check_dup(stack.a))
	// 	return (1);
	push_swap(&stack);
	return (0);
}
