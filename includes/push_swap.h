#ifndef PUSH_SWAP_PUSH_SWAP_H
#define PUSH_SWAP_PUSH_SWAP_H

#include <unistd.h>

typedef struct s_listp
{
	int				value;
	int				order;
	int				flag;
	struct s_list	*next;
	struct s_list	*prev;

}				 t_listp;

int		validation_of_args(int argc, char **argv);

#endif //PUSH_SWAP_PUSH_SWAP_H
