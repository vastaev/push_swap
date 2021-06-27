#include "push_swap.h"

int	calc_steps_b(t_stack_elem *ptr, int startRange, int endRange, int flag)
{
	int				steps;
	t_stack_elem	*tmp;

	tmp = ptr;
	steps = 0;
	while (tmp && (tmp->order < startRange || tmp->order > endRange))
	{
		steps++;
		if (flag)
			tmp = tmp->next;
		else
			tmp = tmp->previous;
	}
	return (steps);
}

int	calc_steps_a(t_stack_elem *ptr, int startRange, int flag)
{
	int				steps;
	t_stack_elem	*tmp;

	tmp = ptr;
	steps = 0;
	while (tmp && tmp->order != startRange)
	{
		steps++;
		if (flag)
			tmp = tmp->next;
		else
			tmp = tmp->previous;
	}
	return (steps);
}