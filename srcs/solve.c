#include "push_swap.h"

t_steps_info *init_struct_info(void)
{
	t_steps_info	*minInfo;

	minInfo = (t_steps_info *)malloc(sizeof(t_steps_info));
	if (NULL == minInfo)
		error_msg();
	minInfo->directionA = R;
	minInfo->directionB = R;
	minInfo->elemA = NULL;
	minInfo->elemB = NULL;
	minInfo->isSet = false;
	minInfo->steps = 0;
	return (minInfo);
}

t_stack_elem *find_elem_a(t_stack *stackA, int order, t_alg_vars *algVars)
{
	t_stack_elem	*ptr;

	ptr = stackA->head;
	if (order < ptr->order)
	{
		while (order < ptr->previous->order
		&& ptr->order > ptr->previous->order)
			ptr = ptr->previous;
	}
	else
	{
		while (order > ptr->order
		&& ptr->order < ptr->next->order)
			ptr = ptr->next;
		if (order > ptr->order && ptr->order > ptr->next->order)
			ptr = ptr->next;
	}
	return (ptr);
}

void	count_steps(t_stack *stack, int order, int *rn_size, int *rrn_size)
{
	t_stack_elem	*ptr;

	if (stack && stack->head)
	{
		ptr = stack->head;
		while (ptr->order != order)
		{
			(*rn_size)++;
			ptr = ptr->next;
		}
		ptr = stack->tail;
		while (ptr->order != order)
		{
			(*rrn_size)++;
			ptr = ptr->previous;
		}
	}
}

int	to_compare(int num1, int num2)
{
	if (num1 > num2)
		return (num1);
	return (num2);
}

void	set_best_direction(int steps, t_steps_info newInfo, t_steps_info
*minInfo)
{
	if (!minInfo->isSet || steps < minInfo->steps)
	{
		minInfo->elemA = newInfo.elemA;
		minInfo->elemB = newInfo.elemB;
		minInfo->directionA = newInfo.directionA;
		minInfo->directionB = newInfo.directionB;
		minInfo->steps = steps;
		minInfo->isSet = true;
	}
}

void	best_direction(t_steps_info *minInfo, t_stack_elem *elemB, t_alg_vars
*algVars, t_stack *stackA, t_stack *stackB)
{
	t_steps_info	newInfo;
	int				ra_size;
	int				rra_size;
	int				rb_size;
	int				rrb_size;

	ra_size = 0;
	rra_size = 0;
	rb_size = 0;
	rrb_size = 0;
	newInfo.elemA = find_elem_a(stackA, elemB->order, algVars);
	newInfo.elemB = elemB;
	count_steps(stackA, newInfo.elemA->order, &ra_size, &rra_size);
	count_steps(stackB, newInfo.elemB->order, &rb_size, &rrb_size);
	newInfo.directionA = R;
	newInfo.directionB = R;
	set_best_direction(to_compare(ra_size, rb_size), newInfo, minInfo);
	newInfo.directionA = RR;
	set_best_direction(rra_size + rb_size, newInfo, minInfo);
	newInfo.directionB = RR;
	set_best_direction(to_compare(rra_size, rrb_size), newInfo, minInfo);
	newInfo.directionA = R;
	set_best_direction(ra_size + rrb_size, newInfo, minInfo);
}

void	calc_steps(t_stack *stackA, t_stack *stackB, t_alg_vars *algVars,
				   t_steps_info *minInfo)
{
	t_stack_elem	*ptr;
	int	i;

	i = 0;
	ptr = stackB->head;
	while (i < stackB->size)
	{
		best_direction(minInfo, ptr, algVars, stackA, stackB);
		i++;
		ptr = ptr->next;
	}
}

void move_b(t_stack *stackA, t_stack *stackB, t_steps_info *minInfo,
			   t_command_list *list)
{
	while (minInfo->elemA != stackA->head || minInfo->elemB != stackB->head)
	{
		if (minInfo->directionA == minInfo->directionB
		&& minInfo->elemA != stackA->head
		&& minInfo->elemB != stackB->head)
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

void	sortToStackA(t_stack *stackA, t_stack *stackB, t_alg_vars *algVars,
					 t_command_list *list)
{
	t_steps_info	*minInfo;

	minInfo = init_struct_info();
	while(stackB->size)
	{
		//find best scenario and send to b
		minInfo->isSet = false;
		calc_steps(stackA, stackB, algVars, minInfo);
		move_b(stackA, stackB, minInfo, list);
		pn(stackA, stackB, "pa", list);
	}
	free(minInfo);
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
	sendToStackB(stackA, stackB, algVars, list);
	sortToStackA(stackA, stackB, algVars, list);
	ptr = stackA->head;
	steps = 0;
	while (ptr->order != 1)
	{
		steps++;
		ptr = ptr->next;
	}
	if (steps < algVars->mid)
		while (stackA->head->order != 1)
			rn(stackA, "ra", list);
	else
		while (stackA->head->order != 1)
			rrn(stackA, "rra", list);
}