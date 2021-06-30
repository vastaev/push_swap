#include "push_swap.h"

void	rrn(t_stack *stack, const char *name, t_command_list *list)
{
	if (stack && stack->head && stack->size >= 2)
	{
		stack->head->previous = stack->tail;
		stack->tail->next = stack->head;
		stack->tail = stack->tail->previous;
		stack->head = stack->head->previous;
		stack->head->previous = NULL;
		stack->tail->next = stack->head;
		stack->head->previous = stack->tail;
	}
	if (name && !list)
		ft_putstrnewline(name);
	if (name && list)
		add_command_to_list(list, create_command(name));
}

void	rrr(t_stack *stackA, t_stack *stackB, const char *name, t_command_list
*list)
{
	rrn(stackA, NULL, NULL);
	rrn(stackB, NULL, NULL);
	if (name && !list)
		ft_putstrnewline(name);
	if (name && list)
		add_command_to_list(list, create_command(name));
}