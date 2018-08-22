#include <stdio.h>
#include <string.h>

int	main(void)
{
	//double	i = -0.;
	long double	i = -0.0;
	int		u;

	//u = *(((int *)&i) + 1);
	u = *(((size_t *)&i) + 1);
	if (u == 0)
		printf("Le nombre est égale à 0\n");
	else
		printf("Le nombre est égale à -0\n");
	printf("u = %d\n", u);
	return (0);
}
