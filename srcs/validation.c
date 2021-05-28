#include "../includes/push_swap.h"
#include "../libs/libft/libft.h"

int			check_for_number(char *str);
int			split_len(char **s);
void		free_split(char **s);

int	validation_of_args(int argc, char **argv)
{
	size_t	i;

	i = argc;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		i = split_len(argv);
	}
	while (--i + (argc == 2))
	{
		if (check_for_number(argv[i]) == 0)
			return (-1);
	}
	if (argc == 2)
		free_split(argv);
	return (0);
}

int error_msg(void)
{
	write(2, "Error\n", 6);
	return (0);
}

int	split_len(char **s)
{
	int	counter;

	counter = 0;
	while (s[counter] != '\0')
		counter++;
	return (counter);
}

void	free_split(char **s)
{
	int len;
	
	len = split_len(s);
	while (len--)
	{
		free(s[len]);
		s[len] = NULL;
	}
	free(s);
	s = NULL;
}

int	check_for_number(char *str)
{
	int	i;

	i = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		str++;
		i++;
	}
	while (ft_isdigit(*str) && i < 11)
	{
		str++;
		i++;
	}
	if (*str == '\0')
		return (1);
	else
		return (error_msg());
}
