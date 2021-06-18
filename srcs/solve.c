#include "push_swap.h"

int	is_there_more_than_mid(t_stack *stack, t_alg_vars *algVars)
{
	t_stack_elem	*ptr;

	ptr = stack->head;
	while (ptr)
	{
		if (ptr->order >= algVars->mid)
			return (1);
		ptr = ptr->next;
	}
	return (0);
}

void	sendNext(t_alg_vars *algVars, t_stack *stackA, t_stack *stackB,
				 t_command_list *list)
{
	t_stack_elem	*ptr;

	ptr = stackB->head;
	while (ptr->order != algVars->next_to_sort)
		ptr = ptr->next;
	

}

void	sendToStackA(t_alg_vars *algVars, t_stack *stackA, t_stack *stackB,
					 t_command_list *list) // можно сделать одну функцию
{
	t_stack_elem	*ptr;
	int steps_head;
	int steps_tail;

	while (is_there_more_than_mid(stackB, algVars)) //maybe can be
		// optimized
	{
		steps_head = 0;
		steps_tail = 1;
		ptr = stackB->head;
		while (ptr && ptr->order < algVars->mid)
		{
//			if (ptr->order == algVars->next_to_sort)
//			{
//				pn(stackA, stackB, "pa", list);
//				rn(stackA, "ra", list);
//				algVars->flag++;
//				return ;
//			}
			ptr = ptr->next;
			steps_head++;
		}
		ptr = stackB->tail;
		while (ptr && ptr->order < algVars->mid)
		{
			ptr = ptr->previous;
			steps_tail++;
		}
		if (steps_head <= steps_tail)
		{
			while (steps_head--)
				rn(stackB, "rb", list);
			stackB->head->flag = algVars->flag;
			pn(stackA, stackB, "pa", list);
		}
		else if (steps_tail < steps_head)
		{
			while (steps_tail--) // ?
				rrn(stackB, "rrb", list);
			stackB->head->flag = algVars->flag;
			pn(stackA, stackB, "pa", list);
		}
	}
}

void	sendToStackB(t_alg_vars *algVars, t_stack *stackA, t_stack *stackB,
					 t_command_list *list)
{
	t_stack_elem	*ptr;
	int steps_head;
	int steps_tail;

	while (is_there_lower_than_mid(stackA, algVars)) //maybe can be optimized
	{
		steps_head = 0;
		steps_tail = 1;
		ptr = stackA->head;
		while (ptr->order > algVars->mid)
		{
			ptr = ptr->next;
			steps_head++;
		}
		ptr = stackA->tail;
		while (ptr->order > algVars->mid)
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
	}
}

void	solve(t_stack *stackA, t_stack *stackB, t_command_list *list,
			  t_alg_vars *algVars)
{
	algVars->next_to_sort = 1;
	algVars->max = stackA->size;
	algVars->mid = (algVars->max / 2) + algVars->next_to_sort;
	sendToStackB(algVars, stackA, stackB, list);
//	while (stackB->head)
//	{
//		algVars->max = stackB->size;
//		algVars->mid = ((algVars->max - (algVars->next_to_sort + 1)) / 2) +
//					   algVars->next_to_sort + 1;
//		sendToStackA(algVars, stackA, stackB, list);
//	}
	algVars->max = stackB->size;
	algVars->mid = ((algVars->max - (algVars->next_to_sort + 1)) / 2) +
				   algVars->next_to_sort + 1;
	sendToStackA(algVars, stackA, stackB, list);
	algVars->next_to_sort++;
}


