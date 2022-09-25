NAME	= push_swap
SERVER  = server
CLIENT	= client
CC		= gcc
FLAGS	= -Wall -Wextra -Werror

SRCS_SER = server.c
SRCS_CNT = client.c
SRCS	= ft_atoi.c \
		ft_putnbr_fd.c \
		
all: ${NAME}

${NAME}: server client

server:
		@${CC} ${FLAGS} ${SRCS_SER} ${SRCS} -o ${SERVER}

client:
		@${CC} ${FLAGS} ${SRCS_CNT} ${SRCS} -o ${CLIENT}

norminette:
	norminette ${SRCS} ${SRCS_SER} ${SRCS_CNT}

clean:
	rm -f ${SERVER}
	rm -f ${CLIENT}

fclean: clean
	rm -f ${NAME}

re: fclean all

bonus: all

rebonus: fclean bonus

test: re
		@valgrind -q --leak-check=full --track-origins=yes ./${CLIENT} ${pid} "${text}"

.PHONY: norminette all
