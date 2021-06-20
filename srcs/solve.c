#include "push_swap.h"

void	sendToStackA(t_alg_vars *algVars, t_stack *stackA, t_stack *stackB,
					 t_command_list *list)
{
	int				steps_head;
	int				steps_tail;

	while (stackB->size)
	{
		steps_head = calculate_steps(stackB->head, algVars->next_to_sort, HEAD);
		steps_tail = calculate_steps(stackB->tail, algVars->next_to_sort,
									 TAIL) + 1;
		if (steps_head == 1)
		{
			sn(stackB, "sb", list);
			pn(stackA, stackB, "pa", list);
		}
		else if (steps_head <= steps_tail)
		{
			while (steps_head--)
				rn(stackB, "rb", list);
			pn(stackA, stackB, "pa", list);
		}
		else
		{
			while (steps_tail--)
				rrn(stackB, "rrb", list);
			pn(stackA, stackB, "pa", list);
		}
		algVars->next_to_sort--;
	}
}

void	sendToStackB(t_alg_vars *algVars, t_stack *stackA, t_stack *stackB,
					 t_command_list *list)
{
	while (stackA->size > 1)
	{
		if (stackA->head->order == algVars->max)
			rn(stackA, "ra", list);
		pn(stackB, stackA, "pb", list);
		if (stackB->head->order < algVars->max / 2 && stackB->head->next)
			rn(stackB, "rb", list);
	}
}

void	solve(t_stack *stackA, t_stack *stackB, t_command_list *list,
			  t_alg_vars *algVars)
{
	algVars->mid = stackA->size / 2;
	algVars->max = stackA->size;
	sendToStackB(algVars, stackA, stackB, list);
	sendToStackA(algVars, stackA, stackB, list);
}