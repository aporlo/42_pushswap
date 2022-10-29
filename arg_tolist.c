/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_tolist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <lsomrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 02:23:45 by lsomrat           #+#    #+#             */
/*   Updated: 2022/10/29 21:34:15 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

static void	index_list(t_list **list);
t_list		*get_smallest(t_list **list);

void	check_argv(char **argv)
{
	if (argv[1][0] == '\0')
		exit(0);
}

static void	to_list(t_list **stack, int argc, char **argv)
{
	int		num;
	char	**arg;
	t_list	*new_list;
	int		i;
	int		j;

	j = 0;
	(void)argc;
	check_argv(argv);
	while (argv[1 + j])
	{
		i = 0;
		arg = ft_split(argv[1 + j], ' ');
		if (!arg[0])
			ft_putstr_fd("Error\n", STDERR_FILENO);
		while (arg[i])
		{
			num = ft_atoi(arg[i]);
			new_list = ft_lstnew(num);
			ft_lstadd_back(stack, new_list);
			i++;
		}
		j++;
		free_split(arg);
	}
}

void	arg_tolist(t_list **stack, int argc, char **argv)
{
	t_list	*last;

	to_list(stack, argc, argv);
	check_dup(*stack);
	index_list(stack);
	last = ft_lstlast(*stack);
	last->next = *stack;
}

static void	index_list(t_list **list)
{
	t_list	*head;
	int		i;

	i = 0;
	head = NULL;
	head = get_smallest(list);
	while (head)
	{
		head->index = i++;
		head = get_smallest(list);
	}
}

t_list	*get_smallest(t_list **list)
{
	t_list	*head;
	t_list	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = *list;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1)
				&& (!has_min || head->data < min->data))
			{
				min = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}
