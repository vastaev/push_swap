#include "push_swap.h"

void	*error_msg(void)
{
	write(2, "Error\n", 6);
	exit(-1);
}
