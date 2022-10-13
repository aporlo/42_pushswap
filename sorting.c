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

	if (!(is_sorted(&stack->a)))
	{
		size = stack_len(stack, 'a');
		if (size <= 5)
		{
			if (size == 2 && stack->a->data > stack->a->next->data)
				swap(stack, 'a');
			else if (size == 3)
				sort_three(stack);
			else if (size <= 5)
				sort_five(stack, size);
		}
		else
			sort_large(stack, size);
	}
}
