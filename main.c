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

static void	push_swap(t_stack *stack)
{
	stack->to_print = 1;
	if (is_sorted(&stack->a))
	{
		free_stack(stack->a);
		free_stack(stack->b);
	}
	sorting(stack);
}

int	main(int argc, char **argv)
{
	t_stack		stack;
	t_list		*a;
	t_list		*b;

	if (argc < 2)
		return (1);
	check_arg(argc, argv);
	a = (t_list *)malloc(sizeof(t_list));
	b = (t_list *)malloc(sizeof(t_list));
	if (!a && !b)
		return (1);
	a = NULL;
	b = NULL;
	stack.a = a;
	stack.b = b;
	arg_tolist(&stack.a, argc, argv);
	check_dup(stack.a);
	push_swap(&stack);
	free_stack(a);
	free_stack(b);
	return (0);
}
