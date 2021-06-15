#include "push_swap.h"



void	sendToStackB(int mid, t_stack *stackA, t_stack *stackB,
					 t_command_list *list)
{
	t_stack_elem	*ptr;
	int steps_head;
	int steps_tail;

//	ptr = stackA->head;
//	if (ptr->order < mid)
//		pn(stackB, stackA, "pb", list);
//	else if (ptr->next->order < mid)
//	{
//		sn(stackA, "sa", list);
//		pn(stackB, stackA, "pb", list);
//	}
//	else if (stackA->tail->order < mid)
//	{
//		rrn(stackA, "rra", list);
//		pn(stackB, stackA, "pb", list);
//	}
//	else
//	{
		while (is_there_lower_than_mid(stackA, mid))
		{
			steps_head = 0;
			steps_tail = 1;
			ptr = stackA->head;
			while (ptr->order > mid)
			{
				ptr = ptr->next;
				steps_head++;
			}
			ptr = stackA->tail;
			while (ptr->order > mid)
			{
				ptr = ptr->previous;
				steps_tail++;
			}
			if (steps_head <= steps_tail)
			{
				while (steps_head--)
					rn(stackA, "ra", list);
				pn(stackB, stackA, "pb", list);
			}
			else if (steps_tail < steps_head)
			{
				while (steps_tail--) // ?
					rrn(stackA, "rra", list);
				pn(stackB, stackA, "pb", list);
			}
	//	}
		//проверять сколько раз придется скинуть вниз или вверх, где меньше,
		// то делать
	}
}

void	solve(t_stack *stackA, t_stack *stackB, t_command_list *list)
{
	int	next_to_sort;
	int max;
	int mid;

	next_to_sort = 1;
	max = stackA->size;
	mid = (max / 2) + next_to_sort;
	sendToStackB(mid, stackA, stackB, list);
}


