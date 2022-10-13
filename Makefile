NAME	= push_swap
CC		= gcc
FLAGS	= -Wall -Wextra -Werror

SRCS	= swap.c \
		push.c \
		rotate.c \
		reverse.c \
		to_push.c \
		print_opt.c \
		error.c \
		arg_tolist.c\
		check_arg.c\
		ft_atoi.c\
		ft_isdigit.c\
		ft_lstadd_back.c\
		ft_lstlast.c\
		ft_lstnew.c\
		ft_lstsize.c\
		ft_split.c\
		ft_strlen.c\
		is_sorted.c\
		main.c\
		quick_way.c\
		sort_five.c\
		sort_three.c\
		sort_large.c\
		sort_tab.c\
		sorting.c\
		stack_len.c\
		ft_putstr_fd.c\

OBJS	= ${SRCS:.c=.o}

# OBJS_B    = ${SRCS_B:.c=.o}

%.o: %.c
	gcc ${FLAGS} -c $< -o $@

$(NAME): ${OBJS}
	gcc -o ${NAME} ${OBJS}

all: ${NAME}

# ${NAME}: push_swap

# push_swap:
# 		@${CC} ${FLAGS} ${SRCS} -o ${PUSH_SWAP}

norminette:
	norminette ${SRCS}

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

bonus: all

rebonus: fclean bonus

.PHONY: norminette all
