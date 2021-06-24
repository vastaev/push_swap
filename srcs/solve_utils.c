#include "push_swap.h"

int	calc_steps(t_stack_elem *ptr, int next_to_sort, int flag)
{
	int				steps;
	t_stack_elem	*tmp;

	tmp = ptr;
	steps = 0;
	while (tmp && tmp->order != next_to_sort)
	{
		steps++;
		if (flag)
			tmp = tmp->next;
		else
			tmp = tmp->previous;
	}
	return (steps);
}
