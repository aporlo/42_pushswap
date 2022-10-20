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

int	find_max(t_list *stack)
{
	int		max;
	int		len;
	t_list	*temp;

	len = stack_len(stack);
	temp = stack->next;
	max = stack->index;
	while (len--)
	{
		if (max < temp->index)
			max = temp->index;
		temp = temp->next;
	}
	return (max);
}

int	find_big_back(t_list *stack)
{
	int		i;
	int		j;
	int		max;
	t_list	*temp;

	i = 0;
	j = 0;
	temp = stack;
	max = find_max(stack);
	while (i <= (stack_len(stack) - 1))
	{
		if (temp->index >= max)
			j = i;
		temp = temp->next;
		i++;
	}
	return (i - j);
}

int	find_big_front(t_list *stack)
{
	int		i;
	int		max;
	t_list	*temp;

	i = 0;
	temp = stack;
	max = find_max(stack);
	while (temp->index < max)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
