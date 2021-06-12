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
	}
	if (name && !list)
		ft_putstrnewline(name);
	if (name && list)
		add_command_to_list(list, create_command(name));
}
