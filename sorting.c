/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <lsomrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:15:19 by lsomrat           #+#    #+#             */
/*   Updated: 2022/10/11 15:15:36 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sorting(t_stack *stack)
{
	int	size;

	size = stack_len(stack->a);
	if (size > 1)
	{
		if (size == 2)
		{
			swap(stack, 'a');
		}
		else if (size == 3)
			sort_three(stack);
		else if (size == 4)
			sort_four(stack);
		else if (size == 5)
			sort_five(stack);
		else
			sort_big(stack);
	}

	// else
	// 	sort_large(stack, size);
}
