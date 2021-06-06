#include "push_swap.h"

t_command	*create_command(const char *name)
{
	t_command	*command;

	command = (t_command *)malloc(sizeof(t_command));
	if (command == NULL)
		return (error_msg());
	command->name = ft_strdup(name);
	if (command->name == NULL)
		return (error_msg());
	command->next = NULL;
	return (command);
}

void	add_command_to_list(t_command_list *list, t_command *command)
{
	t_command	*last;

	if (!list->head)
		list->head = command;
	else
	{
		last = list->head;
		last = find_last_command(last);
		last->next = command;
	}
	list->size++;
}

void	print_commands(t_command_list *list)
{
	t_command	*ptr;

	ptr = list->head;
	while (ptr)
	{
		ft_putstrnewline(ptr->name);
		ptr = ptr->next;
	}
}
