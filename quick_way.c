/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_way.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <lsomrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:29:22 by lsomrat           #+#    #+#             */
/*   Updated: 2022/10/12 22:29:24 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	quick_way(t_stack *stack, int value)
{
	int		size;
	int		moves;
	int		pos;
	int		mid;
	t_stack	*current;

	pos = 0;
	moves = 0;
	size = stack_len(stack->b);
	mid = size / 2;
	current = stack;
	while (current->b->data != value)
	{
		current->b = current->b->next;
		pos++;
	}
	if (pos <= mid)
		moves += pos;
	else
		moves = (-1 * (size - pos));
	return (moves);
}
