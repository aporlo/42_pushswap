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

static void	index_list(t_list **list);
t_list		get_smallest(t_list **list);

void	arg_tolist(t_list **stack, int argc, char **argv)
{
	t_list	*new_list;
	char	**arg;
	int		i;
	int		num;

	i = 0;
	if (argc == 2)
		arg = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		arg = argv;
	}
	while (arg[i])
	{
		num = atoi(arg[i]);
		new_list = ft_lstnew((void *)&num);
		ft_lstadd_back(stack, new_list);
		i++;
	}
	index_list(stack);
	if (argc == 2)
		free_split(arg);
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
	*head = get_smallest(list);
	while (head)
	{
		head->index = i++;
		*head = get_smallest(list);
	}
}

t_list	get_smallest(t_list **list)
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
	return (*min);
}
