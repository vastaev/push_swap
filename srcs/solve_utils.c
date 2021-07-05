#include "push_swap.h"

int	to_compare(int num1, int num2)
{
	if (num1 > num2)
		return (num1);
	return (num2);
}

void	finish_sort_a(t_stack *stackA, t_alg_vars *algVars, t_command_list
*list)
{
	t_stack_elem	*ptr;
	int				steps;

	ptr = stackA->head;
	steps = 0;
	while (ptr->order != 1)
	{
		steps++;
		ptr = ptr->next;
	}
	if (steps < algVars->mid)
		while (stackA->head->order != 1)
			rn(stackA, "ra", list);
	else
		while (stackA->head->order != 1)
			rrn(stackA, "rra", list);
}
