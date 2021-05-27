#include "../includes/push_swap.h"

#include <stdio.h>
int main(int argc, char **argv)
{
	if (validation_of_args(argc, argv) == -1)
		return (-1);
	printf("%d", argc);
	return 0;
}
