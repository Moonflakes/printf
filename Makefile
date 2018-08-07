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
	cp libft/printf/libftprintf.a ../my_curqui_test
	@make -C ../my_curqui_test && ./../my_curqui_test/ft_printf_tests

recurqui :
	@make re -C ../my_curqui_test

re : fclean all
