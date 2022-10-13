/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <lsomrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 23:08:11 by lsomrat           #+#    #+#             */
/*   Updated: 2022/10/07 23:11:15 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_list *list);

void	error(t_list *list)
{
	write(2, "Error\n", 6);
	free_stack(list);
	exit(-1);
}

void	free_stack(t_list *list)
{
	t_list		*stack_next;
	t_list		*delete;

	if (list)
	{
		stack_next = list->next;
		while (stack_next != list)
		{
			delete = stack_next;
			stack_next = stack_next->next;
			free(delete);
		}
		free(stack_next);
	}
}
