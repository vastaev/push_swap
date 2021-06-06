#include "push_swap.h"

t_stack_elem	*create_new_element(int value)
{
	t_stack_elem	*newElement;

	newElement = (t_stack_elem *)malloc(sizeof(t_stack_elem));
	if (!newElement)
		error_msg();
	newElement->value = value;
	newElement->next = NULL;
	newElement->order = -1;
	return (newElement);
}

t_stack_elem	*find_last_in_list(t_stack_elem *elem)
{
	t_stack_elem	*ptr;

	if (elem == NULL)
		return (0);
	ptr = elem;
	while (ptr->next != NULL)
		ptr = ptr->next;
	return (ptr);
}

t_command	*find_last_command(t_command *elem)
{
	t_command	*ptr;

	if (elem == NULL)
		return (0);
	ptr = elem;
	while (ptr->next != NULL)
		ptr = ptr->next;
	return (ptr);
}

void	add_to_end_of_stack(t_stack *stack, t_stack_elem *elem)
{
	t_stack_elem	*ptr;

	ptr = find_last_in_list(stack->head);
	if (stack->head == NULL)
		stack->head = elem;
	else
		ptr->next = elem;
}
