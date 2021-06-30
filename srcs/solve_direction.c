#include "push_swap.h"

static t_stack_elem	*find_elem_a(t_stack *stackA, int order)
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

static void	count_steps(t_stack *stack, int order, int *rn_size, int *rrn_size)
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

static void	set_best_direction(int steps, t_steps_info newInfo, t_steps_info
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

static void	best_direction(t_steps_info *minInfo, t_stack_elem *elemB,
						    t_stack *stackA, t_stack *stackB)
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
	newInfo.elemA = find_elem_a(stackA, elemB->order);
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
	int				i;

	i = 0;
	ptr = stackB->head;
	while (i < stackB->size)
	{
		best_direction(minInfo, ptr, stackA, stackB);
		i++;
		ptr = ptr->next;
	}
}
