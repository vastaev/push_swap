#include "push_swap.h"

//int	dist_from_min(t_stack *deck_a, int order)
//{
//	int	i;
//
//	i = 0;
//	while (deck_a)
//	{
//		if (deck_a->index == order)
//			return (i);
//		i++;
//		deck_a = deck_a->next;
//	}
//	return (i);
//}

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

int	compare_for_min(int steps_head, int steps_tail)
{
	if (steps_head <= steps_tail)
		return (steps_head);
	return (steps_tail);
}

void	sortToStackA(t_stack *stackA, t_stack *stackB, t_alg_vars *algVars,
					  t_command_list *list)
{
	int	steps_max_head;
	int	steps_max_tail;
	int	steps_min_head;
	int	steps_min_tail;
	int min_for_max;
	int	min_for_min;

	while (stackB->size)
	{
		steps_max_head = calc_steps(stackB->head, algVars->prev_max, HEAD);
		steps_max_tail = calc_steps(stackB->tail, algVars->prev_max, TAIL) + 1;
		min_for_max = compare_for_min(steps_max_head, steps_max_tail);
		steps_min_head = calc_steps(stackB->head, algVars->next_min, HEAD);
		steps_min_tail = calc_steps(stackB->tail, algVars->next_min, TAIL) + 1;
		min_for_min = compare_for_min(steps_min_head, steps_min_tail);
		if (min_for_max <= min_for_min)
		{
			do_commands(stackA, stackB, list, steps_max_head, steps_max_tail);
			algVars->prev_max--;
		}
		else if (min_for_min < min_for_max)
		{
			do_commands(stackA, stackB, list, steps_min_head, steps_min_tail);
			rn(stackA, "ra", list);
			algVars->next_min++;
		}
	}
}

void	sendToStackB(t_stack *stackA, t_stack *stackB, t_alg_vars *algVars,
					 t_command_list *list)
{
	while (stackA->size > 2)
	{
		if (stackA->head->order == algVars->max || stackA->head->order == 1)
			rn(stackA, "ra", list);
		pn(stackB, stackA, "pb", list);
		if (stackB->head->order > algVars->max / 2 && stackB->head->next)
			rn(stackB, "rb", list);
	}
	if (stackA->head->order == 1)
		sn(stackA, "sa", list);
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
	steps = calc_steps(stackA->head, 1, HEAD);
	if (steps < algVars->mid)
		while (stackA->head->order != 1)
			rn(stackA, "ra", list);
	else
		while (stackA->head->order != 1)
			rrn(stackA, "rra", list);
}