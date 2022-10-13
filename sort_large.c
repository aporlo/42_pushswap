/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <lsomrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 01:33:01 by lsomrat           #+#    #+#             */
/*   Updated: 2022/10/13 01:33:08 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	find_mid(t_stack *stack, int *tab, int size);
static void	move_b(t_stack *stack, int *tab, int *size);
static void	move_chank(t_stack *stack, int mid, int pos);

void	sort_large(t_stack *stack, int size)
{
	int		*tab;

	tab = sort_tab(stack, size);
	stack->len = size - 1;
	if (size <= 100)
		stack->round = 2;
	else
		stack->round = 1;
	while ((stack->a) && stack->round <= 10)
	{
		find_mid(stack, tab, size);
		move_chank(stack, stack->mid, stack->pos);
		stack->pos = stack->mid;
		if (size <= 100)
			stack->round = (stack->round) + 2;
		else
			stack->round = (stack->round) + 1;
	}
	while ((stack->b))
		move_b(stack, tab, &size);
	free(tab);
}

static void	find_mid(t_stack *stack, int *tab, int size)
{
	if ((stack->round) == 10)
		stack->mid = tab[stack->len];
	else
		stack->mid = tab[(size / 10) * ((stack->round))];
}

static void	move_b(t_stack *stack, int *tab, int *size)
{
	int		i;

	i = quick_way(stack, tab[*size]);
	while (stack->b->data != tab[*size])
	{
		if (stack->b->next)
		{
			if (stack->b->next->data == tab[*size])
			{
				swap(stack, 'b');
				break ;
			}
		}
		if (i < 0)
			reverse(stack, 'b');
		else
			rotate(stack, 'b');
	}
}

static void	move_chank(t_stack *stack, int mid, int pos)
{
	int		i;

	i = stack->a->data;
	pos = mid - pos;
	rotate(stack, 'a');
	while (stack->a->data != i && pos > 0)
	{
		if (stack->a->data <= i)
		{
			push(stack, 'a');
			pos--;
		}
		else
			rotate(stack, 'a');
	}
	if (stack->a->data <= i)
		push(stack, 'a');
}
