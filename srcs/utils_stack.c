#include "push_swap.h"

t_stack_elem	*create_new_element(int value)
{
	t_stack_elem	*newElement;

	newElement = (t_stack_elem *)malloc(sizeof(t_stack_elem));
	if (!newElement)
		error_msg();
	newElement->value = value;
	newElement->next = NULL;
	newElement->previous = NULL;
	newElement->order = -1;
	return (newElement);
}

void	add_to_stack(t_stack *stack, t_stack_elem *elem)
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
			elem->previous = stack->tail;
			stack->tail->next = elem;
			stack->tail = elem;
			stack->tail->next = stack->head;
			stack->head->previous = stack->tail;
		}
		stack->size++;
	}
}
