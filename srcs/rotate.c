#include "push_swap.h"

void	rn(t_stack *stack, const char *name, t_command_list *list)
{
	if (stack && stack->head && stack->size >= 2)
	{
		stack->tail->next = stack->head;
		stack->head->previous = stack->tail;
		stack->head = stack->head->next;
		stack->head->previous = NULL;
		stack->tail->next->next = NULL;
		stack->tail = stack->tail->next;
		stack->tail->next = stack->head;
		stack->head->previous = stack->tail;
	}
	if (name && !list)
		ft_putstrnewline(name);
	if (name && list)
		add_command_to_list(list, create_command(name));
}

void	rr(t_stack *stackA, t_stack *stackB, const char *name, t_command_list
*list)
{
	rn(stackA, NULL, NULL);
	rn(stackB, NULL, NULL);
	if (name && !list)
		ft_putstrnewline(name);
	if (name && list)
		add_command_to_list(list, create_command(name));
}