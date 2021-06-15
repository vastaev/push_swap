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
		stack->tail->next = NULL;
	}
	if (name && !list)
		ft_putstrnewline(name);
	if (name && list)
		add_command_to_list(list, create_command(name));
}