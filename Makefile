NAME	= push_swap
CC		= gcc
FLAGS	= -g -Wall -Wextra -Werror

SRCS	= main.c \
		error.c \
		arg_tolist.c \
		check_arg.c \
		is_sorted.c \
		free_split.c \
		operators/swap.c \
		operators/push.c \
		operators/rotate.c \
		operators/reverse.c \
		operators/to_push.c \
		operators/print_opt.c \
		sort/sorting.c \
		sort/quick_way.c \
		sort/sort_three.c \
		sort/sort_four.c \
		sort/sort_five.c \
		sort/sort_big.c \
		utils/ft_atoi.c \
		utils/ft_isdigit.c \
		utils/ft_lstadd_back.c \
		utils/ft_putstr_fd.c \
		utils/ft_lstlast.c \
		utils/ft_lstnew.c \
		utils/ft_lstsize.c \
		utils/ft_split.c \
		utils/ft_strlen.c \
		utils/stack_len.c

OBJS	= ${SRCS:.c=.o}

# OBJS_B    = ${SRCS_B:.c=.o}

%.o: %.c
	gcc ${FLAGS} -I./ -c $< -o $@

$(NAME): ${OBJS}
	gcc ${OBJS} -I./ -o ${NAME}

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

.PHONY: norminette all ${NAME}
