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

void	do_commands_a(t_stack *stackA, t_stack *stackB, t_command_list *list,
					  t_steps_info steps)
{
	if (steps.stepsA == 1 && steps.isHeadA == HEAD)
	{
		sn(stackB, "sa", list);
	}
	else if (steps.isHeadA == HEAD)
	{
		while (steps.stepsA--)
			rn(stackA, "ra", list);
	}
	else if (steps.isHeadA == TAIL)
	{
		while (steps.stepsA--)
			rrn(stackB, "rra", list);
	}
}

void	new_do_commands(t_stack *stackA, t_stack *stackB, t_command_list *list,
					t_steps_info steps)
{
	do_commands_a(stackA, stackB, list, steps);
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

int	find_end_of_range(t_stack *stackA, t_stack_elem *startRange)
{
	t_stack_elem	*ptr;
	int 			endRange;

	endRange = 0;
	ptr = startRange;
	if (!ptr || !ptr->next)
		return (-1);
	else if (ptr->order < ptr->next->order)
		endRange = ptr->next->order;
	else while (ptr && ptr->next && ptr->order < ptr->next->order)
	{
		endRange = ptr->order;
		ptr = ptr->next;
	}
	return (endRange);
}

t_steps_info	get_min(t_stack *stackA, t_stack *stackB, t_steps_info
minInfo,
			   int startRange, int endRange)
{
	t_stack_elem	*ptr;
	int	steps_head;
	int	steps_tail;
	int steps_head_a;
	int steps_tail_a;

	steps_head = calc_steps_b(stackB->head, startRange, endRange, HEAD);
	steps_tail = calc_steps_b(stackB->tail, startRange, endRange, TAIL) + 1;
	if (steps_head <= steps_tail)
	{
		minInfo.isHead = HEAD;
		minInfo.steps = steps_head;
	}
	else
	{
		minInfo.isHead = TAIL;
		minInfo.steps = steps_tail;
	}
	steps_head_a = calc_steps_a(stackA->head, startRange, HEAD);
	steps_tail_a = calc_steps_a(stackB->head, startRange, TAIL) + 1;
	if (steps_head_a <= steps_tail_a)
	{
		minInfo.isHeadA = HEAD;
		minInfo.stepsA = steps_head_a;
	}
	else
	{
		minInfo.isHeadA = TAIL;
		minInfo.stepsA = steps_tail_a;
	}
	minInfo.sumSteps = minInfo.steps + minInfo.stepsA;
	return (minInfo);
}

t_steps_info init_struct_info(void)
{
	t_steps_info	minInfo;

	minInfo.steps = -1;
	minInfo.isHead = -1;
	minInfo.stepsA = -1;
	minInfo.isHeadA = -1;
	minInfo.sumSteps = 42;
	minInfo.minA = NULL;
	return (minInfo);
}

t_stack_elem *move_startRange(t_stack *stackA, int endRange)
{
	t_stack_elem *ptr;

	ptr = stackA->head;
	while (ptr->order != endRange)
	{
		if (ptr->next == NULL)
			return (NULL);
		ptr = ptr->next;
	}
	return (ptr->next);
}

void	sortToStackA(t_stack *stackA, t_stack *stackB, t_alg_vars *algVars,
					  t_command_list *list)
{
	t_stack_elem 	*startRange;
	int 			endRange;
	t_steps_info	minInfo;
	t_steps_info	newMinInfo;


	while (stackB->size)
	{
		minInfo = init_struct_info();
		startRange = stackA->head;
		while (startRange && startRange->next)
		{
			endRange = find_end_of_range(stackA, startRange);
			while (endRange == 0) // is it needed? maybe if?
			{
				startRange = startRange->next;
				endRange = find_end_of_range(stackA, startRange);
			}
			newMinInfo = get_min(stackA, stackB,minInfo,
								 startRange->order, endRange);
			if (newMinInfo.sumSteps < minInfo.sumSteps)
				minInfo = newMinInfo;
			//move to next element of end of range
			startRange = move_startRange(stackA, endRange);
		}
		new_do_commands(stackA, stackB, list, minInfo);
	}
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
//	steps = calc_steps_b(stackA->head, 1, HEAD);
//	if (steps < algVars->mid)
//		while (stackA->head->order != 1)
//			rn(stackA, "ra", list);
//	else
//		while (stackA->head->order != 1)
//			rrn(stackA, "rra", list);
}