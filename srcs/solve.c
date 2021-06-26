#include "push_swap.h"

void	do_commands(t_stack *stackA, t_stack *stackB, t_command_list *list,
					int steps_head, int steps_tail)
{
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
	else if (steps_tail < steps_head)
	{
		while (steps_tail--)
			rrn(stackB, "rrb", list);
		pn(stackA, stackB, "pa", list);
	}
}

void	new_do_commands(t_stack *stackA, t_stack *stackB, t_command_list *list,
					t_steps_info steps)
{

	if (steps.steps == 1 && steps.isHead == HEAD)
	{
		sn(stackB, "sb", list);
		pn(stackA, stackB, "pa", list);
	}
	else if (steps.isHead == HEAD)
	{
		while (steps.steps--)
			rn(stackB, "rb", list);
		pn(stackA, stackB, "pa", list);
	}
	else if (steps.isHead == TAIL)
	{
		while (steps.steps--)
			rrn(stackB, "rrb", list);
		pn(stackA, stackB, "pa", list);
	}
	sn(stackA, "sa", list);
}

t_steps_info	compare_for_min(t_steps_info steps_head, t_steps_info steps_tail)
{
	if (steps_head.steps <= steps_tail.steps)
	{
		steps_head.isHead = HEAD;
		return (steps_head);
	}
	steps_tail.isHead = TAIL;
	return (steps_tail);
}

int	find_end_of_range(t_stack *stackA, t_stack_elem *startRange)
{
	t_stack_elem	*ptr;
	int 			endRange;

	endRange = 0;
	ptr = startRange;
	if (ptr->order < ptr->next->order)
		endRange = ptr->next->order;
	else while (ptr->next && ptr->order < ptr->next->order)
	{
		endRange = ptr->order;
		ptr = ptr->next;
	}
	return (endRange);
}

t_steps_info calc_steps_in_b(t_stack *stackB, int startRange, int
endRange)
{
	t_steps_info 	steps_head;
	t_steps_info 	steps_tail;

	steps_head.isHead = -1;
	steps_tail.isHead = -1;
	steps_head.steps = calc_steps(stackB->head, startRange, endRange, HEAD);
	steps_tail.steps = calc_steps(stackB->tail, startRange, endRange, TAIL) + 1;
	return (compare_for_min(steps_head, steps_tail));
}

void	sortToStackA(t_stack *stackA, t_stack *stackB, t_alg_vars *algVars,
					  t_command_list *list)
{
	t_stack_elem	*ptr;
	t_stack_elem 	*startRange;
	int 			endRange;
	t_steps_info	stepsB;

	startRange = stackA->head;
	while (stackB->size)
	{

		endRange = find_end_of_range(stackA, startRange);
		while (endRange == 0)
		{
			startRange = startRange->next;
			endRange = find_end_of_range(stackA, startRange);
		}
		stepsB = calc_steps_in_b(stackB, startRange->order, endRange);
	}
	new_do_commands(stackA, stackB, list, stepsB);
}

void	sendToStackB(t_stack *stackA, t_stack *stackB, t_alg_vars *algVars,
					 t_command_list *list)
{
	while (stackA->size > 2)
	{
		if (stackA->head->order == 1 || stackA->head->order == algVars->max)
			rn(stackA, "ra", list);
		pn(stackB, stackA, "pb", list);
		if (stackB->head->order > algVars->max / 2 && stackB->head->next)
			rn(stackB, "rb", list);
	}
}

void	solve(t_stack *stackA, t_stack *stackB, t_command_list *list,
			  t_alg_vars *algVars)
{
	t_stack_elem *ptr;
	int steps;

	algVars->mid = stackA->size / 2;
	algVars->max = stackA->size;
	algVars->prev_max = stackA->size - 1;
	algVars->next_min = 2;
	sendToStackB(stackA, stackB, algVars, list);
	sortToStackA(stackA, stackB, algVars, list);
	sortToStackA(stackA, stackB, algVars, list);
	sortToStackA(stackA, stackB, algVars, list);
	sortToStackA(stackA, stackB, algVars, list);
	sortToStackA(stackA, stackB, algVars, list);
//	steps = calc_steps(stackA->head, 1, HEAD);
//	if (steps < algVars->mid)
//		while (stackA->head->order != 1)
//			rn(stackA, "ra", list);
//	else
//		while (stackA->head->order != 1)
//			rrn(stackA, "rra", list);
}