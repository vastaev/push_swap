#include "push_swap.h"

void	swap_two_elems(t_stack_elem *first,
					t_stack_elem *second,
					t_stack *stack)
{
	t_stack_elem	*next;
	t_stack_elem	*previous;

	next = second->next;
	previous = first->previous;
	first->next = next;
	first->previous = second;
	next->previous = first;
	second->previous = previous;
	second->next = first;
	previous->next = second;
	stack->head = second;
}

void	sn(t_stack *stack,
		   const char *name,
		   t_command_list *list)
{
	if (stack && stack->head && stack->size >= 2)
		swap_two_elems(stack->head, stack->head->next, stack);
	if (name && !list)
		ft_putstrnewline(name);
	if (name && list)
		add_command_to_list(list, create_command(name));
}
