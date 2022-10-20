/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <lsomrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 02:52:01 by lsomrat           #+#    #+#             */
/*   Updated: 2022/10/20 02:52:04 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_chankb(t_stack *stack, int size)
{
	int	chank_n;
	int	count;

	chank_n = 1;
	count = 0;
	while (stack_len(stack->a))
	{
		if (stack->a->index < chank_n * size)
		{
			push(stack, 'b');
			if (stack->b->index < chank_n * size - (size / 2))
			{
				rotate(stack, 'b');
			}
			count++;
		}
		else
			rotate(stack, 'a');
		if (count == chank_n * size)
			chank_n++;
	}
}

void	push_toa(t_stack *stack)
{
	int	hold_first;
	int	hold_second;

	while (stack_len(stack->b) > 0)
	{
		hold_first = find_big_front(stack->b);
		hold_second = find_big_back(stack->b);
		if (hold_first <= hold_second)
		{
			while (hold_first-- > 0)
			{
				rotate(stack, 'b');
			}
			push(stack, 'a');
		}
		else
		{
			while (hold_second-- > 0)
			{
				reverse(stack, 'b');
			}
			push(stack, 'a');
		}
	}
}

void	sort_big(t_stack *stack)
{
	int	s_chank;

	s_chank = stack_len(stack->a) / 12 + 22;
	push_chankb(stack, s_chank);
	push_toa(stack);
}
