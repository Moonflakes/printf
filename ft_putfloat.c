#include <unistd.h>
#include <stdio.h>

void	ft_putnbr_fd(long long n, int fd)
{
	char				value;
	unsigned long long	cast;

	cast = n < 0 ? -n : n;
	if (n < 0)
		write(fd, "-", 1);
	if (cast > 9)
		ft_putnbr_fd(cast / 10, fd);
	value = '0' + cast % 10;
	write(fd, &value, 1);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putfloat_fd(long double f, int precis, int fd)
{
	uint64_t	a;
	int			i;

	a = 10;
	(uint64_t)f == 0 && f < 0 ? ft_putchar_fd('-', fd) : 0;
	ft_putnbr_fd((long long)f, fd);
	ft_putchar_fd('.', fd);
	f < 0 ? f = -f : 0;
	f -= (uint64_t)f;
	i = 0;
	while (++i < precis)
	{
		f *= 10;
		ft_putnbr_fd((int)f, 1);
		f -= (int)f;
	}
	f *= 10;
	if ((f - (int)f) * 10 >= 5)
		f += 1;
	ft_putnbr_fd((int)f, 1);
}

void	ft_putfloat(long double f, int precis)
{
	ft_putfloat_fd(f, precis, 1);
}

int		main(void)
{
	ft_putfloat(-0.0004745, 12);
	printf("\n%.12f\n", -0.0004745);
}
