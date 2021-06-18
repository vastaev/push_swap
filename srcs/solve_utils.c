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

