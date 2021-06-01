//part2
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	step;

	step = 0;
	if (s != NULL)
	{
		while (s[step] != '\0')
		{
			write(fd, &s[step], 1);
			step++;
		}
	}
}
