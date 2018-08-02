all : lautre libft/printf/srcs/main.c
	@gcc libft/printf/srcs/main.c libft/libftprintf.a -o ft_printf

lautre :
	@make -C libft

clean :
	@make -C libft clean

fclean :
	@make -C libft fclean
	@rm -rf ft_printf

re : fclean all