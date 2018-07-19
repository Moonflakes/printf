# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mthiery <mthiery@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/14 11:37:44 by mthiery           #+#    #+#              #
#    Updated: 2018/04/26 11:02:26 by mthiery          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf

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
		utils_g.c \
		ft_pr.c \
		print_p.c \
		print_a.c \
		print_long_a.c \
		utils_a.c \
		round_nb.c \
		print_flags.c \
		add_plus_space.c \
		htag_process.c \
		color.c

OBJ_PATH = obj/
OBJ = $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

SRC_PATH = srcs/
SRC = $(addprefix $(SRC_PATH),$(SRCS))

PATH_LIB = ../

LIB = libftprintf.a

CC = gcc -g3

CFLAGS = -Wall -Werror -Wextra

all: $(OBJS)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(PATH_LIB)$(LIB)
	@printf "\r\033[K""\r\033[K""\033[1;32mCompilation printf terminée !\033[0m\n"

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@printf "\033[42m \033[0m"
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(PATH_LIB)$(OBJ_PATH)
	
$(LIB):
	@make -j -C $(PATH_LIB)
	@mkdir -p $(OBJ_PATH)

clean:
	@rm -rf $(OBJ_PATH)
	@echo "\033[1;34mFichier printf/obj supprimé.\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;37mProgramme printf détruit\033[0m"

re: fclean all

.PHONY: all clean fclean re
