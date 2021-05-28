//part1
#include "libft.h"

int	ft_atoi(const char *str)
{
	int	shag;
	int	res;
	int	minus;

	minus = 0;
	res = 0;
	shag = 0;
	while (ft_isspace(str[shag]))
		shag++;
	if (str[shag] == '-')
		minus = 1;
	if ((str[shag] == '-') || (str[shag] == '+'))
		shag++;
	while (ft_isdigit(str[shag]))
	{
		res = res * 10 + (str[shag] - '0');
		shag++;
	}
	if (minus == 1)
		return (-res);
	else
		return (res);
}
