#include "push_swap.h"

static t_steps_info	*init_struct_info(void)
{
	t_steps_info	*minInfo;

	minInfo = (t_steps_info *)malloc(sizeof(t_steps_info));
	if (NULL == minInfo)
		error_msg();
	minInfo->directionA = R;
	minInfo->directionB = R;
	minInfo->elemA = NULL;
	minInfo->elemB = NULL;
	minInfo->isSet = FALSE;
	minInfo->steps = 0;
	return (minInfo);
}

static void	move_b(t_stack *stackA, t_stack *stackB, t_steps_info *minInfo,
			   t_command_list *list)
{
	while (minInfo->elemA != stackA->head || minInfo->elemB != stackB->head)
	{
		if (minInfo->directionA == minInfo->directionB
			&& minInfo->elemA != stackA->head && minInfo->elemB != stackB->head)
		{
			if (minInfo->directionA == R)
				rr(stackA, stackB, "rr", list);
			else
				rrr(stackA, stackB, "rrr", list);
		}
		else if (minInfo->elemA != stackA->head)
		{
			if (minInfo->directionA == R)
				rn(stackA, "ra", list);
			else
				rrn(stackA, "rra", list);
		}
		else if (minInfo->elemB != stackB->head)
		{
			if (minInfo->directionB == R)
				rn(stackB, "rb", list);
			else
				rrn(stackB, "rrb", list);
		}
	}
}

static void	sortToStackA(t_stack *stackA, t_stack *stackB, t_alg_vars *algVars,
					 t_command_list *list)
{
	t_steps_info	*minInfo;

	minInfo = init_struct_info();
	while (stackB->size)
	{
		minInfo->isSet = FALSE;
		calc_steps(stackA, stackB, algVars, minInfo);
		move_b(stackA, stackB, minInfo, list);
		pn(stackA, stackB, "pa", list);
	}
	free(minInfo);
}

static void	sendToStackB(t_stack *stackA, t_stack *stackB, t_alg_vars *algVars,
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

void	solve(t_stack *stackA, t_stack *stackB, t_command_list *list)
{
	t_alg_vars		*algVars;

	algVars = (t_alg_vars *)malloc(sizeof(t_alg_vars));
	algVars->mid = stackA->size / 2;
	algVars->max = stackA->size;
	sendToStackB(stackA, stackB, algVars, list);
	sortToStackA(stackA, stackB, algVars, list);
	finish_sort_a(stackA, algVars, list);
	free(algVars);
}
