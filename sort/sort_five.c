/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <lsomrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:12:47 by lsomrat           #+#    #+#             */
/*   Updated: 2022/10/12 14:13:22 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five(t_stack *stack)
{
	int			distance;

	distance = get_distance(stack, get_min(stack, -1));
	if (distance == 1)
		rotate(stack, 'a');
	else if (distance == 2)
	{
		rotate(stack, 'a');
		rotate(stack, 'a');
	}
	else if (distance == 3)
	{
		reverse(stack, 'a');
		reverse(stack, 'a');
	}
	else if (distance == 4)
	{
		reverse(stack, 'a');
	}
	if (is_sorted(&stack->a))
		return ;
	push(stack, 'b');
	sort_four(stack);
	push(stack, 'a');
}
