all : lautre libft/printf/srcs/main.c
	@gcc libft/printf/srcs/main.c libft/printf/libftprintf.a -o ft_printf

lautre :
	@make -C libft/printf

clean :
	@make -C libft/printf clean

fclean :
	@make -C libft/printf fclean
	@rm -rf ft_printf

re : fclean all
