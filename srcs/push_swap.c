#include "push_swap.h"
#include "libft.h"

#include <stdio.h>
int	main(int argc, char **argv)
{
	t_stack			*stackA;
	t_stack			*stackB;
	t_stack_elem	*ptr;
	t_command_list *list;
	t_command 		*comand;
	t_alg_vars		*algVars;

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
	printf("%d\n", stackA->size);
	list = malloc(sizeof(t_command_list));
	list->head = NULL;
	list->size = 0;

	stackB = malloc(sizeof(t_stack));
	stackB->head = NULL;
	stackB->tail = NULL;
	stackB->size = 0;

//	sn(stackA, "sa", list);
//	print_commands(list);
//	ptr = stackA->head;
//	while (ptr)
//	{
//		printf("%d ", ptr->value);
//		printf("%d\n", ptr->order);
//		ptr = ptr->next;
//	}

//	rn(stackA, "ra", list);
//	print_commands(list);
//	ptr = stackA->head;
//	while (ptr)
//	{
//		printf("%d ", ptr->value);
//		printf("%d\n", ptr->order);
//		ptr = ptr->next;
//	}

//	rrn(stackA, "ra", list);
//	print_commands(list);
//	ptr = stackA->head;
//	while (ptr)
//	{
//		printf("%d ", ptr->value);
//		printf("%d\n", ptr->order);
//		ptr = ptr->next;
//	}


//	pn(stackB, stackA, "pb", list);
//	print_commands(list);
//	ptr = stackB->head;
//	while (ptr)
//	{
//		printf("%d ", ptr->value);
//		printf("%d\n", ptr->order);
//		ptr = ptr->next;
//	}
//	pn(stackB, stackA, "pb", list);
//	print_commands(list);
//	ptr = stackB->head;
//	while (ptr)
//	{
//		printf("%d ", ptr->value);
//		printf("%d\n", ptr->order);
//		ptr = ptr->next;
//	}
//	pn(stackB, stackA, "pb", list);
//	print_commands(list);
//	ptr = stackB->head;
//	while (ptr)
//	{
//		printf("%d ", ptr->value);
//		printf("%d\n", ptr->order);
//		ptr = ptr->next;
//	}
//
//	printf("\n\n");
//
//	ptr = stackA->head;
//	while (ptr)
//	{
//		printf("%d ", ptr->value);
//		printf("%d\n", ptr->order);
//		ptr = ptr->next;
//	}
//	printf("\n");
//	pn(stackA, stackB, "pa", list);
//	ptr = stackA->head;
//	while (ptr)
//	{
//		printf("%d ", ptr->value);
//		printf("%d\n", ptr->order);
//		ptr = ptr->next;
//	}
	algVars = (t_alg_vars *)malloc(sizeof(t_alg_vars));
	algVars->next_to_sort = 0;
	algVars->max = 0;
	algVars->mid = 0;
	solve(stackA, stackB, list, algVars);
	return (0);
}
