#include "push_swap.h"

void	sn(t_stack *stack,
			const char *name,
			t_command_list *list)
{
	if (stack && stack->head && stack->size >= 2)
	{
		stack->head->next->next->previous = stack->head;
		stack->head = stack->head->next;
		stack->head->previous = NULL;
		stack->head->next->previous->next = stack->head->next;
		stack->head->next = stack->head->next->previous;
		stack->head->next->previous = stack->head;
	}
	if (name && !list)
		ft_putstrnewline(name);
	if (name && list)
		add_command_to_list(list, create_command(name));
}

void	ss(t_stack *a,
			t_stack *b,
			const char *name,
			t_command_list *list)
{
	sn(a, NULL, NULL);
	sn(b, NULL, NULL);
	if (name && !list)
		ft_putstrnewline(name);
	if (name && list)
		add_command_to_list(list, create_command(name));
}
