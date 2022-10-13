/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <lsomrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:45:15 by lsomrat           #+#    #+#             */
/*   Updated: 2022/10/11 15:50:26 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stack)
{
	if ((stack->a->data < stack->a->next->data)
		&& (stack->a->next->data > stack->a->next->next->data)
		&& (stack->a->next->next->data > stack->a->data))
	{
		swap(stack, 'a');
		rotate(stack, 'a');
	}
	else if ((stack->a->data > stack->a->next->data)
		&& (stack->a->next->data > stack->a->next->next->data)
		&& (stack->a->next->next->data < stack->a->data))
	{
		rotate(stack, 'a');
		swap(stack, 'a');
	}
	else if ((stack->a->data < stack->a->next->data)
		&& (stack->a->next->next->data < stack->a->next->data))
		reverse(stack, 'a');
	else if ((stack->a->data > stack->a->next->next->data)
		&& (stack->a->data > stack->a->next->data))
		rotate(stack, 'a');
	else if ((stack->a->data > stack->a->next->data)
		&& (stack->a->data < stack->a->next->next->data))
		swap(stack, 'a');
}
