#include "push_swap.h"

static void	sort_three_nums(t_stack *stackA, t_command_list *list)
{
	t_stack_elem	*max;
	int				maxNum;
	int				i;

	i = 0;
	max = stackA->head;
	maxNum = max->order;
	while (i < stackA->size)
	{
		if (maxNum < max->order)
			maxNum = max->order;
		max = max->next;
		i++;
	}
	if (stackA->head->order == maxNum)
		rn(stackA, "ra", list);
	if (stackA->head->next->order == maxNum)
		rrn(stackA, "rra", list);
	if (stackA->head->order > stackA->head->next->order)
		sn(stackA, "sa", list);
}

static void	sort_four_nums(t_stack *stackA, t_stack *stackB,
							  t_command_list *list)
{
	while (stackB->size < 1)
	{
		if (stackA->head->order == 1)
			pn(stackB, stackA, "pb", list);
		else
			rn(stackA, "ra", list);
	}
	sort_three_nums(stackA, list);
	pn(stackA, stackB, "pa", list);
}

static void	sort_five_nums(t_stack *stackA, t_stack *stackB,
							  t_command_list *list)
{
	while (stackB->size < 2)
	{
		if (stackA->head->order == 1 || stackA->head->order == 2)
			pn(stackB, stackA, "pb", list);
		else
			rn(stackA, "ra", list);
	}
	if (stackB->head->order < stackB->head->next->order)
		sn(stackB, "sb", list);
	sort_three_nums(stackA, list);
	pn(stackA, stackB, "pa", list);
	pn(stackA, stackB, "pa", list);
}

void	small_sort(t_stack *stackA, t_stack *stackB, t_command_list *list)
{
	if (stackA->size == 2 && stackA->head->order > stackA->head->next->order)
		sn(stackA, "sa", list);
	else if (stackA->size == 3)
		sort_three_nums(stackA, list);
	else if (stackA->size == 4)
		sort_four_nums(stackA, stackB, list);
	else if (stackA->size == 5)
		sort_five_nums(stackA, stackB, list);
}
