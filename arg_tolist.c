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
	while (stack != temp && temp != NULL)
	{
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

static void	to_list(t_list **stack, int argc, char **argv)
{
	int		num;
	char	**arg;
	t_list	*new_list;
	int		i;

	i = 0;
	if (argc == 2)
		arg = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		arg = argv;
	}
	while (i <= argc && arg[i])
	{
		// printf("i is %d\n", i);
		num = atoi(arg[i]);
		// printf("num is%d\n", num);
		new_list = ft_lstnew(num);
		// printf("new_list is %d\n", num);
		ft_lstadd_back(stack, new_list);
		i++;
	}
	// free_stack(new_list);
	if (argc == 2)
		free_split(arg);
}

void	arg_tolist(t_list **stack, int argc, char **argv)
{
	t_list	*last;
	// char	**arg;
	// int		i;

	// i = 0;
	// if (argc == 2)
	// 	arg = ft_split(argv[1], ' ');
	// else
	// {
	// 	i = 1;
	// 	arg = argv;
	// }
	// printf("argument is %s\n", argv[1]);
	to_list(stack, argc, argv);
	// print_stack("a", *stack);
	check_dup(*stack);
	// if (argc == 2)
	// 	free_split(arg);
	// if (check_dup(*stack))
	// 	return (1);
	index_list(stack);
	last = ft_lstlast(*stack);
	last->next = *stack;
	// free_stack(*stack);
	// return (0);
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
