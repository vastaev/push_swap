#include "push_swap.h"

int	check_argv_dups(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	free_all(t_stack *stackA, t_stack *stackB, t_command_list *list)
{
	free_stack(stackA);
	free_stack(stackB);
	free_commands(list);
}

int	is_list_sorted(t_stack *stackA)
{
	t_stack_elem	*ptr;
	int				i;

	i = 0;
	ptr = stackA->head;
	while (i < stackA->size - 1)
	{
		if (ptr->value > ptr->next->value)
			return (FALSE);
		ptr = ptr->next;
		i++;
	}
	return (TRUE);
}
