#include "push_swap.h"
#include "libft.h"

#include <stdio.h>
int	main(int argc, char **argv)
{
	t_stack			*stackA;
	t_stack			*stackB;
	t_command_list *list;
	t_alg_vars		*algVars;

	if (argc < 2)
		exit(0);
	stackA = validation_of_args(argc, argv);

	list = malloc(sizeof(t_command_list));
	list->head = NULL;
	list->size = 0;

	stackB = malloc(sizeof(t_stack));
	stackB->head = NULL;
	stackB->tail = NULL;
	stackB->size = 0;

	algVars = (t_alg_vars *)malloc(sizeof(t_alg_vars));
	algVars->max = 0;
	algVars->mid = 0;
	solve(stackA, stackB, list, algVars);
	free_stack(stackA);
	free_stack(stackB);
	//printf("\n\n");
	print_commands(list);
	free_commands(list);
	free(algVars);
	return (0);
}
