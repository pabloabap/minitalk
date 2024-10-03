#___CABECERA!!!___

#Nombre del programa
LIBFT	= ./libft/libft.a
CLIENT	= client
SERVER	= server

CC	= gcc
CFLAGS	= -Wall -Wextra -Werror

CLIENT_SRCS	= ./client.c
CLIENT_OBJ	= $(CLIENT_SRCS:.c=.o)

SERVER_SRCS	= ./server.c
SERVER_OBJ	= $(SERVER_SRCS:.c=.o)

all: $(SERVER) $(CLIENT)

$(LIBFT): ./libft/*.c ./libft/*.h ./libft/Makefile
	$(MAKE) -C ./libft
$(SERVER): $(LIBFT) $(SERVER_OBJ) Makefile
	$(CC) -g $(CFLAGS) $(SERVER_OBJ) -L./libft/ -lft -o server
$(CLIENT): $(LIBFT) $(CLIENT_OBJ) Makefile
	$(CC) -g $(CFLAGS) $(CLIENT_OBJ) -L./libft/ -lft -o client

clean:
	make clean -C ./libft
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ)
fclean: clean
	make fclean -C ./libft
	rm -f $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re
