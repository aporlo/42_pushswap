/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <lsomrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 03:20:24 by lsomrat           #+#    #+#             */
/*   Updated: 2022/10/09 03:20:26 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_num(char *arg)
{
	int	i;

	i = 0;
	if (arg[0] == '-' && ft_strlen(arg) > 1)
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	compare(int v1, int v2)
{
	if (v1 == v2)
		return (0);
	else
		return (1);
}

int	check_dup(t_list *list)
{
	t_list		*lst;

	while (list)
	{
		lst = list->next;
		while (lst)
		{
			if (!compare(list->data, lst->data))
			{
				ft_putstr_fd("Error\n", STDERR_FILENO);
				free_stack(list);
				return (1);
			}
			lst = lst->next;
		}
		list = list->next;
	}
	return (0);
}

void	check_arg(int argc, char **argv)
{
	int		i;
	long	num;
	char	**arg;

	i = 0;
	if (argc == 2)
		arg = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		arg = argv;
	}
	num = ft_atoi(arg[i]);
	is_num(arg[i]);
	while (arg[i])
	{
		num = ft_atoi(arg[i]);
		if (!is_num(arg[i]))
			ft_putstr_fd("Error\n", STDERR_FILENO);
		if (num < INT_MIN || num > INT_MAX)
			ft_putstr_fd("Error\n", STDERR_FILENO);
		i++;
	}
	if (argc == 2)
		free_split(arg);
}
