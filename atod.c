#include <stdio.h>
#include <unistd.h>

double ft_atod(char *str)
{
	double	left;
	double	right;
	int		sign;

	sign = 1;
	left = 0;
	right = 0;
	while (*str == ' ' || *str == '+')
		str++;
	if (*str == '-')
		sign = -1;
	while (str && *str != '.')
	{
		left = left * 10 + *str;
		str++;
	}
	return ((left + right) * sign);
}

int main(void)
{
	double n;

	n = ft_atod("123");
	printf("%f\n", n);
	return (0);
}
