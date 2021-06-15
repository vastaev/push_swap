#include "push_swap.h"

int	is_there_lower_than_mid(t_stack *stackA, int mid)
{
	t_stack_elem	*ptr;

	ptr = stackA->head;
	while (ptr)
	{
		if (ptr->order <= mid)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}
