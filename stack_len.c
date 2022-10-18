/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <lsomrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 21:39:20 by lsomrat           #+#    #+#             */
/*   Updated: 2022/10/12 21:39:23 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_list *stack)
{
	t_list		*temp;
	int			len;

	len = 1;
	temp = stack->next;
	while (stack != temp)
	{
		temp = temp->next;
		len++;
	}
	return (len);
}
