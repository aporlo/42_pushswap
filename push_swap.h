/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsomrat <lsomrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 23:24:46 by lsomrat           #+#    #+#             */
/*   Updated: 2022/10/06 22:24:28 by lsomrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_list
{
	int					data;
	int					index;
	struct s_list		*next;
	struct s_list		*prev;
}	t_list;

typedef struct s_stack
{
	int				to_print;
	t_list			*a;
	t_list			*b;
}	t_stack;

void	swap(t_stack *stack, char stack_name);
void	push(t_stack *stack, char stack_name);
void	rotate(t_stack *stack, char stack_name);
void	reverse(t_stack *stack, char stack_name);
void	to_push(t_list **from_stack, t_list **to_stack);
void	print_opt(int to_print, char *opt);
void	error(t_list *list);
void	print_stack(char *str, t_list *stack);
// void	to_list(t_list **stack, int argc, char **argv);
t_list	*stack_last(t_list *list);

void	check_arg(int argc, char **argv);
void	check_dup(t_list *list);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *s);
int		ft_isdigit(int c);
void	ft_putstr_fd(char *s, int fd);
void	ft_lstadd_back(t_list **lst, t_list *new);
size_t	ft_strlen(const char *s);
t_list	*ft_lstnew(int data);
t_list	*ft_lstlast(t_list *lst);
void	arg_tolist(t_list **stack, int argc, char **argv);

int		is_sorted(t_list **list);
int		find_max(t_list *stack);
int		find_big_back(t_list *stack);
int		find_big_front(t_list *stack);
void	sorting(t_stack *stack);
void	sort_three(t_stack *stack);
void	sort_four(t_stack *stack);
void	sort_five(t_stack *stack);
void	sort_large(t_stack *stack, int size);
void	sort_big(t_stack *stack);
int		get_min(t_stack *stack, int data);
int		get_distance(t_stack *stack, int i);
int		stack_len(t_list *stack);
void	free_stack(t_list *list);
void	free_split(char **arg);

#endif
