#include "push_swap.h"
#include "libft.h"

#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack			*stackA;
	t_stack			*stackB;
	t_command_list	*list;

	if (argc < 2)
		exit(0);
	stackA = (t_stack *)malloc(sizeof(t_stack));
	if (stackA == NULL)
		error_msg();
	stackA = validation_of_args(argc, argv, stackA);
	list = (t_command_list *)malloc(sizeof(t_command_list));
	list->head = NULL;
	list->size = 0;
	stackB = (t_stack *)malloc(sizeof(t_stack));
	stackB->head = NULL;
	stackB->tail = NULL;
	stackB->size = 0;
	if (stackA->size < 6)
		small_sort(stackA, stackB, list);
	else
		solve(stackA, stackB, list);
	print_commands(list);
	free_commands(list);
	free_stack(stackA);
	free_stack(stackB);
}
