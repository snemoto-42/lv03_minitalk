# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: snemoto <snemoto@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/28 15:42:21 by snemoto           #+#    #+#              #
#    Updated: 2023/04/13 19:19:23 by snemoto          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT_SRCS	= \
			client.c

SERVER_SRCS	= \
			server.c

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -I include
RM		= rm -f

C_NAME	= client
C_SRCS	= ${CLIENT_SRCS}
C_OBJS	= ${CLIENT_SRCS:.c=.o}

S_NAME	= server
S_SRCS	= ${SERVER_SRCS}
S_OBJS	= ${SERVER_SRCS:.c=.o}

NAME	= ${C_NAME} ${S_NAME}
OBJS	= ${C_OBJS} ${S_OBJS}

LIBFT_PATH = libft
LIBFT_INCLUDE = libft.a
LIBFTPRINTF_PATH = libftprintf
LIBFTPRINTF_INCLUDE = libftprintf.a

$(NAME):	${OBJS} ${NAME}

$(C_NAME):
			cd "$(PWD)/${LIBFT_PATH}" && make bonus
			cd "$(PWD)/${LIBFTPRINTF_PATH}" && make bonus
			${CC} ${CFLAGS} \
			$(PWD)/${LIBFT_PATH}/${LIBFT_INCLUDE} \
			$(PWD)/${LIBFTPRINTF_PATH}/${LIBFTPRINTF_INCLUDE} \
			${C_SRCS} -o ${C_NAME}

$(S_NAME):
			cd "$(PWD)/${LIBFT_PATH}" && make bonus
			cd "$(PWD)/${LIBFTPRINTF_PATH}" && make bonus
			${CC} ${CFLAGS} \
			$(PWD)/${LIBFT_PATH}/${LIBFT_INCLUDE} \
			$(PWD)/${LIBFTPRINTF_PATH}/${LIBFTPRINTF_INCLUDE} \
			${S_SRCS} -o ${S_NAME}

all:	${NAME}

clean:
		${RM} ${C_OBJS}
		${RM} ${S_OBJS}
		cd "$(PWD)/${LIBFTPRINTF_PATH}" && make fclean

fclean:	clean
		${RM} ${C_NAME}
		${RM} ${S_NAME}

re:		fclean all

bonus:	all

.PHONY: all clean fclean re bonus
