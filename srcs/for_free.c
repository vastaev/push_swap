#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	size_t			i;
	t_stack_elem	*ptr;
	t_stack_elem	*tmp;

	i = 0;
	ptr = stack->head;
	while (i < stack->size)
	{
		tmp = ptr;
		ptr = ptr->next;
		free(tmp);
		i++;
	}
	free(stack);
}

void	free_commands(t_command_list *list)
{
	t_command	*ptr;
	t_command	*tmp;

	ptr = list->head;
	while (ptr)
	{
		tmp = ptr;
		ptr = ptr->next;
		free(tmp->name);
		free(tmp);
	}
	free(list);
}