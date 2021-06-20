#include "push_swap.h"

t_stack_elem	*pop(t_stack *stack)
{
	t_stack_elem	*elem;

	elem = NULL;
	if (stack && stack->size)
	{
		if (stack->size == 1)
		{
			elem = stack->head;
			stack->head = NULL;
			stack->tail = NULL;
			elem->next = NULL;
			elem->previous = NULL;
		}
		else
		{
			elem = stack->head;
			stack->head = stack->head->next;
			stack->head->previous = NULL;
			elem->next = NULL;
			elem->previous = NULL;
		}
		stack->size--;
	}
	return (elem);
}

void	push(t_stack *stack, t_stack_elem *elem)
{
	if (stack && elem)
	{
		if (!stack->head)
		{
			stack->head = elem;
			stack->tail = elem;
			stack->head->next = NULL;
			stack->head->previous = NULL;
		}
		else
		{
			stack->head->previous = elem;
			elem->next = stack->head;
			stack->head = elem;
			stack->head->previous = NULL;
		}
		stack->size++;
	}
}

void pn(t_stack *to, t_stack *from, const char *name, t_command_list *list)
{
	push(to, pop(from));
	if (name && !list)
		ft_putstrnewline(name);
	if (name && list)
		add_command_to_list(list, create_command(name));
}
