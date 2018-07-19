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
	   mon_itoabase.c \
	   ft_recursive_power.c \
	   ft_iterative_power.c \
	   ft_iterative_power_double.c \
	   ft_power_double.c \
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
	   ft_lstmap.c

SRC_PATH = srcs_lib/
OBJ_PATH = obj/

NAME = libftprintf.a
FLAG = -Wall -Wextra -Werror
OBJ_NAME = $(SRCS:.c=.o)
CC = clang $(FLAG)
SRC = $(addprefix $(SRC_PATH),$(SRCS))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
POBJ = ft_printf.c \
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
POBJS = $(POBJ:.c=.o)
PROBJS = $(addprefix printf/obj/, $(POBJS))


all : $(NAME)

$(NAME) :  $(OBJ) PROBJ
	@ar rc $(NAME) $(OBJ) $(PROBJS)
	@ranlib $(NAME)
	@printf "\033[\1A \r\033[K""\r\033[K""\033[32mCompilation libft terminée !\033[0m\n"

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@printf "\033[42m \033[0m"
	@mkdir -p $(OBJ_PATH)
	@$(CC) -I./includes -o $@ -c $<

PROBJ :
	@make -C printf/

loading :
	@printf "Compilation en cours...\n"

clean :
	@rm -rf $(OBJ_PATH)
	@echo "\033[0;34mFichier libft/obj supprimé.\033[0m"

fclean : clean
	@rm -f $(NAME)
	@echo "\033[1;37mLibrairie detruite.\033[0m"
	@$(MAKE) fclean -C printf

norm :
	@norminette srcs/ includes/

header :
	cp includes/libft.h ./

re : fclean
	@$(MAKE) all
