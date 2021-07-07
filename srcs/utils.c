#include "push_swap.h"

void	*error_msg(void)
{
	write(2, "Error\n", 6);
	exit(-1);
}

void	free_stack_and_array(t_stack *stack, int *array, int flag)
{
	free_stack(stack);
	free(array);
	if (flag == 1)
		error_msg();
	else
		exit(0);
}

int	is_sorted(const int *array, int size)
{
	int	flag;
	int	i;

	i = 0;
	flag = 0;
	while (i < size - 1)
	{
		if (array[i] > array[i + 1])
			flag++;
		i++;
	}
	if (flag == 0)
		return (1);
	return (0);
}
