#include "push_swap.h"
#include "libft.h"
#include "limits.h"

static int			check_for_number(char *str);
static int			split_len(char **s);
static void			free_split(char **s);
int					*bubble_sort(int *arrayOfNumbers, int size);

int	*validation_of_args(int argc, char **argv)
{
	size_t	i;
	size_t	j;
	int		*arrayOfNumbers;

	i = argc;
	j = 0;
	arrayOfNumbers = malloc(sizeof(int) * argc - 1);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		i = split_len(argv);
	}
	while (--i + (argc == 2))
	{
		check_for_number(argv[i]);
		arrayOfNumbers[j++] = (int)ft_atoi(argv[i]);
	}
	if (argc == 2)
		free_split(argv);
	arrayOfNumbers = bubble_sort(arrayOfNumbers, argc - 1);
	return (arrayOfNumbers);
}

int	*bubble_sort(int *arrayOfNumbers, int size)
{
	int	i;
	int	j;
	int tmp;

	tmp = 0;
	i = 0;
	j = size - 1;
	while (i < size - 1)
	{
		while (j > i)
		{
			if (arrayOfNumbers[j - 1] > arrayOfNumbers[j])
			{
				tmp = arrayOfNumbers[j];
				arrayOfNumbers[j] = arrayOfNumbers[j - 1];
				arrayOfNumbers[j - 1] = tmp;
			}
			j--;
		}
		i++;
	}
	return (arrayOfNumbers);
}

static int	split_len(char **s)
{
	int	counter;

	counter = 0;
	while (s[counter] != '\0')
		counter++;
	return (counter);
}

static void	free_split(char **s)
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

static int	check_for_number(char *str)
{
	long long	num;

	num = ft_atoi(str);
	if (num < INT_MIN || num > INT_MAX)
		return (error_msg());
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
		str++;
	if (*str == '\0')
		return (1);
	else
		return (error_msg());
}
