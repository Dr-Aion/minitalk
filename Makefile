# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aiganymmoldagulova <aiganymmoldagulova@    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/20 04:32:17 by aiganymmold       #+#    #+#              #
#    Updated: 2025/07/20 05:20:53 by aiganymmold      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client

SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

SERVER_SRC = server.c libft/ft_memset.c
CLIENT_SRC = client.c libft/ft_atoi.c libft/ft_memset.c

SERVER_SRC_BONUS = server_bonus.c utils_bonus.c libft/ft_memset.c
CLIENT_SRC_BONUS = client_bonus.c utils_bonus.c libft/ft_atoi.c libft/ft_memset.c 

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

SERVER_OBJ_BONUS = $(SERVER_SRC_BONUS:.c=.o)
CLIENT_OBJ_BONUS = $(CLIENT_SRC_BONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(SERVER) $(CLIENT)

$(SERVER): $(SERVER_OBJ)
	$(CC) $(CFLAGS) -o $(SERVER) $(SERVER_OBJ)

$(CLIENT): $(CLIENT_OBJ)
	$(CC) $(CFLAGS) -o $(CLIENT) $(CLIENT_OBJ)

bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS): $(SERVER_OBJ_BONUS)
	$(CC) $(CFLAGS) -o $(SERVER_BONUS) $(SERVER_OBJ_BONUS)

$(CLIENT_BONUS): $(CLIENT_OBJ_BONUS)
	$(CC) $(CFLAGS) -o $(CLIENT_BONUS) $(CLIENT_OBJ_BONUS)

clean:
	rm -f $(SERVER_OBJ) $(CLIENT_OBJ) $(SERVER_OBJ_BONUS) $(CLIENT_OBJ_BONUS)

fclean: clean 
	rm -f $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS)

re: fclean all

.PHONY: all clean fclean re