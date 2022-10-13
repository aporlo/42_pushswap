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

// # define MID	stack->mid
// # define POS	stack->pos
// # define LEN	stack->len
// # define ROUND	stack->round

// typedef struct s_list1
// {
// 	void			*content;
// 	struct s_list1	*next;
// }	t_list1;

typedef struct s_list
{
	void				*content;
	long int			data;
	int					index;
	struct s_list		*next;
	struct s_list		*prev;
}	t_list;

typedef struct s_stack
{
	int				to_print;
	struct s_list	*a;
	struct s_list	*b;

	int				len;
	int				mid;
	int				pos;
	int				round;
}	t_stack;

void	swap(t_stack *stack, char stack_name);
void	push(t_stack *stack, char stack_name);
void	rotate(t_stack *stack, char stack_name);
void	reverse(t_stack *stack, char stack_name);
void	to_push(t_list **list, char stack_name, long int data);
void	print_opt(int to_print, char *opt);
void	error(t_list *list);

void	check_arg(int argc, char **argv);
void	check_dup(t_list *list);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *s);
int		ft_isdigit(int c);
void	ft_putstr_fd(char *s, int fd);
// int		ft_lstsize(t_list1 *lst);
// void	ft_lstclear(t_list1 **lst, void (*del)(void*));
void	ft_lstadd_back(t_list **lst, t_list *new);
size_t	ft_strlen(const char *s);
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
void	arg_tolist(t_list **stack, int argc, char **argv);

int		is_sorted(t_list **list);
int		quick_way(t_stack *stack, int value);
void	sorting(t_stack *stack);
void	sort_three(t_stack *stack);
void	sort_five(t_stack *stack, int size);
int		*sort_tab(t_stack *stack, int size);
void	sort_large(t_stack *stack, int size);
int		stack_len(t_stack *stack, char stack_name);
void	free_stack(t_list *list);
void	free_split(char **arg);

#endif
