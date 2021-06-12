#include "push_swap.h"
#include "libft.h"

#include <stdio.h>
int	main(int argc, char **argv)
{
	t_stack			*stackA;
	t_stack_elem	*ptr;
	t_command_list *list;
	t_command 		*comand;

	if (argc < 2)
		exit(0);
	stackA = validation_of_args(argc, argv);

	ptr = stackA->head;
	while (ptr)
	{
		printf("%d ", ptr->value);
		printf("%d\n", ptr->order);
		ptr = ptr->next;
	}

	list = malloc(sizeof(t_command_list));
	list->head = NULL;
	list->size = 0;

	sn(stackA, "sa", list);
	print_commands(list);
	ptr = stackA->head;
	while (ptr)
	{
		printf("%d ", ptr->value);
		printf("%d\n", ptr->order);
		ptr = ptr->next;
	}

//	rn(stackA, "ra", list);
//	print_commands(list);
//	ptr = stackA->head;
//	while (ptr)
//	{
//		printf("%d ", ptr->value);
//		printf("%d\n", ptr->order);
//		ptr = ptr->next;
//	}

	return (0);
}
