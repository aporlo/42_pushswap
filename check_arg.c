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

static void	compare(t_list *list, int v1, int v2)
{
	if (v1 == v2)
	{
		free_stack(list);
		ft_putstr_fd("Error\n", STDERR_FILENO);
	}
}

void	check_dup(t_list *list)
{
	t_list		*lst;
	t_list		*temp;
	int			len;
	int			i;
	int			j;

	i = 0;
	len = stack_len(list);
	temp = list;
	while (i < len)
	{
		lst = temp;
		j = 0;
		while (j < i)
		{
			compare(list, list->data, lst->data);
			lst = lst->next;
			j++;
		}
		list = list->next;
		i++;
	}
}

static void	check_error(int i, char **arg)
{
	long	num;

	while (arg[i])
	{
		num = ft_atoi(arg[i]);
		is_num(arg[i]);
		if (!is_num(arg[i]))
			ft_putstr_fd("Error\n", STDERR_FILENO);
		if (num < INT_MIN || num > INT_MAX)
			ft_putstr_fd("Error\n", STDERR_FILENO);
		i++;
	}
}

void	check_arg(int argc, char **argv)
{
	int		i;
	int		j;
	char	**arg;

	j = 0;
	(void)argc;
	check_argv(argv);
	while (argv[1 + j])
	{
		i = 0;
		arg = ft_split(argv[1 + j], ' ');
		if (!arg[0])
			ft_putstr_fd("Error\n", STDERR_FILENO);
		check_error(i, arg);
		j++;
		free_split(arg);
	}
}
