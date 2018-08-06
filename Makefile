all : lautre libft/printf/srcs/main.c
	@gcc libft/printf/srcs/main.c libft/printf/libftprintf.a -I./libft/printf/includes/ -o ft_printf

lautre :
	@make -C libft/printf

clean :
	@make -C libft/printf clean

fclean :
	@make -C libft/printf fclean
	@rm -rf ft_printf

curqui :
	cp libft/printf/libftprintf.a ../curqui_test
	@make -C ../curqui_test && ./../curqui_test/ft_printf_tests

re : fclean all
