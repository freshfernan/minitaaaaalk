# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fefernan <fefernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/27 12:32:34 by fefernan          #+#    #+#              #
#    Updated: 2022/11/22 12:47:53 by fefernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=
CLIENT	=	client
SERVER	=	server

LIBFT		=	./libft/libft.a
LIBFT_DIR	=	./libft

SRC_C	=	client.c
SRC_S	=	server.c
INC		=	-I. -I$(LIBFT_DIR) -I$(LIBFT_DIR)/stack \
			-I$(LIBFT_DIR)/get_next_line

CC			=	gcc -fsanitize=address -g3
CFLAG		=	-Wall -Wextra -Werror
RM			=	rm -f

	# koloreak #
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]

ifeq ($(DEBUG), 1)
	D_FLAG	=	-g
endif

ifeq ($(SANITIZE), 1)
	D_FLAG	=	-fsanitize=leak -g
endif


all: $(SERVER) $(CLIENT)

$(NAME): all

$(SERVER): $(LIBFT)
	@ $(CC) $(D_FLAG) $(CFLAG) $(SRC_S) $(LIBFT) $(INC) -o $(SERVER)
	@printf "$(_SUCCESS) server ready.\n"

$(CLIENT): $(LIBFT)
	@ $(CC) $(D_FLAG) $(CFLAG) $(SRC_C) $(LIBFT) $(INC) -o $(CLIENT)
	@printf "$(_SUCCESS) client ready.\n"


$(LIBFT):
	@ $(MAKE) DEBUG=$(DEBUG) -C ./libft

clean:
	@ $(RM) $(CLIENT) $(SERVER)
	@printf "$(_INFO) client removed.\n"
	@printf "$(_INFO) server removed.\n"

fclean:
	@ $(MAKE) fclean -C $(LIBFT_DIR)
	@ $(RM) $(CLIENT) $(SERVER)
	@printf "$(_INFO) client removed.\n"
	@printf "$(_INFO) server removed.\n"

re: fclean all

mandatory:	$(CLIENT) $(SERVER)
bonus:		mandatory

m : mandatory
b : bonus

.PHONY: all clean fclean re mandatory m bonus b
