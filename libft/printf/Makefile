# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mthiery <mthiery@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/14 11:37:44 by mthiery           #+#    #+#              #
#    Updated: 2018/08/03 15:43:48 by mthiery          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = 	ft_printf.c \
		free_struct.c \
		mallocnb.c \
		mallocchar.c \
		init_struct.c \
		what_arg.c \
		stock_arg.c \
		init_flags.c \
		print_arg.c \
		printing.c \
		print_w.c \
		print_base.c \
		print_f.c \
		print_e.c \
		print_g.c \
		utils_d.c \
		print_p.c \
		print_a.c \
		print_long_a.c \
		utils_a.c \
		round_nb.c \
		print_flags.c \
		add_plus_space.c \
		htag_process.c \
		ht_process_g.c \
		color.c

SRC_PATH = srcs/
SRC = $(addprefix $(SRC_PATH),$(SRCS))

OBJ_PATH = obj/
OBJ = $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

CC = clang $(FLAG)
FLAG = -Wall -Wextra -Werror -g3 #-g -fsanitize=address

all : $(NAME)

$(NAME) : mlibft $(OBJS) 
	@ar rc printf.a $(OBJS)
	@ranlib printf.a
	@libtool -static -o $(NAME) printf.a ../libft.a
	@rm printf.a
	@ranlib $(NAME)
	@printf "\033[ \r\033[K""\r\033[K""\033[1;32mCompilation printf terminée !\033[0m\n"

$(OBJ_PATH)%.o : $(SRC_PATH)%.c includes/printf.h
	@printf "\033[1;42m \033[0m"
	@mkdir -p $(OBJ_PATH)
	@$(CC) -I./includes/ -o $@ -c $<

loading :
	@printf "Compilation en cours...\n"

clean :
	@make -C ../ fclean
	@rm -rf $(OBJ_PATH)
	@echo "\033[1;34mFichier printf/obj supprimé.\033[0m"

fclean : clean
	@rm -f $(NAME)
	@echo "\033[1;37mProgramme printf détruit\033[0m"

mlibft :
	@make -C ../

re : fclean all

.PHONY : all clean fclean re
