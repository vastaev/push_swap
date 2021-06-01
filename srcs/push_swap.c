#include "push_swap.h"
#include "libft.h"

#include <stdio.h>
int main(int argc, char **argv)
{
	int		*sortedArray;

	if (argc < 2)
		exit(0);
	sortedArray = validation_of_args(argc, argv);
	for (int i = 0; i< argc - 1; i++)
		printf("%d ", sortedArray[i]);
	printf("%d", 0);
	return 0;
}
