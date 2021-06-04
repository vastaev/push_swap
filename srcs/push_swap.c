#include "push_swap.h"
#include "libft.h"

#include <stdio.h>
int	main(int argc, char **argv)
{
	t_stack			*stackA;
	t_stack_elem	*ptr;

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
	printf("%d", stackA->size);
	return (0);
}
