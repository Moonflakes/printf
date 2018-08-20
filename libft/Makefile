# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mthiery <mthiery@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 11:28:20 by mthiery           #+#    #+#              #
#    Updated: 2018/04/26 11:19:40 by mthiery          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_bzero.c \
	   ft_putchar.c \
	   ft_putchar_fd.c \
	   ft_putnbr.c \
	   ft_putnbr_fd.c \
	   ft_putunbr.c \
	   ft_putstr.c \
	   ft_putstr_fd.c \
	   ft_putendl.c \
	   ft_putendl_fd.c \
	   ft_atoi.c \
	   ft_itoa.c \
	   ft_dtoa.c \
	   ft_itoabase.c \
	   ft_uitoabase.c \
	   ft_recursive_power.c \
	   ft_iterative_power.c \
	   ft_iterative_power_double.c \
	   ft_power_double.c \
	   ft_nblen.c \
	   ft_range.c \
	   ft_strlen.c \
	   ft_strdup.c \
	   ft_strndup.c \
	   ft_strdup_free.c \
	   ft_strdup_del.c \
	   ft_strcpy.c \
	   ft_strncpy.c \
	   ft_strcat.c \
	   ft_strncat.c \
	   ft_strlcat.c \
	   ft_strchr.c \
	   ft_strrchr.c \
	   ft_strstr.c \
	   ft_strnstr.c \
	   ft_strcmp.c \
	   ft_strncmp.c \
	   ft_strrev.c \
	   ft_strcapitalize.c \
	   ft_strnew.c \
	   ft_strdel.c \
	   ft_strclr.c \
	   ft_striter.c \
	   ft_striteri.c \
	   ft_strmap.c \
	   ft_strmapi.c \
	   ft_strequ.c \
	   ft_strnequ.c \
	   ft_strsub.c \
	   ft_strsub_free.c \
	   ft_strjoin.c \
	   ft_strjoin_free.c\
	   ft_strtrim.c \
	   ft_strsplit.c \
	   ft_memset.c \
	   ft_memcpy.c \
	   ft_memccpy.c \
	   ft_memmove.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_memalloc.c \
	   ft_memdel.c \
	   ft_isalpha.c \
	   ft_islower.c \
	   ft_isupper.c \
	   ft_isdigit.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_lstnew.c \
	   ft_lstdelone.c \
	   ft_lstdel.c \
	   ft_lstadd.c \
	   ft_lstiter.c \
	   ft_lstmap.c \
	   nbase_len.c

SRC_PATH = srcs_lib/
SRC = $(addprefix $(SRC_PATH),$(SRCS))

OBJ_PATH = obj/
OBJ_NAME = $(SRCS:.c=.o)
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

CC = clang $(FLAG)
FLAG = -Wall -Wextra -Werror -g3 #-g -fsanitize=address

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@printf "\033[ \r\033[K""\r\033[K""\033[32mCompilation libft terminée !\033[0m\n"

$(OBJ_PATH)%.o : $(SRC_PATH)%.c includes/libft.h
	@printf "\033[42m \033[0m"
	@mkdir -p $(OBJ_PATH)
	@$(CC) -I./includes -o $@ -c $<

loading :
	@printf "Compilation en cours...\n"

clean :
	@rm -rf $(OBJ_PATH)
	@echo "\033[0;34mFichier libft/obj supprimé.\033[0m"

fclean : clean
	@rm -f $(NAME)
	@echo "\033[1;37mLibrairie detruite.\033[0m"

norm :
	@norminette srcs/ includes/

#header :
#	cp includes/libft.h ./

re : fclean all
