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
	t_command	*ptr;

	if (list && command)
	{
		if (list->head == NULL)
			list->head = command;
		else
		{
			ptr = list->head;
			while (ptr->next)
				ptr = ptr->next;
			ptr->next = command;
		}
		list->size++;
	}
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
