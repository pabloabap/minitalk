# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pabad-ap <pabad-ap@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/21 13:55:08 by pabad-ap          #+#    #+#              #
#    Updated: 2023/10/21 13:55:17 by pabad-ap         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC      = gcc
CFLAGS = -Wall -Wextra -Werror

SOURCES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	  ft_toupper.c ft_tolower.c ft_strlen.c ft_strchr.c ft_strrchr.c \
	  ft_strncmp.c ft_memset.c ft_bzero.c ft_memchr.c ft_memcpy.c ft_memcmp.c ft_memmove.c \
	  ft_strlcpy.c ft_strlcat.c ft_strnstr.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
	  ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c \
	  ft_char_formater.c ft_str_formater.c ft_pointer_formater.c ft_int_formater.c\
	  ft_uint_formater.c ft_hex_formater.c ft_upperhex_formater.c \
	  ft_printf.c

SOURCES_BONUS = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c

OBJS = $(SOURCES:.c=.o)

OBJS_BONUS = $(SOURCES_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c libft.h Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)
	
re: fclean all

bonus: $(OBJS_BONUS)
	ar rcs $(NAME) $(OBJS_BONUS)

.PHONY: all clean fclean re
