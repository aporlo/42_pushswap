/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <lsomrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 22:51:10 by lsomrat           #+#    #+#             */
/*   Updated: 2022/10/12 22:51:15 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_list(int *tab, unsigned int size);
static void	ft_swap(int *a, int*b);

int	*sort_tab(t_stack *stack, int size)
{
	t_list	*current;
	int		*tab;
	int		i;

	current = stack->a;
	i = 0;
	tab = (int *)malloc(sizeof(int) * size + 1);
	if (!tab)
		return (0);
	while (current)
	{
		tab[i] = current->data;
		current = current->next;
		i++;
	}
	sort_list(tab, size);
	return (tab);
}

static void	sort_list(int *tab, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i;
		while (j < size)
		{
			if (tab[i] > tab[j])
				ft_swap(&tab[i], &tab[j]);
			j += 1;
		}
		i += 1;
	}
}

static void	ft_swap(int *a, int*b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
