# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: matrodri <matrodri@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 12:41:17 by matrodri          #+#    #+#              #
#    Updated: 2021/10/22 16:19:09 by matrodri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

CLIENT = client
SERVER = server

CC = clang
CFLAGS = -Wall -Wextra -Werror

PATH_SRCS = ./src/
PATH_MDT = $(PATH_SRCS)mandatory/
PATH_LBF = $(PATH_SRCS)mini_libft/
PATH_OBJS = ./objs/

SRCS =		$(PATH_MDT)utils.c \
			$(PATH_LBF)ft_atoi.c \
			$(PATH_LBF)ft_callo.c \
			$(PATH_LBF)ft_itoa.c \
			$(PATH_LBF)ft_strlen.c

OBJS =		$(patsubst $(PATH_SRCS)%.c, $(PATH_OBJS)%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS)

$(PATH_OBJS)%.o: $(PATH_SRCS)%.c
	@mkdir -p $(PATH_OBJS)
	@mkdir -p $(PATH_OBJS)mandatory
	@mkdir -p $(PATH_OBJS)mini_libft
	@$(CC) $(CFLAGS) -c $< -o $@


$(CLIENT):
		$(CC) $(CFLAGS) $(PATH_MDT)client.c $(OBJS) -o $@

$(SERVER):
		$(CC) $(CFLAGS) $(PATH_MDT)server.c $(OBJS) -o $@

clean:
	rm -rf $(PATH_OBJS) $(CLIENT) $(SERVER)

re: clean all
