/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_tolist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <lsomrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 02:23:45 by lsomrat           #+#    #+#             */
/*   Updated: 2022/10/09 02:24:18 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

static void	index_list(t_list **list);
t_list		*get_smallest(t_list **list);

void	print_stack(char *str, t_list *stack)
{
	t_list	*temp;

	printf("%s:: ", str);
	if (!stack)
	{
		printf("NULL\n");
		return ;
	}
	temp = stack->next;
	printf("%d -> ", stack->data);
	while (stack != temp)
	{
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

int	arg_tolist(t_list **stack, int argc, char **argv)
{
	t_list	*new_list;
	t_list	*last;
	char	**arg;
	int		i;
	int		num;
	// (void)*stack;
	// (void)*new_list;

	i = 0;
	if (argc == 2)
		arg = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		arg = argv;
	}
	while (i < argc && arg[i])
	{
		num = atoi(arg[i]);
		new_list = ft_lstnew(num);
		ft_lstadd_back(stack, new_list);
		// print_stack(*stack);
		i++;
	}
	if (argc == 2)
		free_split(arg);
	index_list(stack);
	if (check_dup(*stack))
		return (1);
	last = ft_lstlast(*stack);
	last->next = *stack;
	// print_stack(*stack);
	return (0);
}

void	free_split(char **arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		free(arg[i]);
		i++;
	}
	free(arg);
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
			if ((head->index == -1) && (!has_min || head->data < min->data))
			{
				min = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}
