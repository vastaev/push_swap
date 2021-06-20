#include "push_swap.h"

int	is_there_lower_than_mid(t_stack *stack, t_alg_vars *algVars)
{
	t_stack_elem	*ptr;

	ptr = stack->head;
	while (ptr)
	{
		if (ptr->order == algVars->next_to_sort)
			return (2);
		if (ptr->order <= algVars->mid)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

int	calculate_steps(t_stack_elem *ptr, int next_to_sort, int flag)
{
	int	steps;

	steps = 0;
	while (ptr->order != next_to_sort)
	{
		steps++;
		if (flag)
			ptr = ptr->next;
		else
			ptr = ptr->previous;
	}
	return (steps);
}
